#include "SdlWrap/Renderer.hpp"
#include <sstream>

sdl::Renderer::Renderer(SDL_Renderer* handle) : m_handle{handle}
{
}
void sdl::Renderer::cleanup() const
{
	if (m_handle != nullptr)
	{
		SDL_DestroyRenderer(m_handle);
	}
}
sdl::Renderer::~Renderer()
{
	cleanup();
}
sdl::Renderer::Renderer(sdl::Renderer&& other) noexcept : m_handle{other.m_handle}
{
	other.m_handle = nullptr;
}
sdl::Renderer& sdl::Renderer::operator=(sdl::Renderer&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_handle = other.m_handle;
		other.m_handle = nullptr;
	}
	return *this;
}

void sdl::Renderer::clear()
{
	if (SDL_RenderClear(m_handle) != 0)
	{
		std::ostringstream message;
		message << "SDL_RenderClear: " << SDL_GetError();
		throw std::runtime_error{message.str()};
	}
}

void sdl::Renderer::present()
{
	SDL_RenderPresent(m_handle);
}
