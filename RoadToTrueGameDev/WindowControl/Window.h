#ifndef WINDOWCONTROL_WINDOW_H
#define WINDOWCONTROL_WINDOW_H

#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window() noexcept(false);
    explicit Window(const std::string& WindowTitle, sf::Vector2u& WindowSize);
    ~Window();

    void BeginDraw() noexcept;  // Clear the window
    void EndDraw() noexcept;  // Display changes

    void Update();

    constexpr bool isDone() const noexcept;
    constexpr bool isFullScreen() const noexcept;
    sf::Vector2u GetWindowSize() const;

    void ToggleFullScreen();

    void Draw(sf::Drawable& l_drawable);

private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullScreen;

};

#endif //WINDOWCONTROL_WINDOW_H
