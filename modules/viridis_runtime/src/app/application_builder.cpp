#include "app/application_builder.hpp"
#include "renderer/renderer_bundle.hpp"
#include "renderer/renderer.hpp"

#include "spdlog/spdlog.h"

using namespace viridis;

ApplicationBuilder::ApplicationBuilder(std::unique_ptr<RendererBundle> renderer_bundle)
    : renderer_bundle(std::move(renderer_bundle))
{

}

ApplicationBuilder::~ApplicationBuilder() = default;

std::optional<Application> ApplicationBuilder::build() const {
    spdlog::trace("Performing app initialization");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        spdlog::error("Couldn't initialize SDL: {}", SDL_GetError());

        return {};
    }

    renderer_bundle->set_attributes();

    const auto window = SDL_CreateWindow(
        title.c_str(),
        window_size.x, window_size.y,
        get_window_flags() | renderer_bundle->get_window_flags()
    );
    if (!window) {
        spdlog::error("Couldn't create window: {}", SDL_GetError());

        return {};
    }

    auto renderer = renderer_bundle->create_renderer(*window);
    if (!renderer) {
        spdlog::error("Couldn't initialize renderer");

        return {};
    }

    Application application { window, target_framerate, std::move(renderer) };

    return { std::move(application) };
}

SDL_WindowFlags ApplicationBuilder::get_window_flags() const {
    switch (window_kind) {
        case WindowKind::Resizable:
            return SDL_WINDOW_RESIZABLE;
        case WindowKind::Fullscreen:
            return SDL_WINDOW_FULLSCREEN;
        case WindowKind::Default:
            [[fallthrough]];
        default:
            return 0;
    }
}
