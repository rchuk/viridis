#pragma once

#include "viridis_core/util/dynlib.hpp"

#include "glm/glm.hpp"

namespace viridis {

class Application;

class VIRIDIS_API Renderer {
public:
    virtual ~Renderer() = default;

    // TODO: Create command buffer
    virtual void render(Application& application) = 0;
    virtual void on_resize(glm::ivec2 size) = 0;
};

}
