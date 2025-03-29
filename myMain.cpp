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
    std::cout << '\n';

    bool isRemoved = tree.remove(3);
    std::cout << "Remove element 3: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(15);
    std::cout << "Remove element 15: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(10);
    std::cout << "Remove element 10: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(8);
    std::cout << "Remove element 8: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(7);
    std::cout << "Remove element 7: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(20);
    std::cout << "Remove element 20: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(1);
    std::cout << "Remove element 1: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(25);
    std::cout << "Remove element 25: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(5);
    std::cout << "Remove element 5: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';
    std::cout << "##################\n";
}

void checkRemoveInsert() {
    std::cout << "##################\n";
    std::cout << "TEST: check remove and insert\n";
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
    std::cout << '\n';

    bool isRemoved = tree.remove(3);
    std::cout << "Remove element 3: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    bool isInserted = tree.insert(2);
    std::cout << "Insert element 2: " << isInserted << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(10);
    std::cout << "Remove element 10: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isRemoved = tree.remove(20);
    std::cout << "Remove element 20: " << isRemoved << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isInserted = tree.insert(9);
    std::cout << "Insert element 9: " << isInserted << "\n";
    tree.output(std::cout);
    std::cout << '\n';

    isInserted = tree.insert(17);
    std::cout << "Insert element 17: " << isInserted << "\n";
    tree.output(std::cout);
    std::cout << '\n';
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

void checkNumberOfNodes() {
    std::cout << "##################\n";
    std::cout << "TEST: check number of nodes\n";
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
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 30 0 -2 17\n";
    tree.insert(30);
    tree.insert(0);
    tree.insert(-2);
    tree.insert(17);
    tree.output(std::cout);
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";
    std::cout << "\n";

    std::cout << "Delete elements 10 7\n";
    tree.remove(10);
    tree.remove(7);
    tree.output(std::cout);
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";
    std::cout << "##################\n";
}

void checkNumberOfNodesEmptyTree() {
    std::cout << "##################\n";
    std::cout << "TEST: check number of nodes in empty tree\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.output(std::cout);
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 5 100 40 70\n";
    tree.insert(5);
    tree.insert(100);
    tree.insert(40);
    tree.insert(70);
    tree.output(std::cout);
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";
    std::cout << "\n";

    std::cout << "Delete elements 100\n";
    tree.remove(100);
    tree.output(std::cout);
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";
    std::cout << "##################\n";
}

void checkHeight() {
    std::cout << "##################\n";
    std::cout << "TEST: check height\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.output(std::cout);
    std::cout << "Height: " << tree.getHeight() << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 10:\n";
    tree.insert(10);
    tree.output(std::cout);
    std::cout << "Height: " << tree.getHeight() << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 5 20 3\n";
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.output(std::cout);
    std::cout << "Height: " << tree.getHeight() << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 7 25 15 1 8\n";
    tree.insert(7);
    tree.insert(25);
    tree.insert(15);
    tree.insert(1);
    tree.insert(8);
    tree.output(std::cout);
    std::cout << "Height: " << tree.getHeight() << "\n";
    std::cout << "##################\n";
}

void checkInorderWalkIterative() {
    std::cout << "##################\n";
    std::cout << "TEST: check inorder walk iterative\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.inorderWalkIterative(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 40 0 60:\n";
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.inorderWalkIterative(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 50 35 20 -3:\n";
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.inorderWalkIterative(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 100 58 7:\n";
    tree.insert(100);
    tree.insert(58);
    tree.insert(7);
    tree.inorderWalkIterative(std::cout);
    std::cout << "\n";
    std::cout << "##################\n";
}

void checkInorderWalkRecursive() {
    std::cout << "##################\n";
    std::cout << "TEST: check inorder walk recursive\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.inorderWalkRecursive(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 40 0 60:\n";
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.inorderWalkRecursive(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 50 35 20 -3:\n";
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.inorderWalkRecursive(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 100 58 7:\n";
    tree.insert(100);
    tree.insert(58);
    tree.insert(7);
    tree.inorderWalkRecursive(std::cout);
    std::cout << "\n";
    std::cout << "##################\n";
}

void checkInorderWalkIterativeListener() {
    auto listener = [](const int& key)->bool {
        std::cout << key << "\n";
        return true;
    };

    std::cout << "##################\n";
    std::cout << "TEST: check inorder walk iterative listener\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.inorderWalkIterative(listener);
    std::cout << "\n";

    std::cout << "Insert elements 40 0 60:\n";
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.inorderWalkIterative(listener);
    std::cout << "\n";

    std::cout << "Insert elements 50 35 20 -3:\n";
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.inorderWalkIterative(listener);
    std::cout << "\n";

    std::cout << "Insert elements 100 58 7:\n";
    tree.insert(100);
    tree.insert(58);
    tree.insert(7);
    tree.inorderWalkIterative(listener);
    std::cout << "\n";
    std::cout << "##################\n";
}

void checkWalkByLevels() {
    std::cout << "##################\n";
    std::cout << "TEST: check walk by levels\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.walkByLevels(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 40 0 60:\n";
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.walkByLevels(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 50 35 20 -3:\n";
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.walkByLevels(std::cout);
    std::cout << "\n";

    std::cout << "Insert elements 100 58 7:\n";
    tree.insert(100);
    tree.insert(58);
    tree.insert(7);
    tree.walkByLevels(std::cout);
    std::cout << "\n";
    std::cout << "##################\n";
}

void checkCountKeysInRange() {
    std::cout << "##################\n";
    std::cout << "TEST: check count keys in range\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRange(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 40 0 60:\n";
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRange(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 50 35 20 -3:\n";
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRange(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 100 58 7:\n";
    tree.insert(100);
    tree.insert(58);
    tree.insert(7);
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRange(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 30 -9 200:\n";
    tree.insert(30);
    tree.insert(-9);
    tree.insert(-8);
    tree.insert(200);
    tree.output(std::cout);
    std::cout << "Count keys in [-500; 1000]: " << tree.countKeysInRange(-500, 1000) << "\n";
    std::cout << "\n";

    std::cout << "Count keys in [37; 59]: " << tree.countKeysInRange(37, 59) << "\n";
    std::cout << "\n";
    std::cout << "##################\n";
}

void checkCountKeysInRangeException() {
    std::cout << "##################\n";
    std::cout << "TEST: check count keys in range exception\n";
    std::cout << "Created tree with elements 40 0 60 50 35 20 -3 100\n";
    BinarySearchTree<int> tree;
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.insert(100);
    tree.output(std::cout);
    try {
        std::cout << "Count keys in [100; 0] (must be error): " << tree.countKeysInRange(100, 0) << "\n";
    }
    catch(std::invalid_argument& e) {
        std::cout << e.what();
    }
    std::cout << "##################\n";
}

void checkCountKeysInRangeNoOptimized() {
    std::cout << "##################\n";
    std::cout << "TEST: check count keys in range (no optimized)\n";
    std::cout << "Created empty tree\n";
    BinarySearchTree<int> tree;
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRangeNoOptimized(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 40 0 60:\n";
    tree.insert(40);
    tree.insert(0);
    tree.insert(60);
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRangeNoOptimized(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 50 35 20 -3:\n";
    tree.insert(50);
    tree.insert(35);
    tree.insert(20);
    tree.insert(-3);
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRangeNoOptimized(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 100 58 7:\n";
    tree.insert(100);
    tree.insert(58);
    tree.insert(7);
    tree.output(std::cout);
    std::cout << "Count keys in [15; 50]: " << tree.countKeysInRangeNoOptimized(15, 50) << "\n";
    std::cout << "\n";

    std::cout << "Insert elements 30 -9 200:\n";
    tree.insert(30);
    tree.insert(-9);
    tree.insert(200);
    tree.output(std::cout);
    std::cout << "Count keys in [-500; 1000]: " << tree.countKeysInRangeNoOptimized(-500, 1000) << "\n";
    std::cout << "\n";

    std::cout << "Count keys in [37; 59]: " << tree.countKeysInRangeNoOptimized(37, 59) << "\n";
    std::cout << "\n";
    std::cout << "##################\n";
}



void myTests() {
    checkInsert();

    checkRemove();
    checkRemoveAll();
    checkRemoveInsert();

    checkOutput();

    checkSearch();

    checkNumberOfNodes();
    checkNumberOfNodesEmptyTree();

    checkHeight();

    checkInorderWalkIterative();
    checkInorderWalkIterativeListener();
    checkInorderWalkRecursive();

    checkWalkByLevels();

    checkCountKeysInRange();
    checkCountKeysInRangeNoOptimized();
}

int main() {
    // oldMainFile();

    myTests();
    return 0;
}
