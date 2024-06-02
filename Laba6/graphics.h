#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <string>

// Клас Point представляє точку на площині з її координатами
class Point {
protected:
    float x, y;
public:
    Point(float x = 0, float y = 0);
    virtual ~Point() {}
    virtual void move(float dx, float dy);
    virtual void draw(sf::RenderWindow& window) const = 0;
};

// Клас Window представляє графічне вікно, успадковане від класу Point
class Window : public Point {
private:
    float width, height;
    sf::Color color;
    float rotation;
public:
    Window(float x = 0, float y = 0, float width = 100, float height = 100, sf::Color color = sf::Color::White);
    void resize(float newWidth, float newHeight);
    void changeColor(sf::Color newColor);
    void rotate(float angle);
    void draw(sf::RenderWindow& window) const override;
};

#endif // GRAPHICS_H