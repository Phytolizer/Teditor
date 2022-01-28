#include "SdlWrapper/Context.hpp"

#include "SdlWrapper/Error.hpp"
#include "SdlWrapper/VideoContext.hpp"

#include <SDL2/SDL.h>

SdlWrapper::Context::Context() : _isActive{true}
{
    if (const int code = SDL_Init(0); code != 0)
    {
        throw Error::FailureCode("SDL_Init", code);
    }
}

SdlWrapper::Context::~Context()
{
    if (_isActive)
    {
        SDL_Quit();
    }
}

SdlWrapper::Context::Context(Context&& other) noexcept : _isActive(other._isActive)
{
    other._isActive = false;
}

SdlWrapper::Context& SdlWrapper::Context::operator=(Context&& other) noexcept
{
    if (&other != this)
    {
        if (_isActive)
        {
            SDL_Quit();
        }

        _isActive = other._isActive;
        other._isActive = false;
    }

    return *this;
}

bool SdlWrapper::Context::PollEvent(SDL_Event* event) const
{
    (void)this;
    return SDL_PollEvent(event);
}

SdlWrapper::VideoContext SdlWrapper::Context::Video() const
{
    return VideoContext{this};
}
