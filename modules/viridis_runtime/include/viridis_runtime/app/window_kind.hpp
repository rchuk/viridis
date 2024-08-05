#pragma once

#include <cstdint>

namespace viridis {

enum class WindowKind : uint8_t {
    Default = 0,
    Fullscreen,
    Resizable
};

}
