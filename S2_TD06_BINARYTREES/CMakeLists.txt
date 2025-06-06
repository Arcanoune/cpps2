cmake_minimum_required(VERSION 3.24)

project(BinaryTree_Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(binary_tree
    src/main.cpp
    src/node.cpp
)

target_include_directories(binary_tree PUBLIC src/)
