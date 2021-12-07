#include <SDL2/SDL.h>
#include <SdlWrap/GraphicsContext.hpp>
#include <SdlWrap/Renderer.hpp>
#include <SdlWrap/TtfContext.hpp>
#include <SdlWrap/TtfFont.hpp>
#include <SdlWrap/Window.hpp>

int main()
{
	sdl::GraphicsContext context{SDL_INIT_VIDEO};
	sdl::TtfContext ttf = context.initTtf();
	sdl::TtfFont font = ttf.openFont("res/fonts/Hack.ttf", 20);
	sdl::Window window = context.createWindow("Teditor", 800, 600, SDL_WINDOW_RESIZABLE);
	sdl::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool run = true;
	while (run)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				run = false;
				break;
			default:
				break;
			}
		}

		renderer.setDrawColor(SDL_Color{100, 0, 0, 255});
		renderer.clear();
		renderer.present();
	}
	return 0;
}
