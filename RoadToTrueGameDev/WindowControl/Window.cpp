#include <iostream>
#include "Window.h"


Window::Window() noexcept(false) {
    Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string &WindowTitle, sf::Vector2u &WindowSize){
    Setup(WindowTitle, WindowSize);
}

Window::~Window() {
    Destroy();
}

void Window::Setup(const std::string &l_title, const sf::Vector2u &l_size) {
    this->m_windowTitle = l_title;
    this->m_windowSize = l_size;
    this->m_isFullScreen = false;
    this->m_isDone = false;
    Create();
}

void Window::Create() {
    auto style = (this->m_isFullScreen ? sf::Style::Fullscreen
            : sf::Style::Default);

    this->m_window.create( {this->m_windowSize.x, this->m_windowSize.y, 32},
            this->m_windowTitle, style);
}

void Window::Destroy() {
    this->m_window.close();
}

void Window::Update() {
    sf::Event event;
    while(this->m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            this->m_isDone = true;
        }else if(event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::F5) {
            ToggleFullScreen();
        }
    }
}

void Window::ToggleFullScreen() {
    this->m_isDone = !(this->m_isDone);
    Destroy();
    Create();
}

void Window::BeginDraw() noexcept {
    this->m_window.clear(sf::Color::Black);
}

void Window::EndDraw() noexcept {
    this->m_window.display();
}

constexpr bool Window::isDone() const noexcept{
    return this->m_isDone;
}

 constexpr bool Window::isFullScreen() const noexcept{
    return this->m_isFullScreen;
}

sf::Vector2u Window::GetWindowSize() const {
    return this->m_windowSize;
}

void Window::Draw(sf::Drawable &l_drawable) {
    this->m_window.draw(l_drawable);
}