#pragma once

#include "SdlWrapper/Context.hpp"

#include <string>

namespace SdlWrapper
{

class Window;

class VideoContext
{
    bool _isActive;

    friend class Context;
    explicit VideoContext(const Context* parent);

  public:
    ~VideoContext();
    VideoContext(const VideoContext&) = delete;
    VideoContext& operator=(const VideoContext&) = delete;
    VideoContext(VideoContext&& other) noexcept;
    VideoContext& operator=(VideoContext&& other) noexcept;

    [[nodiscard]] Window CreateWindow(const std::string& title, int x, int y, int w, int h, std::uint32_t flags) const;
};

} // namespace SdlWrapper
