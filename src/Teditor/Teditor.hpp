#pragma once

#include <SdlWrap/FcFont.hpp>
#include <rope.h>

class Teditor
{
	rope* m_rope;
	size_t m_pos;

	void cleanup() const;

  public:
	Teditor();
	~Teditor();
	Teditor(const Teditor&) = delete;
	Teditor& operator=(const Teditor&) = delete;
	Teditor(Teditor&& other) noexcept;
	Teditor& operator=(Teditor&& other) noexcept;

	void renderText(const sdl::FcFont& font) const;
	void writeText(const char* string);
	void backspace();
};
