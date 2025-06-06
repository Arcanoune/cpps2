#pragma once
#include <vector>
#include <iostream>

struct Node {
    int value;
    Node* left {nullptr};
    Node* right {nullptr};

    bool is_leaf() const;
    void insert(int v);
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node const*> prefix() const;
};

Node* create_node(int value);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);

////////////////////////

// #pragma once
// #include <vector>

// struct Node {
//     int value;
//     Node* left { nullptr };
//     Node* right { nullptr };

//     bool is_leaf() const;
//     void insert(int val);
//     int height() const;
//     void delete_children();
//     void display_infix() const;
//     std::vector<Node const*> prefix() const;
// };

// Node* create_node(int value);
// void delete_tree(Node* node);
