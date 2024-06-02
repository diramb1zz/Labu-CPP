#include "graphics.h"
#include <SFML/Graphics.hpp>

// Реалізація конструктора та методів класу Point
Point::Point(float x, float y) : x(x), y(y) {}

void Point::move(float dx, float dy) {
    x += dx;
    y += dy;
}

// Реалізація конструктора та методів класу Window
Window::Window(float x, float y, float width, float height, sf::Color color)
    : Point(x, y), width(width), height(height), color(color), rotation(0) {}

void Window::resize(float newWidth, float newHeight) {
    width = newWidth;
    height = newHeight;
}

void Window::changeColor(sf::Color newColor) {
    color = newColor;
}

void Window::rotate(float angle) {
    rotation += angle;
}

void Window::draw(sf::RenderWindow& window) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    rectangle.setRotation(rotation);
    window.draw(rectangle);
}