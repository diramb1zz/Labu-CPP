#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string key;
    std::string value;
    Node* left;
    Node* right;

    Node(const std::string& k, const std::string& v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
