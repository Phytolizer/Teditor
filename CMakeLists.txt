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
	"inc/SdlWrap/TtfFont.hpp"
	"inc/SdlWrap/Window.hpp"
	"src/SdlWrap/GraphicsContext.cpp"
	"src/SdlWrap/Renderer.cpp"
	"src/SdlWrap/TtfContext.cpp"
	"src/SdlWrap/TtfFont.cpp"
	"src/SdlWrap/Window.cpp"
)
target_include_directories("SdlWrap" PUBLIC "inc")
target_link_libraries("SdlWrap" PUBLIC "SDL2" "SDL2_ttf")

add_custom_target(
		"copy_assets"
		DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/res"
		COMMAND  "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/res" "${CMAKE_CURRENT_BINARY_DIR}/res"
)

add_executable("Teditor" "src/Teditor/Main.cpp")
target_compile_features("Teditor" PRIVATE "cxx_std_20")
target_link_libraries("Teditor" PRIVATE "SdlWrap")
add_dependencies("Teditor" "copy_assets")
