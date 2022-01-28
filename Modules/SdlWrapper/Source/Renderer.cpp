#include "SdlWrapper/Renderer.hpp"

#include "SdlWrapper/Error.hpp"

SdlWrapper::Renderer::Renderer(SDL_Window* pWindow, const int index, const std::uint32_t flags)
    : _handle(SDL_CreateRenderer(pWindow, index, flags))
{
    if (_handle == nullptr)
    {
        throw Error::NullPointer("SDL_CreateRenderer");
    }
}

SdlWrapper::Renderer::~Renderer()
{
    if (_handle != nullptr)
    {
        SDL_DestroyRenderer(_handle);
    }
}

SdlWrapper::Renderer::Renderer(Renderer&& other) noexcept : _handle(other._handle)
{
    other._handle = nullptr;
}

SdlWrapper::Renderer& SdlWrapper::Renderer::operator=(Renderer&& other) noexcept
{
    if (&other != this)
    {
        if (_handle != nullptr)
        {
            SDL_DestroyRenderer(_handle);
        }
        _handle = other._handle;
        other._handle = nullptr;
    }

    return *this;
}
