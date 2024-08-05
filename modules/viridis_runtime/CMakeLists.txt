cmake_minimum_required(VERSION 3.28)

project(viridis_runtime)

add_library(viridis_runtime SHARED
    "include/viridis_runtime/renderer/opengl/opengl_renderer.hpp"
    "include/viridis_runtime/renderer/opengl/opengl_renderer_bundle.hpp"
    "include/viridis_runtime/renderer/renderer.hpp"
    "include/viridis_runtime/renderer/renderer_bundle.hpp"
    "include/viridis_runtime/app/application.hpp"
    "include/viridis_runtime/app/application_builder.hpp"
    "include/viridis_runtime/app/window_kind.hpp"

    "src/renderer/opengl/opengl_renderer.cpp"
    "src/renderer/opengl/opengl_renderer_bundle.cpp"
    "src/app/application.cpp"
    "src/app/application_builder.cpp"

    "src/viridis_runtime.cpp"
)

target_include_directories(viridis_runtime PUBLIC include)
target_include_directories(viridis_runtime PRIVATE include/viridis_runtime)

target_link_libraries(viridis_runtime PUBLIC viridis_core)
target_link_libraries(viridis_runtime PUBLIC SDL3::SDL3 libglew_shared)
