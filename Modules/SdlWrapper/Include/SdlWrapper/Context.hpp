#pragma once

namespace SdlWrapper
{

class VideoContext;

class Context
{
    bool _isActive;

  public:
    Context();
    ~Context();

    // It doesn't make any sense to init/deinit SDL twice.
    Context(const Context&) = delete;
    Context& operator=(const Context&) = delete;

    // However, you may move the context out of its originating function.
    Context(Context&& other) noexcept;
    Context& operator=(Context&& other) noexcept;

    [[nodiscard]] VideoContext Video() const;
};

} // namespace SdlWrapper
