#include "node.hpp"
#include <iostream>

int main() {
    Node* root = create_node(10);
    root->insert(5);
    root->insert(15);
    root->insert(3);
    root->insert(7);
    root->insert(13);
    root->insert(17);

    std::cout << "Infix: ";
    root->display_infix();
    std::cout << "\nHeight: " << root->height() << '\n';

    std::cout << "Prefix: ";
    for (const auto* node : root->prefix()) std::cout << node->value << " ";

    remove(root, 15);
    std::cout << "After remove 15, infix: ";
    root->display_infix();
    std::cout << '\n';

    delete_tree(root);
    return 0;
}

////////////////////////

// #include "node.hpp"
// #include <iostream>

// int main() {
//     Node* root = create_node(5);
//     for (int val : {3, 7, 2, 4, 6, 8, 1, 9, 0}) {
//         root->insert(val);
//     }

//     std::cout << "Infix order: ";
//     root->display_infix();
//     std::cout << '\n';

//     int sum = 0;
//     for (auto node : root->prefix()) {
//         sum += node->value;
//     }
//     std::cout << "Sum: " << sum << '\n';

//     std::cout << "Height: " << root->height() << '\n';

//     delete_tree(root);
//     return 0;
// }
