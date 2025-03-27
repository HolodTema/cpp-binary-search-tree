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

void checkInsert() {
    std::cout << "##################\n";
    std::cout << "TEST: check insert\n";
    std::cout << "Created tree from bundle 8 5 3 7 10\n";
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.output(std::cout);
    std::cout << "\n";

    std::cout << "Add 4: " << tree.insert(4) << "\n";
    tree.output(std::cout);
    std::cout << "\n";

    std::cout << "Add 12: " << tree.insert(12) << "\n";
    tree.output(std::cout);
    std::cout << "\n";

    std::cout << "Add 2: " << tree.insert(2) << "\n";
    tree.output(std::cout);
    std::cout << "\n";

    std::cout << "Add 12: " << tree.insert(12) << "\n";
    tree.output(std::cout);
    std::cout << "##################\n";
}

void checkRemove() {
    std::cout << "##################\n";
    std::cout << "TEST: check remove\n";
    std::cout << "Created tree from bundle 8 5 3 7 10\n";
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.output(std::cout);
    std::cout << '\n';

    bool isRemoved = tree.remove(3);
    std::cout << "Remove element 3: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(200);
    std::cout << "Remove element 200: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(7);
    std::cout << "Remove element 7: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << "##################\n";
}

void checkRemoveAll() {
    std::cout << "##################\n";
    std::cout << "TEST: check remove all\n";
    std::cout << "Created tree from bundle 8 5 3 7 10\n";
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.output(std::cout);
    std::cout << '\n';

    bool isRemoved = tree.remove(3);
    std::cout << "Remove element 3: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(200);
    std::cout << "Remove element 200: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(7);
    std::cout << "Remove element 7: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << "##################\n";
}

void checkOutput() {
    std::cout << "##################\n";
    std::cout << "TEST: check output\n";
    std::cout << "Created tree from bundle 12 11 13 5 6 20 8\n";
    BinarySearchTree<int> tree;
    tree.insert(12);
    tree.insert(11);
    tree.insert(13);
    tree.insert(5);
    tree.insert(6);
    tree.insert(20);
    tree.insert(8);

    tree.output(std::cout);
    std::cout << "##################\n";
}

void checkOutputEmptyTree() {
    std::cout << "##################\n";
    std::cout << "TEST: check output empty tree\n";
    std::cout << "Created empty tree:\n";
    BinarySearchTree<int> tree;
    tree.output(std::cout);
    std::cout << "##################\n";
}

void checkSearch() {
    std::cout << "##################\n";
    std::cout << "TEST: check search\n";
    std::cout << "Created tree from bundle 10 5 20 3 7 25 15 1 8\n";
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(25);
    tree.insert(15);
    tree.insert(1);
    tree.insert(8);
    tree.output(std::cout);

    std::cout << "Try to find 25 in tree: " << tree.searchIterative(25) << "\n";
    std::cout << "Try to find 0 in tree: " << tree.searchIterative(0) << "\n";
    std::cout << "Try to find 7 in tree: " << tree.searchIterative(7) << "\n";
    std::cout << "Try to find 1000 in tree: " << tree.searchIterative(1000) << "\n";
    std::cout << "##################\n";
}

void checkGetInorderSuccessor() {
    std::cout << "##################\n";
    std::cout << "TEST: check inorder successor\n";
    std::cout << "Created tree from bundle 10 5 20 3 7 25 15 1 8\n";
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(25);
    tree.insert(15);
    tree.insert(1);
    tree.insert(8);
    tree.output(std::cout);

    int successor = tree.getInorderSuccessor(7); //it is 8
    std::cout << "7 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(10); //it is 15
    std::cout << "10 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(25); //-1
    std::cout << "25 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(8); //it is 10
    std::cout << "8 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(5); //it is 7
    std::cout << "5 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(3); //it is 5
    std::cout << "3 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(20); //it is 25
    std::cout << "20 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(1); //it is 3
    std::cout << "1 successor = " << successor << "\n";

    successor = tree.getInorderSuccessor(15); //it is 20
    std::cout << "15 successor = " << successor << "\n";
    std::cout << "##################\n";
}

void myTests() {
    checkInsert();
    checkRemove();
    checkOutput();
    checkSearch();
}

int main() {
    // oldMainFile();

    // myTests();

    checkGetInorderSuccessor();
    return 0;
}
