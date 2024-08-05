cmake_minimum_required(VERSION 3.28)
project(viridis_externals)

add_subdirectory(SDL)
add_subdirectory(glm)
add_subdirectory(glew)

SET(SPDLOG_USE_STD_FORMAT ON CACHE BOOL "Use std::format instead of fmt library")
SET(SPDLOG_NO_EXCEPTIONS ON CACHE BOOL "Compile with -fno-exceptions. Call abort() on any spdlog exceptions")
add_subdirectory(spdlog)
