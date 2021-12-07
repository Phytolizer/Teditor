#include "SdlWrap/TtfContext.hpp"
#include "SdlWrap/TtfFont.hpp"
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <stdexcept>

void sdl::TtfContext::cleanup() const
{
	if (m_isMain)
	{
		TTF_Quit();
	}
}

sdl::TtfContext::TtfContext() : m_isMain{true}
{
	if (TTF_Init() != 0)
	{
		std::ostringstream message;
		message << "TTF_Init: " << SDL_GetError();
		throw std::runtime_error{message.str()};
	}
}

sdl::TtfContext::~TtfContext()
{
	cleanup();
}

sdl::TtfContext::TtfContext(sdl::TtfContext&& other) noexcept : m_isMain{other.m_isMain}
{
	other.m_isMain = false;
}

sdl::TtfContext& sdl::TtfContext::operator=(sdl::TtfContext&& other) noexcept
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
sdl::TtfFont sdl::TtfContext::openFont(const std::string& path, int pointSize) const
{
	TTF_Font* handle = TTF_OpenFont(path.c_str(), pointSize);
	if (handle == nullptr)
	{
		std::ostringstream message;
		message << "TTF_OpenFont: " << SDL_GetError();
		throw std::runtime_error{message.str()};
	}
	return TtfFont{handle};
}
