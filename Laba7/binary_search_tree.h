#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.h"
#include <iostream>
#include <fstream>

class BinarySearchTree {
private:
    Node* root;

    void addHelper(Node*& node, const std::string& key, const std::string& value) {
        if (node == nullptr) {
            node = new Node(key, value);
        }
        else if (key < node->key) {
            addHelper(node->left, key, value);
        }
        else if (key > node->key) {
            addHelper(node->right, key, value);
        }
        else {
            node->value = value; // Update the value if the key already exists
        }
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* removeHelper(Node* node, const std::string& key) {
        if (node == nullptr) return node;
        if (key < node->key) {
            node->left = removeHelper(node->left, key);
        }
        else if (key > node->key) {
            node->right = removeHelper(node->right, key);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = removeHelper(node->right, temp->key);
            }
        }
        return node;
    }

    Node* searchHelper(Node* node, const std::string& key) {
        if (node == nullptr || node->key == key) return node;
        if (key < node->key) return searchHelper(node->left, key);
        return searchHelper(node->right, key);
    }

    void inorderHelper(Node* node, std::ostream& os) {
        if (node != nullptr) {
            inorderHelper(node->left, os);
            os << node->key << " " << node->value << std::endl;
            inorderHelper(node->right, os);
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void add(const std::string& key, const std::string& value) {
        addHelper(root, key, value);
    }

    void remove(const std::string& key) {
        root = removeHelper(root, key);
    }

    std::string search(const std::string& key) {
        Node* result = searchHelper(root, key);
        return result ? result->value : "Not found";
    }

    void inorder() {
        inorderHelper(root, std::cout);
    }

    void inorderToFile(std::ofstream& file) {
        inorderHelper(root, file);
    }
};

#endif // BINARY_SEARCH_TREE_H
