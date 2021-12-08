#include "Teditor.hpp"
#include <SDL2/SDL.h>
#include <SdlWrap/GraphicsContext.hpp>
#include <SdlWrap/Renderer.hpp>
#include <SdlWrap/TtfContext.hpp>
#include <SdlWrap/TtfFont.hpp>
#include <SdlWrap/Window.hpp>
#include <iostream>

int main()
{
	sdl::GraphicsContext context{SDL_INIT_VIDEO};
	sdl::Window window = context.createWindow("Teditor", 800, 600, SDL_WINDOW_RESIZABLE);
	sdl::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	sdl::FcFont font = renderer.loadFont("res/fonts/Hack.ttf", 16, {255, 255, 255, 255}, TTF_STYLE_NORMAL);

	Teditor teditor;

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
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_BACKSPACE:
					teditor.backspace();
					break;
				default:
					break;
				}
				break;
			case SDL_TEXTINPUT:
				teditor.writeText(event.text.text);
				break;
			default:
				break;
			}
		}

		renderer.setDrawColor(SDL_Color{25, 25, 25, 255});
		renderer.clear();
		teditor.renderText(font);
		renderer.present();
	}

	return 0;
}
