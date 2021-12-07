#include "SdlWrap/FcFont.hpp"

sdl::FcFont::FcFont(FC_Font* handle, SDL_Renderer* renderer) : m_handle{handle}, m_renderer{renderer}
{
}

void sdl::FcFont::cleanup() const
{
	if (m_handle != nullptr)
	{
		FC_FreeFont(m_handle);
	}
}

sdl::FcFont::~FcFont()
{
	cleanup();
}

sdl::FcFont::FcFont(sdl::FcFont&& other) noexcept : m_handle{other.m_handle}, m_renderer{other.m_renderer}
{
	other.m_handle = nullptr;
}

sdl::FcFont& sdl::FcFont::operator=(sdl::FcFont&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_handle = other.m_handle;
		m_renderer = other.m_renderer;
		other.m_handle = nullptr;
	}
	return *this;
}

void sdl::FcFont::draw(float x, float y, const std::string& text) const
{
	FC_Draw(m_handle, m_renderer, x, y, text.c_str());
}
