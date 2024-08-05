#pragma once

#include "viridis_core/util/dynlib.hpp"

#include <memory>

#include "SDL3/SDL.h"

namespace viridis {

class Renderer;

class VIRIDIS_API RendererBundle {
public:
    virtual ~RendererBundle() = default;

    virtual void set_attributes() const = 0;
    [[nodiscard]] virtual SDL_WindowFlags get_window_flags() const = 0;

    [[nodiscard]] virtual std::unique_ptr<Renderer> create_renderer(SDL_Window& window) = 0;
};

}
