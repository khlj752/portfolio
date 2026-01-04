#include <Windows.h>

#include <defs.hpp>

struct Size {
  unsigned int width;
  unsigned int height;
};

struct Position {
  int x;
  int y;
};

class Window {
public:
  explicit Window(const k::string& title, Size windowSize, Position position);
  ~Window();

  Window(const Window& other) = delete;
  auto operator=(const Window& other) -> Window& = delete;
  Window(Window&& other) = delete;
  auto operator=(Window&& other) -> Window& = delete;

  void Run();

private:
  HWND mWndHandle_;
  k::string mTitle_;
  Size mSize_;
  Position mPosition_;
  bool mIsRunning_ = false;

  static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                     LPARAM lParam);
  LRESULT HandleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};