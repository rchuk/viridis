cmake_minimum_required(VERSION 3.28)
project(example_00_test)

add_executable(example_00_test
    "src/main.cpp"
)

target_link_libraries(example_00_test PRIVATE viridis_runtime)
