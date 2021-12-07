#pragma once

#include <SDL2/SDL_stdinc.h>

namespace sdl
{
class Window;
class TtfContext;

class GraphicsContext
{
	bool m_isMain;

	void cleanup() const;

  public:
	explicit GraphicsContext(Uint32 flags);
	~GraphicsContext();
	GraphicsContext(const GraphicsContext&) = delete;
	GraphicsContext& operator=(const GraphicsContext&) = delete;
	GraphicsContext(GraphicsContext&& other) noexcept;
	GraphicsContext& operator=(GraphicsContext&& other) noexcept;

	TtfContext initTtf() const;

	Window createWindow(const char* title, int width, int height, Uint32 flags);
};
} // namespace sdl