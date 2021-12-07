#pragma once

#include <string>

namespace sdl
{
class TtfFont;

class TtfContext
{
	bool m_isMain;

	TtfContext();
	friend class GraphicsContext;

	void cleanup() const;

  public:
	~TtfContext();
	TtfContext(const TtfContext&) = delete;
	TtfContext& operator=(const TtfContext&) = delete;
	TtfContext(TtfContext&& other) noexcept;
	TtfContext& operator=(TtfContext&& other) noexcept;

	[[nodiscard]] TtfFont openFont(const std::string& path, int pointSize) const;
};
} // namespace sdl