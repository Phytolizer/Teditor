#include <Config.hpp>
#include <SDL2/SDL.h>
#include <SdlWrapper/Context.hpp>
#include <SdlWrapper/FontCache/Font.hpp>
#include <SdlWrapper/Renderer.hpp>
#include <SdlWrapper/VideoContext.hpp>
#include <SdlWrapper/Window.hpp>

int main(int argc, char** argv)
{
    const SdlWrapper::Context ctx;
    const SdlWrapper::VideoContext video = ctx.Video();
    const SdlWrapper::Window window =
        video.CreateWindow("Text Editor",
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           800,
                           600,
                           SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);
    const SdlWrapper::Renderer renderer =
        window.CreateRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    const SdlWrapper::FontCache::Font font{};
    font.Load(renderer, CMAKE_PROJECT_SOURCE_DIR "/Resources/Fonts/Hack-Regular.ttf", 20, {0xFF, 0xFF, 0xFF, 0xFF}, 0);

    bool quit = false;
    while (!quit)
    {
        SDL_Event e;
        while (ctx.PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
        }

        renderer.SetDrawColor({0x00, 0x00, 0x00, 0xFF});
        renderer.Clear();
        font.Draw(renderer, 0, 0, "test set");
        renderer.Present();
    }
    return 0;
}
