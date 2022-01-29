#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdint>

namespace SdlWrapper
{

class Renderer
{
    SDL_Renderer* _handle;

    friend class Window;
    Renderer(SDL_Window* pWindow, int index, std::uint32_t flags);

  public:
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&& other) noexcept;
    Renderer& operator=(Renderer&& other) noexcept;

    [[nodiscard]] SDL_Renderer* Get() const;

    void SetDrawColor(SDL_Color color) const;
    void Clear() const;
    void Present() const;
};

} // namespace SdlWrapper
