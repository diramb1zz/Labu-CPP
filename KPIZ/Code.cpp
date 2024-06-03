#include <iostream>
#include <vector>

// Клас "коло"
class Circle {
public:
    int x, y; // Координати центру кола
    int R;    // Радіус кола

    // Конструктор
    Circle(int x, int y, int R) : x(x), y(y), R(R) {}

    // Метод для виведення інформації про коло
    void print() const {
        std::cout << "Circle(" << x << ", " << y << ", " << R << ")\n";
    }
};

int main() {
    // Створення вектора, що містить об'єкти класу "коло"
    std::vector<Circle> circles;

    // Додавання елементів до вектора
    circles.emplace_back(0, 0, 5);
    circles.emplace_back(2, 3, 10);
    circles.emplace_back(-1, -1, 3);

    // Виведення інформації про всі кола у векторі
    std::cout << "Circles in the vector:\n";
    for (const auto& circle : circles) {
        circle.print();
    }

    // Видалення останнього елементу з вектора
    circles.pop_back();

    // Виведення інформації про всі кола у векторі після видалення
    std::cout << "\nAfter removing the last circle:\n";
    for (const auto& circle : circles) {
        circle.print();
    }

    // Доступ до конкретного елементу вектора
    if (!circles.empty()) {
        std::cout << "\nFirst circle in the vector:\n";
        circles.front().print();
    }

    return 0;
}
