#include "Teditor.hpp"

void Teditor::cleanup() const
{
	if (m_rope != nullptr)
	{
		rope_free(m_rope);
	}
}

Teditor::Teditor() : m_rope{rope_new()}, m_pos{0}
{
}

Teditor::~Teditor()
{
	cleanup();
}

Teditor::Teditor(Teditor&& other) noexcept : m_rope{other.m_rope}, m_pos{other.m_pos}
{
	other.m_rope = nullptr;
}

Teditor& Teditor::operator=(Teditor&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_rope = other.m_rope;
		m_pos = other.m_pos;
		other.m_rope = nullptr;
	}
	return *this;
}

void Teditor::renderText(const sdl::FcFont& font) const
{
	uint8_t* text = rope_create_cstr(m_rope);
	font.draw(0, 0, reinterpret_cast<const char*>(text));
	free(text);
}

void Teditor::writeText(const char* string)
{
	rope_insert(m_rope, m_pos, reinterpret_cast<const uint8_t*>(string));
	m_pos += strlen(string);
}
