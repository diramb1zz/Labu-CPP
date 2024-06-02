#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "binary_search_tree.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Dictionary {
private:
    BinarySearchTree bst;

public:
    void addWord(const std::string& english, const std::string& russian) {
        bst.add(english, russian);
    }

    void removeWord(const std::string& english) {
        bst.remove(english);
    }

    std::string translate(const std::string& english) {
        return bst.search(english);
    }

    void printDictionary() {
        bst.inorder();
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string english, russian;
                if (iss >> english >> russian) {
                    addWord(english, russian);
                }
            }
            file.close();
        }
        else {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            bst.inorderToFile(file);
            file.close();
        }
        else {
            std::cerr << "Unable to open file" << std::endl;
        }
    }
};

#endif // DICTIONARY_H