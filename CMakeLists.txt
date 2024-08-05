cmake_minimum_required(VERSION 3.28)
project(viridis)

option(VIRIDIS_ENABLE_EXAMPLES "Enable examples" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

#
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#

add_subdirectory(externals)

if (MSVC)
    add_compile_options(/Wall)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG=1)
else()
    add_compile_definitions(DEBUG=0)
endif()

add_subdirectory(modules)

if (VIRIDIS_ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif ()
