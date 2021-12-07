#include "SdlWrap/GraphicsContext.hpp"
#include "SdlWrap/Window.hpp"
#include <SDL2/SDL.h>
#include <sstream>
#include <stdexcept>

void sdl::GraphicsContext::cleanup() const
{
	if (m_isMain)
	{
		SDL_Quit();
	}
}

sdl::GraphicsContext::GraphicsContext(Uint32 flags) : m_isMain{true}
{
	SDL_Init(flags);
}

sdl::GraphicsContext::~GraphicsContext()
{
	cleanup();
}

sdl::GraphicsContext::GraphicsContext(sdl::GraphicsContext&& other) noexcept : m_isMain{other.m_isMain}
{
	other.m_isMain = false;
}

sdl::GraphicsContext& sdl::GraphicsContext::operator=(sdl::GraphicsContext&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_isMain = other.m_isMain;
		other.m_isMain = false;
	}
	return *this;
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
sdl::Window sdl::GraphicsContext::createWindow(const char* title, int width, int height, Uint32 flags)
{
	SDL_Window* handle =
	        SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	if (handle == nullptr)
	{
		std::ostringstream message;
		message << "SDL window creation failed: " << SDL_GetError();
		throw std::runtime_error{message.str()};
	}
	return sdl::Window{handle};
}
