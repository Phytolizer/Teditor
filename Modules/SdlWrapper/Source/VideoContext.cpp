#include "SdlWrapper/VideoContext.hpp"

#include "SdlWrapper/Error.hpp"
#include "SdlWrapper/Window.hpp"

#include <SDL2/SDL.h>

SdlWrapper::VideoContext::VideoContext(const Context* parent) : _isActive{true}
{
    if (const int code = SDL_InitSubSystem(SDL_INIT_VIDEO); code != 0)
    {
        throw Error::FailureCode("SDL_InitSubSystem", code);
    }
}

SdlWrapper::VideoContext::~VideoContext()
{
    if (_isActive)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

SdlWrapper::VideoContext::VideoContext(VideoContext&& other) noexcept : _isActive{other._isActive}
{
    other._isActive = false;
}

SdlWrapper::VideoContext& SdlWrapper::VideoContext::operator=(VideoContext&& other) noexcept
{
    if (&other != this)
    {
        if (_isActive)
        {
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
        }

        _isActive = other._isActive;
        other._isActive = false;
    }

    return *this;
}

SdlWrapper::Window SdlWrapper::VideoContext::CreateWindow(
    const std::string& title, const int x, const int y, const int w, const int h, const std::uint32_t flags) const
{
    return Window{this, title, x, y, w, h, flags};
}
