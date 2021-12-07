#pragma once

#include <SDL2/SDL_video.h>

namespace sdl
{
class Renderer;

class Window
{
	SDL_Window* m_handle;

	explicit Window(SDL_Window* handle);
	friend class GraphicsContext;

	void cleanup() const;

  public:
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&& other) noexcept;
	Window& operator=(Window&& other) noexcept;

	Renderer createRenderer(int index, Uint32 flags);
};
} // namespace sdl