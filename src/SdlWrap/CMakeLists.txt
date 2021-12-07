add_library(
	"SdlWrap"
	"GraphicsContext.cpp"
	"Window.cpp"
	Renderer.cpp
)
target_link_libraries("SdlWrap" PUBLIC "SDL2")
if(WIN32)
	target_link_libraries("SdlWrap" PUBLIC "SDL2main")
endif()
target_compile_features("SdlWrap" PUBLIC "cxx_std_20")
target_include_directories("SdlWrap" PUBLIC "${PROJECT_SOURCE_DIR}/inc")
