#include "SdlWrap/Window.hpp"
#include "SdlWrap/Renderer.hpp"
#include <sstream>

sdl::Window::Window(SDL_Window* handle) : m_handle{handle}
{
}
void sdl::Window::cleanup() const
{
	if (m_handle != nullptr)
	{
		SDL_DestroyWindow(m_handle);
	}
}

sdl::Renderer sdl::Window::createRenderer(int index, Uint32 flags)
{
	SDL_Renderer* handle = SDL_CreateRenderer(m_handle, index, flags);
	if (handle == nullptr)
	{
		std::ostringstream message;
		message << "SDL renderer creation failed: " << SDL_GetError();
		throw std::runtime_error{message.str()};
	}
	return Renderer{handle};
}

sdl::Window::~Window()
{
	cleanup();
}
sdl::Window::Window(sdl::Window&& other) noexcept : m_handle{other.m_handle}
{
	other.m_handle = nullptr;
}
sdl::Window& sdl::Window::operator=(sdl::Window&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_handle = other.m_handle;
		other.m_handle = nullptr;
	}
	return *this;
}
