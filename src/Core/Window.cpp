#include "Core/Window.hpp"

#include <winuser.h>

#include <format>
#include <iostream>

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                    LPARAM lParam) {
  auto* window =
      reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

  if (window != nullptr) {
    return window->HandleMessage(hwnd, uMsg, wParam, lParam);
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window(const k::string& title, Size windowSize, Position position)
    : mTitle_(title), mSize_(windowSize), mPosition_(position) {
  HMODULE hInstance = GetModuleHandle(nullptr);
  WNDCLASSEX wcex{};
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WindowProc;
  wcex.hInstance = hInstance;
  wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
  wcex.lpszClassName = title.c_str();

  if (!RegisterClassEx(&wcex)) {
    std::wcerr << std::format(L"Failed to register window class. Error: {}\n",
                              GetLastError());
    return;
  }

  RECT windowRect = {0, 0, static_cast<LONG>(mSize_.width),
                     static_cast<LONG>(mSize_.height)};
  AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

  mWndHandle_ = CreateWindowEx(
      0, mTitle_.c_str(), mTitle_.c_str(), WS_OVERLAPPEDWINDOW, mPosition_.x,
      mPosition_.y, windowRect.right - windowRect.left,
      windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, this);

  if (mWndHandle_ != nullptr) {
    SetWindowLongPtr(mWndHandle_, GWLP_USERDATA,
                     reinterpret_cast<LONG_PTR>(this));
    ShowWindow(mWndHandle_, SW_SHOW);
    mIsRunning_ = true;
    std::wcout << std::format(L"Window created: {}", mTitle_) << "\n";
  } else {
    std::wcerr << std::format(L"Failed to create window. Error: {}\n",
                              GetLastError());
  }
}

Window::~Window() {
  if (mWndHandle_ != nullptr) {
    DestroyWindow(mWndHandle_);
    std::wcout << std::format(L"Window destroyed: {}", mTitle_) << "\n";
  }
}

auto Window::HandleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    -> LRESULT {
  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      mIsRunning_ = false;
      return 0;
    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}

void Window::Run() {
  MSG msg{};
  while (mIsRunning_) {
    if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    } else {
      // CPU 사용 양보 ( 임시 )
      WaitMessage();
    }
  }
}