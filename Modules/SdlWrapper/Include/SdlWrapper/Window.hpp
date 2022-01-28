#pragma once

#include "SdlWrapper/VideoContext.hpp"

#include <SDL2/SDL_video.h>
#include <string>

namespace SdlWrapper
{

class Window
{
    SDL_Window* _handle;
    const VideoContext* _ctx;

    friend class VideoContext;
    Window(const VideoContext* ctx, const std::string& title, int x, int y, int w, int h, std::uint32_t flags);

  public:
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&& other) noexcept;
    Window& operator=(Window&& other) noexcept;
};

} // namespace SdlWrapper
