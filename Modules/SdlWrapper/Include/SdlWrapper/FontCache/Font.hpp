#pragma once

#include <SDL_FontCache.h>
#include <string>

namespace SdlWrapper
{
class Renderer;
}

namespace SdlWrapper::FontCache
{

class Font
{
    FC_Font* _handle;

  public:
    Font();
    ~Font();
    Font(const Font&) = delete;
    Font& operator=(const Font&) = delete;
    Font(Font&& other) noexcept;
    Font& operator=(Font&& other) noexcept;

    void Load(const Renderer& renderer,
              const std::string& filename,
              std::uint32_t pointSize,
              SDL_Color color,
              int style) const;
    void Draw(const Renderer& renderer, float x, float y, const std::string& text) const;
};

} // namespace SdlWrapper::FontCache
