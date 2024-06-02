#include "dictionary.h"
#include <iostream>

void printMenu() {
    std::cout << "1. Add word\n";
    std::cout << "2. Remove word\n";
    std::cout << "3. Translate word\n";
    std::cout << "4. Print dictionary\n";
    std::cout << "5. Load from file\n";
    std::cout << "6. Save to file\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Dictionary dictionary;
    int choice;
    std::string english, ukrainian, filename;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter English word: ";
            std::cin >> english;
            std::cout << "Enter Ukrainian word: ";
            std::cin >> ukrainian;
            dictionary.addWord(english, ukrainian);
            break;
        case 2:
            std::cout << "Enter English word to remove: ";
            std::cin >> english;
            dictionary.removeWord(english);
            break;
        case 3:
            std::cout << "Enter English word to translate: ";
            std::cin >> english;
            std::cout << "Translation: " << dictionary.translate(english) << std::endl;
            break;
        case 4:
            dictionary.printDictionary();
            break;
        case 5:
            std::cout << "Enter filename to load from: ";
            std::cin >> filename;
            dictionary.loadFromFile(filename);
            break;
        case 6:
            std::cout << "Enter filename to save to: ";
            std::cin >> filename;
            dictionary.saveToFile(filename);
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
