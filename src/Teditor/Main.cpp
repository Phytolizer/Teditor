#include <SDL2/SDL.h>
#include <SdlWrap/GraphicsContext.hpp>
#include <SdlWrap/Renderer.hpp>
#include <SdlWrap/Window.hpp>

int main()
{
	sdl::GraphicsContext context{SDL_INIT_VIDEO};
	sdl::Window window = context.createWindow("Teditor", 800, 600, SDL_WINDOW_RESIZABLE);
	sdl::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return 0;
}
