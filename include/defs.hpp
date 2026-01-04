#pragma once

#include <string>

namespace k {

#if !defined(UNICODE) || !defined(_UNICODE)
#define UNICODE
#define _UNICODE
#endif

using string = std::wstring;
};  // namespace k