#pragma once

#include <SDL2/SDL_render.h>

namespace sdl
{
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

	void clear();
	void present();
};
} // namespace sdl
