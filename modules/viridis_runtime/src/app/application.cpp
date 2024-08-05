#include "app/application.hpp"
#include "renderer/renderer.hpp"

#include <utility>

#include "spdlog/spdlog.h"

using namespace viridis;

Application::Application(
    SDL_Window* window, std::optional<uint32_t> target_framerate,
    std::unique_ptr<Renderer> renderer
)
    : window(window),
    target_frametime(target_framerate.transform([](auto t) { return 1.0 / t; }).value_or(0.0)),
    renderer(std::move(renderer))
{
    if (SDL_GetWindowSizeInPixels(window, &window_size.x, &window_size.y) != 0) {
        spdlog::error("Couldn't get window size: {}", SDL_GetError());
    }
}

Application::Application(viridis::Application&& other) noexcept {
    swap(other);
}

Application& Application::operator=(viridis::Application&& other) noexcept {
    if (this != &other)
        swap(other);

    return *this;
}

Application::~Application() {
    renderer.reset();
    if (window) {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

void Application::run() {
    on_startup();
    loop();
    on_shutdown();
}

void Application::loop() {
    uint64_t perf_count = SDL_GetPerformanceCounter();

    bool is_running = true;
    while (is_running) {
        const uint64_t new_perf_count = SDL_GetPerformanceCounter();
        const uint64_t perf_count_delta = new_perf_count - perf_count;
        const double dt = static_cast<double>(perf_count_delta) / static_cast<double>(SDL_GetPerformanceFrequency());
        perf_count = new_perf_count;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                is_running = false;

                break;
            } else if (event.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) {
                window_size = { event.window.data1, event.window.data2 };
                on_resize();
            } else {
                on_event(event);
            }
        }

        on_update(dt);
        render();

        const double delay = std::max(0.0, target_frametime - dt);
        SDL_DelayNS(static_cast<uint64_t>(delay * 1e9));
    }
}

void Application::on_startup() {
    spdlog::trace("Application startup");

    on_resize();
}

void Application::on_shutdown() {
    spdlog::trace("Application shutdown");
}

void Application::on_update(double dt) {

}

void Application::render() {
    renderer->render(*this);
}

void Application::on_event(const SDL_Event& event) {

}

void Application::on_resize() {
    renderer->on_resize(window_size);
}

void Application::swap(Application& other) noexcept {
    using std::swap;

    swap(window, other.window);
    swap(window_size, other.window_size);
    swap(target_frametime, other.target_frametime);
    swap(renderer, other.renderer);
}
