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

SDL_Renderer* SdlWrapper::Renderer::Get() const
{
    return _handle;
}

void SdlWrapper::Renderer::SetDrawColor(const SDL_Color color) const
{
    if (const int code = SDL_SetRenderDrawColor(_handle, color.r, color.g, color.b, color.a); code != 0)
    {
        throw Error::FailureCode("SDL_SetRenderDrawColor", code);
    }
}

void SdlWrapper::Renderer::Clear() const
{
    if (const int code = SDL_RenderClear(_handle); code != 0)
    {
        throw Error::FailureCode("SDL_RenderClear", code);
    }
}

void SdlWrapper::Renderer::Present() const
{
    SDL_RenderPresent(_handle);
}
