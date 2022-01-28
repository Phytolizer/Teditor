cmake_minimum_required(VERSION 3.12...3.22)

project(
	"SDL_FontCache"
	LANGUAGES "C"
	VERSION "0.1.0"
	DESCRIPTION "Font caching library for SDL2"
	HOMEPAGE_URL "https://github.com/grimfang4/SDL_FontCache"
)

find_package(SDL2 REQUIRED)

add_library("SDL_FontCache" "inc/SDL_FontCache.h" "src/SDL_FontCache.c")
target_include_directories("SDL_FontCache" PUBLIC "inc")
target_link_libraries("SDL_FontCache" PUBLIC "SDL2::SDL2" "SDL2::SDL2_ttf")
