#include "SdlWrap/TtfFont.hpp"

void sdl::TtfFont::cleanup() const
{
	if (m_handle != nullptr)
	{
		TTF_CloseFont(m_handle);
	}
}

sdl::TtfFont::TtfFont(TTF_Font* handle) : m_handle{handle}
{
}

sdl::TtfFont::TtfFont(TtfFont&& other) noexcept : m_handle{other.m_handle}
{
	other.m_handle = nullptr;
}

sdl::TtfFont::~TtfFont()
{
	cleanup();
}
sdl::TtfFont& sdl::TtfFont::operator=(sdl::TtfFont&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_handle = other.m_handle;
		other.m_handle = nullptr;
	}
	return *this;
}
