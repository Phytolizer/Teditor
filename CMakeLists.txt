cmake_minimum_required(VERSION 3.8)

project(
    Teditor
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "A text editor."
    HOMEPAGE_URL "https://github.com/Phytolizer/Teditor"
)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
include(DeclareModule)

find_package(sdl2 CONFIG REQUIRED)

declare_module(
    "SdlWrapper"
    KIND library
    SOURCES "Context.cpp"
            "Error.cpp"
            "VideoContext.cpp"
            "Window.cpp"
    DEPENDS SDL2::SDL2
)
declare_module(
    "Teditor"
    KIND executable
    SOURCES "Main.cpp"
    DEPENDS SDL2::SDL2 SDL2::SDL2main "SdlWrapper"
)
