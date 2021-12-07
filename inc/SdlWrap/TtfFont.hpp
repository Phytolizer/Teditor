#pragma once

#include <SDL2/SDL_ttf.h>

namespace sdl
{
class TtfFont
{
	TTF_Font* m_handle;

	explicit TtfFont(TTF_Font* handle);
	friend class TtfContext;

	void cleanup() const;

  public:
	~TtfFont();
	TtfFont(const TtfFont&) = delete;
	TtfFont& operator=(const TtfFont&) = delete;
	TtfFont(TtfFont&& other) noexcept;
	TtfFont& operator=(TtfFont&& other) noexcept;
};
} // namespace sdl