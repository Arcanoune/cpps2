#include "node.hpp"

Node* create_node(int value) {
    return new Node{value};
}

bool Node::is_leaf() const {
    return !left && !right;
}

void Node::insert(int v) {
    if (v < value) {
        if (!left) left = create_node(v);
        else left->insert(v);
    } else {
        if (!right) right = create_node(v);
        else right->insert(v);
    }
}

int Node::height() const {
    int h_left = left ? left->height() : 0;
    int h_right = right ? right->height() : 0;
    return 1 + std::max(h_left, h_right);
}

void Node::delete_children() {
    if (left) {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right) {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const {
    if (left) left->display_infix();
    std::cout << value << " ";
    if (right) right->display_infix();
}

std::vector<Node const*> Node::prefix() const {
    std::vector<Node const*> nodes{this};
    if (left) {
        auto left_nodes = left->prefix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        auto right_nodes = right->prefix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

Node*& most_left(Node*& node) {
    if (!node->left) return node;
    return most_left(node->left);
}

bool remove(Node*& node, int value) {
    if (!node) return false;

    if (value < node->value) return remove(node->left, value);
    if (value > node->value) return remove(node->right, value);

    if (node->is_leaf()) {
        delete node;
        node = nullptr;
        return true;
    }

    if (!node->left || !node->right) {
        Node* temp = node->left ? node->left : node->right;
        delete node;
        node = temp;
        return true;
    }

    Node*& min_node = most_left(node->right);
    node->value = min_node->value;
    return remove(min_node, min_node->value);
}

void delete_tree(Node* node) {
    if (!node) return;
    node->delete_children();
    delete node;
}


////////////////////////
 

// #include "node.hpp"
// #include <iostream>
// #include <algorithm>

// Node* create_node(int value) {
//     return new Node{value};
// }

// bool Node::is_leaf() const {
//     return !left && !right;
// }

// void Node::insert(int val) {
//     if (val < value) {
//         if (left) left->insert(val);
//         else left = create_node(val);
//     } else {
//         if (right) right->insert(val);
//         else right = create_node(val);
//     }
// }

// int Node::height() const {
//     int lh = left ? left->height() : 0;
//     int rh = right ? right->height() : 0;
//     return 1 + std::max(lh, rh);
// }

// void Node::delete_children() {
//     if (left) {
//         left->delete_children();
//         delete left;
//         left = nullptr;
//     }
//     if (right) {
//         right->delete_children();
//         delete right;
//         right = nullptr;
//     }
// }

// void Node::display_infix() const {
//     if (left) left->display_infix();
//     std::cout << value << ' ';
//     if (right) right->display_infix();
// }

// std::vector<Node const*> Node::prefix() const {
//     std::vector<Node const*> nodes;
//     nodes.push_back(this);
//     if (left) {
//         auto l = left->prefix();
//         nodes.insert(nodes.end(), l.begin(), l.end());
//     }
//     if (right) {
//         auto r = right->prefix();
//         nodes.insert(nodes.end(), r.begin(), r.end());
//     }
//     return nodes;
// }

// void delete_tree(Node* node) {
//     if (node) {
//         node->delete_children();
//         delete node;
//     }
// }
