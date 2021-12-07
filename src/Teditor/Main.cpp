#include <SDL2/SDL.h>
#include <SdlWrap/GraphicsContext.hpp>
#include <SdlWrap/Renderer.hpp>
#include <SdlWrap/TtfContext.hpp>
#include <SdlWrap/TtfFont.hpp>
#include <SdlWrap/Window.hpp>
#include <rope.h>

int main()
{
	sdl::GraphicsContext context{SDL_INIT_VIDEO};
	sdl::Window window = context.createWindow("Teditor", 800, 600, SDL_WINDOW_RESIZABLE);
	sdl::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	sdl::FcFont font = renderer.loadFont("res/fonts/Hack.ttf", 16, {255, 255, 255, 255}, TTF_STYLE_NORMAL);

	rope* myRope = rope_new();
	rope_insert(myRope, 0, reinterpret_cast<const uint8_t*>("Hello, world!"));
	rope_insert(myRope, sizeof("Hello,"), reinterpret_cast<const uint8_t*>("ropy "));

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

		renderer.setDrawColor(SDL_Color{25, 25, 25, 255});
		renderer.clear();
		uint8_t* myText = rope_create_cstr(myRope);
		font.draw(0, 0, reinterpret_cast<const char*>(myText));
		free(myText);
		renderer.present();
	}

	rope_free(myRope);
	return 0;
}
