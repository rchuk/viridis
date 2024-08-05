#pragma once

#include "window_kind.hpp"
#include "viridis_core/util/dynlib.hpp"

#include <string>
#include <optional>
#include <memory>

#include "SDL3/SDL.h"
#include "glm/glm.hpp"

namespace viridis {

class ApplicationBuilder;
class Renderer;

class Application {
    friend ApplicationBuilder;
public:
    VIRIDIS_API ~Application();

    Application(const Application& other) = delete;
    Application& operator=(const Application& other) = delete;

    Application(Application&& other) noexcept;
    Application& operator=(Application&& other) noexcept;

    VIRIDIS_API void run();

    [[nodiscard]] SDL_Window* get_window() const {
        return window;
    }

private:
    SDL_Window* window = nullptr;
    glm::ivec2 window_size = { 0, 0 };
    double target_frametime;

    std::unique_ptr<Renderer> renderer;

    Application(
        SDL_Window* window, std::optional<uint32_t> target_framerate,
        std::unique_ptr<Renderer> renderer
    );

    void loop();

    void on_startup();
    void on_shutdown();
    void on_update(double dt);
    void render();
    void on_event(const SDL_Event& event);
    void on_resize();

    void swap(Application& other) noexcept;
};

}
