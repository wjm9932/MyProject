#pragma once
#include <memory>
#include "Vector2.hpp"

class PlatformWindow;

class Window
{
public:
    Window() noexcept;
    ~Window() noexcept;

    bool CreateWindow() noexcept;
    void PollEvent() noexcept;
    void SwapBackBuffer() const noexcept;

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

private:
    std::unique_ptr<PlatformWindow> platformWindow{};
};
