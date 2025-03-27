#include <iostream>
#include "BinarySearchTree.h"

void oldMainFile() {
    BinarySearchTree<int> tree;

    tree.insert(15);
    tree.insert(23);
    if (tree.insert(13))
    {
        std::cout << "inserted\n";
    }

    tree.output(std::cout);   // (15(13)(23))
    std::cout << '\n';
    std::cout << "count: " << tree.getNumberOfNodes() << '\n';
    std::cout << "height: " << tree.getHeight() << '\n';

    if (!tree.searchIterative(100))
    {
        std::cout << "not found\n";
    }

    if (!tree.remove(100))
    {
        std::cout << "not found\n";
    }

    tree.inorderWalkRecursive(std::cout);
    std::cout << '\n';
    tree.inorderWalkIterative(std::cout);
    std::cout << '\n';
    tree.walkByLevels(std::cout);
    std::cout << '\n';
}

int main() {
    oldMainFile();
    return 0;
}
