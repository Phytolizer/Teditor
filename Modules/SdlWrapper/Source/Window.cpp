#include "SdlWrapper/Window.hpp"

#include "SdlWrapper/Error.hpp"

SdlWrapper::Window::Window(const VideoContext* ctx,
                           const std::string& title,
                           const int x,
                           const int y,
                           const int w,
                           const int h,
                           const std::uint32_t flags)
    : _handle{SDL_CreateWindow(title.c_str(), x, y, w, h, flags)}, _ctx(ctx)
{
    if (_handle == nullptr)
    {
        throw Error::NullPointer("SDL_CreateWindow");
    }
}

SdlWrapper::Window::~Window()
{
    if (_handle != nullptr)
    {
        SDL_DestroyWindow(_handle);
    }
}

SdlWrapper::Window::Window(Window&& other) noexcept : _handle(other._handle)
{
    other._handle = nullptr;
}

SdlWrapper::Window& SdlWrapper::Window::operator=(Window&& other) noexcept
{
    if (&other != this)
    {
        if (_handle != nullptr)
        {
            SDL_DestroyWindow(_handle);
        }
        _handle = other._handle;
        other._handle = nullptr;
    }

    return *this;
}
