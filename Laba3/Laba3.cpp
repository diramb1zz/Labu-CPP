#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* data; // Вказівник на початок масиву
    int size;  // Розмір масиву

public:
    // Конструктор за замовчуванням
    Vector() : data(nullptr), size(0) {}

    // Конструктор з вказанням розміру масиву
    Vector(int size) : size(size) {
        if (size < 10 || size > 10000) {
            throw std::invalid_argument("Invalid size. Size should be between 10 and 10000.");
        }
        data = new int[size];
    }

    // Деструктор для звільнення виділеної пам'яті
    ~Vector() {
        delete[] data;
    }

    // Перевантаження оператора індексації []
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    // Метод для отримання розміру масиву
    int getSize() const {
        return size;
    }
};

int main() {
    try {
        // Створення об'єкту класу Vector з розміром 100
        Vector vec(100);

        // Заповнення масиву значеннями
        for (int i = 0; i < vec.getSize(); ++i) {
            vec[i] = i * 10;
        }

        // Виведення елементів масиву
        for (int i = 0; i < vec.getSize(); ++i) {
            std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

