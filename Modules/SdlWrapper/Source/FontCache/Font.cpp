#include "SdlWrapper/FontCache/Font.hpp"

#include "SdlWrapper/Error.hpp"
#include "SdlWrapper/Renderer.hpp"

SdlWrapper::FontCache::Font::Font() : _handle(FC_CreateFont())
{
    if (_handle == nullptr)
    {
        throw Error::NullPointer("FC_CreateFont");
    }
}

SdlWrapper::FontCache::Font::~Font()
{
    if (_handle != nullptr)
    {
        FC_FreeFont(_handle);
    }
}

SdlWrapper::FontCache::Font::Font(Font&& other) noexcept : _handle(other._handle)
{
    other._handle = nullptr;
}

SdlWrapper::FontCache::Font& SdlWrapper::FontCache::Font::operator=(Font&& other) noexcept
{
    if (&other != this)
    {
        if (_handle != nullptr)
        {
            FC_FreeFont(_handle);
        }

        _handle = other._handle;
        other._handle = nullptr;
    }

    return *this;
}

void SdlWrapper::FontCache::Font::Load(const Renderer& renderer,
                                       const std::string& filename,
                                       const std::uint32_t pointSize,
                                       const SDL_Color color,
                                       const int style) const
{
    if (const std::uint8_t ret = FC_LoadFont(_handle, renderer.Get(), filename.c_str(), pointSize, color, style);
        ret == 0)
    {
        throw Error::FailureCode("FC_LoadFont", ret);
    }
}

void SdlWrapper::FontCache::Font::Draw(const Renderer& renderer,
                                       const float x,
                                       const float y,
                                       const std::string& text) const
{
    if (const auto [xRes, yRes, w, h] = FC_Draw(_handle, renderer.Get(), x, y, text.c_str()); w == 0)
    {
        throw Error::FailureCode("FC_Draw", 0);
    }
}
