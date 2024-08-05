#include "renderer/opengl/opengl_renderer_bundle.hpp"
#include "renderer/renderer.hpp"
#include "app/application.hpp"

#include "spdlog/spdlog.h"
#include "GL/glew.h"

using namespace viridis;

void OpenglRendererBundle::set_attributes() const {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major_version);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor_version);
}

SDL_WindowFlags OpenglRendererBundle::get_window_flags() const {
    return SDL_WINDOW_OPENGL;
}

std::unique_ptr<Renderer> OpenglRendererBundle::create_renderer(SDL_Window& window) {
    const auto ctx = SDL_GL_CreateContext(&window);
    if (!ctx) {
        spdlog::error("Couldn't create OpenGL context: {}", SDL_GetError());

        return {};
    }

    glewExperimental = true;
    if (GLuint result = glewInit(); result != GLEW_OK) {
        spdlog::error("Couldn't initialize GLEW: {}", reinterpret_cast<const char*>(glewGetErrorString(result)));

        return {};
    }

    return std::unique_ptr<Renderer> { new OpenglRenderer { ctx } };
}
