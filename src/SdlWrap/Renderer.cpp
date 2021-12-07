#include "SdlWrap/Renderer.hpp"

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
