cmake_minimum_required(VERSION 3.28)

project(viridis_core)

add_library(viridis_core STATIC
    "src/viridis_core.cpp"
)

target_include_directories(viridis_core PUBLIC include)
target_include_directories(viridis_core PRIVATE include/viridis_core)

target_link_libraries(viridis_core PUBLIC spdlog::spdlog glm)
