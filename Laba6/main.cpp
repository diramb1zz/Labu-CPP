#include <SFML/Graphics.hpp>
#include "graphics.h"
#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "1. Create Window\n";
    std::cout << "2. Move Window\n";
    std::cout << "3. Resize Window\n";
    std::cout << "4. Change Color\n";
    std::cout << "5. Rotate Window\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

bool isValidColorValue(int value) {
    return value >= 0 && value <= 255;
}

void handleMenuChoice(int choice, Window*& window) {
    switch (choice) {
    case 1: {
        float x, y, width, height;
        int r, g, b;
        std::cout << "Enter x, y, width, height, color (r g b): ";
        if (std::cin >> x >> y >> width >> height >> r >> g >> b &&
            isValidColorValue(r) && isValidColorValue(g) && isValidColorValue(b)) {
            if (window != nullptr) {
                delete window;
            }
            window = new Window(x, y, width, height, sf::Color(r, g, b));
        }
        else {
            std::cout << "Invalid input. Please enter valid values.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
    }
    case 2: {
        if (window) {
            float dx, dy;
            std::cout << "Enter dx, dy: ";
            if (std::cin >> dx >> dy) {
                window->move(dx, dy);
            }
            else {
                std::cout << "Invalid input. Please enter valid values.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Window not created yet.\n";
        }
        break;
    }
    case 3: {
        if (window) {
            float width, height;
            std::cout << "Enter new width, new height: ";
            if (std::cin >> width >> height) {
                window->resize(width, height);
            }
            else {
                std::cout << "Invalid input. Please enter valid values.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Window not created yet.\n";
        }
        break;
    }
    case 4: {
        if (window) {
            int r, g, b;
            std::cout << "Enter new color (r g b): ";
            if (std::cin >> r >> g >> b &&
                isValidColorValue(r) && isValidColorValue(g) && isValidColorValue(b)) {
                window->changeColor(sf::Color(r, g, b));
            }
            else {
                std::cout << "Invalid input. Please enter valid values.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Window not created yet.\n";
        }
        break;
    }
    case 5: {
        if (window) {
            float angle;
            std::cout << "Enter angle to rotate: ";
            if (std::cin >> angle) {
                window->rotate(angle);
            }
            else {
                std::cout << "Invalid input. Please enter valid values.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Window not created yet.\n";
        }
        break;
    }
    case 6: {
        std::exit(0);
    }
    default: {
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
    }
}

int main() {
    sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Graphics Window");
    Window* window = nullptr;

    while (renderWindow.isOpen()) {
        sf::Event event;
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderWindow.close();
            }
        }

        renderWindow.clear();
        if (window) {
            window->draw(renderWindow);
        }
        renderWindow.display();

        showMenu();
        int choice;
        if (std::cin >> choice) {
            handleMenuChoice(choice, window);
        }
        else {
            std::cout << "Invalid input. Please enter a valid choice.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if (window != nullptr) {
        delete window;
    }

    return 0;
}
