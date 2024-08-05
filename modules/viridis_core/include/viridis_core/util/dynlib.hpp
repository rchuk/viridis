#pragma once

#include "SDL3/SDL_platform_defines.h"

#ifdef SDL_PLATFORM_WIN32
#define VIRIDIS_API __declspec(dllexport)
#else
#define VIRIDIS_API
#endif
