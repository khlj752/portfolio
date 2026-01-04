#include "Core/Window.hpp"

auto main() -> int {
  Window window(L"Test", {.width = 800, .height = 640}, {.x = 0, .y = 0});
  window.Run();
  return 0;
}