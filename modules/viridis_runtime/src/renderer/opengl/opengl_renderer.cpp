#include "renderer/opengl/opengl_renderer.hpp"
#include "app/application.hpp"

#include <SDL3/SDL_opengl.h>

using namespace viridis;

OpenglRenderer::OpenglRenderer(SDL_GLContext ctx) : ctx(ctx) {

}

OpenglRenderer::~OpenglRenderer() {
    SDL_GL_DestroyContext(ctx);
}

void OpenglRenderer::render(Application& application) {
    // TODO

    glClearColor(0.0, 0.25f, 0.75f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(application.get_window());
}

void OpenglRenderer::on_resize(glm::ivec2 size) {
    // TODO

    glViewport(0, 0, size.x, size.y);
}
