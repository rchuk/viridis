#pragma once

#include "application.hpp"
#include "window_kind.hpp"
#include "viridis_core/util/dynlib.hpp"

#include <cstdint>
#include <utility>
#include <optional>
#include <memory>
#include <concepts>

#include "glm/glm.hpp"

namespace viridis {

class RendererBundle;

class ApplicationBuilder {
public:
    template<class T>
    explicit VIRIDIS_API ApplicationBuilder(T renderer_bundle) requires std::derived_from<T, RendererBundle>
        : renderer_bundle(std::make_unique<T>(std::move(renderer_bundle))) {}
    explicit VIRIDIS_API ApplicationBuilder(std::unique_ptr<RendererBundle> renderer_bundle);

    VIRIDIS_API ~ApplicationBuilder();

    VIRIDIS_API ApplicationBuilder& with_title(std::string new_title) {
        title = std::move(new_title);

        return *this;
    }

    VIRIDIS_API ApplicationBuilder& with_window_kind(WindowKind new_window_kind) {
        window_kind = new_window_kind;

        return *this;
    }

    VIRIDIS_API ApplicationBuilder& with_window_size(glm::ivec2 new_window_size) {
        window_size = new_window_size;

        return *this;
    }

    VIRIDIS_API ApplicationBuilder& limit_framerate(uint32_t new_target_framerate) {
        target_framerate = new_target_framerate;

        return *this;
    }

    VIRIDIS_API ApplicationBuilder& no_limit_framerate() {
        target_framerate = {};

        return *this;
    }

    [[nodiscard]] VIRIDIS_API std::optional<Application> build() const;

private:
    std::string title = "My Application";
    WindowKind window_kind = WindowKind::Default;
    glm::ivec2 window_size = { 800, 480 };
    std::optional<uint32_t> target_framerate = std::nullopt;

    std::unique_ptr<RendererBundle> renderer_bundle;

    [[nodiscard]] SDL_WindowFlags get_window_flags() const;
};

}
