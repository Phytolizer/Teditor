#pragma once

#include <SDL_FontCache.h>
#include <string>

namespace sdl
{
class FcFont
{
	FC_Font* m_handle;
	SDL_Renderer* m_renderer;

	FcFont(FC_Font* handle, SDL_Renderer* renderer);
	friend class Renderer;

	void cleanup() const;

  public:
	~FcFont();
	FcFont(const FcFont&) = delete;
	FcFont& operator=(const FcFont&) = delete;
	FcFont(FcFont&& other) noexcept;
	FcFont& operator=(FcFont&& other) noexcept;

	void draw(float x, float y, const std::string& text);
};
} // namespace sdl
