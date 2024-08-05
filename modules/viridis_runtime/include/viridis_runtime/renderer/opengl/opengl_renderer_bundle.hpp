#pragma once

#include "opengl_renderer.hpp"
#include "viridis_runtime/renderer/renderer_bundle.hpp"
#include "viridis_core/util/dynlib.hpp"

#include "SDL3/SDL.h"

namespace viridis {

class Application;

class VIRIDIS_API OpenglRendererBundle : public RendererBundle {
public:
    OpenglRendererBundle() = default;

    OpenglRendererBundle& with_version(uint32_t new_major_version, uint32_t new_minor_version) {
        major_version = new_major_version;
        minor_version = new_minor_version;

        return *this;
    }

    void set_attributes() const override;
    [[nodiscard]] SDL_WindowFlags get_window_flags() const override;

    [[nodiscard]] std::unique_ptr<Renderer> create_renderer(SDL_Window& window) override;

private:
    uint32_t major_version = 3;
    uint32_t minor_version = 2;
};

}
