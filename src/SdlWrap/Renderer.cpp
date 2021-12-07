#include "SdlWrap/Renderer.hpp"
#include "SdlWrap/FcFont.hpp"
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
void sdl::Renderer::setDrawColor(SDL_Color color)
{
	if (SDL_SetRenderDrawColor(m_handle, color.r, color.g, color.b, color.a) != 0)
	{
		std::ostringstream message;
		message << "SDL_SetRenderDrawColor: " << SDL_GetError();
		throw std::runtime_error{message.str()};
	}
}
sdl::FcFont sdl::Renderer::loadFont(const std::string& path, int pointSize, SDL_Color color, int style)
{
	FC_Font* handle = FC_CreateFont();
	if (FC_LoadFont(handle, m_handle, path.c_str(), pointSize, color, style) == 0)
	{
		std::ostringstream message;
		message << "FC_LoadFont reported failure";
		throw std::runtime_error{message.str()};
	}
	return FcFont{handle, m_handle};
}
