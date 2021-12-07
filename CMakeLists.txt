cmake_minimum_required(VERSION 3.12...3.22)
project(
	"Teditor"
	LANGUAGES "CXX"
	VERSION "0.1.0"
	DESCRIPTION "Text Editor"
	HOMEPAGE_URL "https://github.com/Phytolizer/Teditor"
)

find_package("SDL2" REQUIRED)

add_library(
		"SdlWrap"
		"inc/SdlWrap/GraphicsContext.hpp"
		"inc/SdlWrap/Renderer.hpp"
		"inc/SdlWrap/TtfContext.hpp"
		"inc/SdlWrap/Window.hpp"
		"src/SdlWrap/GraphicsContext.cpp"
		"src/SdlWrap/Renderer.cpp"
		"src/SdlWrap/TtfContext.cpp"
		"src/SdlWrap/Window.cpp"
		inc/SdlWrap/TtfFont.hpp src/SdlWrap/TtfFont.cpp)
target_include_directories("SdlWrap" PUBLIC "inc")
target_link_libraries("SdlWrap" PUBLIC "SDL2" "SDL2_ttf")

add_executable("Teditor" "src/Teditor/Main.cpp")
target_compile_features("Teditor" PRIVATE "cxx_std_20")
target_link_libraries("Teditor" PRIVATE "SdlWrap")
