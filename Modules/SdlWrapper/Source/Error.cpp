#include "SdlWrapper/Error.hpp"

#include <sstream>

SdlWrapper::Error::Error(const std::string_view function, const int code) noexcept : runtime_error{"dummy message"}
{
    std::ostringstream messageStream;
    messageStream << function << " returned non-zero code " << code;
    _message = messageStream.str();
}

SdlWrapper::Error::Error(const std::string_view function) noexcept : runtime_error{"dummy message"}
{
    std::ostringstream messageStream;
    messageStream << function << " returned NULL when it shouldn't";
    _message = messageStream.str();
}

SdlWrapper::Error SdlWrapper::Error::FailureCode(const std::string_view function, const int code) noexcept
{
    return Error{function, code};
}

SdlWrapper::Error SdlWrapper::Error::NullPointer(const std::string_view function) noexcept
{
    return Error{function};
}

const char* SdlWrapper::Error::what() const
{
    return _message.c_str();
}
