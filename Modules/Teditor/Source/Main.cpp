#include <SDL2/SDL.h>
#include <SdlWrapper/Context.hpp>
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
    return 0;
}
