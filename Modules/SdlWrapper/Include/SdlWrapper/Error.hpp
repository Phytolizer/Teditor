#pragma once

#include <stdexcept>
#include <string_view>

namespace SdlWrapper
{

struct Error final : std::runtime_error
{
  private:
    std::string _message;

    Error(std::string_view function, int code) noexcept;
    explicit Error(std::string_view function) noexcept;

  public:
    static Error FailureCode(std::string_view function, int code) noexcept;
    static Error NullPointer(std::string_view function) noexcept;

    [[nodiscard]] const char* what() const noexcept override;
};

} // namespace SdlWrapper
