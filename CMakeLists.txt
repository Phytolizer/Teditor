cmake_minimum_required(VERSION 3.8)

project(
    Teditor
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "A text editor."
    HOMEPAGE_URL "https://github.com/Phytolizer/Teditor"
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
include(DeclareModule)

declare_module(
    "Teditor"
    KIND executable
    SOURCES "Main.cpp"
)
