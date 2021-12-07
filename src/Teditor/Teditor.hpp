#pragma once

#include <SdlWrap/FcFont.hpp>
#include <rope.h>

class Teditor
{
	rope* m_rope;

	void cleanup() const;

  public:
	Teditor();
	~Teditor();
	Teditor(const Teditor&) = delete;
	Teditor& operator=(const Teditor&) = delete;
	Teditor(Teditor&& other) noexcept;
	Teditor& operator=(Teditor&& other) noexcept;

	void renderText(const sdl::FcFont& font) const;
};
