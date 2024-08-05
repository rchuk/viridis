#pragma once

#include "viridis_runtime/renderer/renderer.hpp"

#include "SDL3/SDL.h"
#include "glm/glm.hpp"

namespace viridis {

class OpenglRendererBundle;
class Application;

class OpenglRenderer : public Renderer {
    friend OpenglRendererBundle;
public:
    ~OpenglRenderer() override;

    OpenglRenderer(const OpenglRenderer& other) = delete;
    OpenglRenderer& operator=(const OpenglRenderer& other) = delete;

    void render(Application& application) override;
    void on_resize(glm::ivec2 size) override;

private:
    SDL_GLContext ctx;

    explicit OpenglRenderer(SDL_GLContext ctx);
};

}
