cmake_minimum_required(VERSION 3.28)

project(viridis_runtime)

add_library(viridis_runtime SHARED
    "src/viridis_runtime.cpp"
)

target_include_directories(viridis_runtime PUBLIC include)
target_include_directories(viridis_runtime PRIVATE include/viridis_runtime)

target_link_libraries(viridis_runtime PUBLIC viridis_core)
target_link_libraries(viridis_runtime PUBLIC SDL3::SDL3)
