cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Huffman VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optimization
set(CMAKE_CXX_FLAGS "-Os -s")

# Include directories
include_directories(include)

# Source files
add_executable(huffman src/main.cc src/node.cc src/node_comparator.cc src/huffman_tree.cc)