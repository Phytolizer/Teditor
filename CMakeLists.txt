cmake_minimum_required(VERSION 3.8)

project(
    Teditor
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "A text editor."
    HOMEPAGE_URL "https://github.com/Phytolizer/Teditor"
)

set(CMAKE_CXX_STANDARD 20)

configure_file("Config.hpp.cin" "${PROJECT_BINARY_DIR}/Include/Config.hpp")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
include(DeclareModule)

find_package(SDL2 CONFIG REQUIRED)

add_subdirectory("ThirdParty/SDL_FontCache")

declare_module(
    "SdlWrapper"
    KIND library
    SOURCES "Context.cpp"
            "Error.cpp"
            "FontCache/Font.cpp"
            "Renderer.cpp"
            "VideoContext.cpp"
            "Window.cpp"
    DEPENDS SDL2::SDL2 FontCache
)
declare_module(
    "Teditor"
    KIND executable
    SOURCES "Main.cpp"
    DEPENDS SDL2::SDL2 SDL2::SDL2main "SdlWrapper"
    INCLUDES "${PROJECT_BINARY_DIR}/Include"
)
if(UNIX)
    target_link_libraries("SdlWrapper" PUBLIC "X11" "Xext")
endif()
