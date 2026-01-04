#include <Windows.h>

#include <string>

class Window {
public:
  explicit Window(const unsigned int width, const unsigned int height,
                  const int posX, const int posY) {}
  ~Window() {}

  Window(const Window& other) = delete;
  Window& operator=(const Window& other) = delete;
  Window(Window&& other) = delete;
  Window& operator=(Window&& other) = delete;

public:
  HWND wnd_handle_ = NULL;
  const std::string title_;
  unsigned int width_;
  unsigned int height_;
};