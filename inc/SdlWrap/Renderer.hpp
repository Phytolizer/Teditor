#pragma once

#include <SDL2/SDL_render.h>
#include <string>
#include "FcFont.hpp"

namespace sdl
{
class FcFont;

class Renderer
{
	SDL_Renderer* m_handle;
	explicit Renderer(SDL_Renderer* handle);
	friend class Window;

	void cleanup() const;

  public:
	~Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	Renderer(Renderer&& other) noexcept;
	Renderer& operator=(Renderer&& other) noexcept;

	[[nodiscard]] FcFont loadFont(const std::string& path, int pointSize, SDL_Color color, int style);

	void clear();
	void present();
	void setDrawColor(SDL_Color color);
};
} // namespace sdl
