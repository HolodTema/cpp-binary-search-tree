#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree<int> getTree()
{
    BinarySearchTree<int> tree;

    tree.insert(15);
    tree.insert(10);
    tree.insert(7);
    tree.insert(11);
    tree.insert(25);

    return tree;
}

void fillTree(BinarySearchTree<int>& tree)
{
    tree.insert(15);
    tree.insert(10);
    tree.insert(7);
    tree.insert(11);
    tree.insert(13);
    tree.insert(8);
    tree.insert(5);
    tree.insert(25);
    tree.insert(21);
    tree.insert(27);
    tree.insert(30);
    tree.insert(18);
    tree.insert(23);
}

void moveTest()
{
    std::cout << "--moveTest begin--\n";

    BinarySearchTree<int> tree1 = getTree();
    tree1.output(std::cout);
    std::cout << '\n';

    BinarySearchTree<int> tree2;
    tree2.insert(30);
    tree2.insert(20);
    tree2.insert(40);
    tree2 = getTree();
    tree2.output(std::cout);
    std::cout << '\n';

    std::cout << "--moveTest end--\n";
}

void insertTest()
{
    std::cout << "--insertTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    tree.output(std::cout);
    std::cout << '\n';

    if (!tree.insert(23))
    {
        std::cout << "already exists\n";
    }
    if (!tree.insert(10))
    {
        std::cout << "already exists\n";
    }

    if (tree.insert(35))
    {
        std::cout << "inserted\n";
    }

    tree.output(std::cout);
    std::cout << '\n';

    std::cout << "--insertTest end--\n";
}

void deleteTest()
{
    std::cout << "--deleteTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    if (tree.remove(18))
    {
        std::cout << "deleted\n";
    }
    if (tree.remove(10))
    {
        std::cout << "deleted\n";
    }
    if (tree.remove(15))
    {
        std::cout << "deleted\n";
    }

    if (!tree.remove(100))
    {
        std::cout << "not found\n";
    }

    std::cout << "--deleteTest end--\n";
}

void deleteDetailTest()
{
    std::cout << "--deleteDetailTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    tree.output(std::cout);
    std::cout << '\n';

    tree.remove(18);
    tree.output(std::cout);
    std::cout << '\n';

    tree.remove(10);
    tree.output(std::cout);
    std::cout << '\n';

    tree.remove(15);
    tree.output(std::cout);
    std::cout << '\n';

    std::cout << "--deleteDetailTest end--\n";
}

void searchTest()
{
    std::cout << "--searchTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    if (tree.searchIterative(18))
    {
        std::cout << "found\n";
    }
    if (tree.searchIterative(7))
    {
        std::cout << "found\n";
    }
    if (tree.searchIterative(15))
    {
        std::cout << "found\n";
    }

    if (!tree.searchIterative(100))
    {
        std::cout << "not found\n";
    }

    std::cout << "--searchTest end--\n";
}

void heightAndCountTest()
{
    std::cout << "--heightAndCountTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    std::cout << "count: " << tree.getNumberOfNodes() << '\n';
    std::cout << "height: " << tree.getHeight() << '\n';

    tree.insert(35);

    std::cout << "count: " << tree.getNumberOfNodes() << '\n';
    std::cout << "height: " << tree.getHeight() << '\n';

    std::cout << "--heightAndCountTest end--\n";
}

void emptyTreeTest()
{
    std::cout << "--emptyTreeTest begin--\n";

    BinarySearchTree<int> tree;

    if (!tree.searchIterative(100))
    {
        std::cout << "not found\n";
    }
    std::cout << "count: " << tree.getNumberOfNodes() << '\n';
    std::cout << "height: " << tree.getHeight() << '\n';
    if (!tree.remove(100))
    {
        std::cout << "not found\n";
    }

    std::cout << "--emptyTreeTest end--\n";
}

void inorderWalkTest()
{
    std::cout << "--inorderWalkTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    tree.inorderWalkRecursive(std::cout);
    std::cout << '\n';

    std::cout << "--inorderWalkTest end--\n";
}

void inorderWalkIterativeTest()
{
    std::cout << "--inorderWalkIterativeTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    tree.inorderWalkIterative(std::cout);
    std::cout << '\n';

    std::cout << "--inorderWalkIterativeTest end--\n";
}

void walkByLevelsTest()
{
    std::cout << "--walkByLevelsTest begin--\n";

    BinarySearchTree<int> tree;

    fillTree(tree);

    tree.walkByLevels(std::cout);
    std::cout << '\n';

    std::cout << "--walkByLevelsTest end--\n";
}

void similarTest()
{
    // Если нет в вашем варианте, замените на
    std::cout << "not implemented\n";

    // std::cout << "--similarTest begin--\n";
    //
    // BinarySearchTree<int> first;
    //
    // first.insert(10);
    // first.insert(6);
    // first.insert(8);
    // first.insert(1);
    // first.insert(15);
    // first.insert(12);
    // first.insert(14);
    // first.insert(17);
    //
    // BinarySearchTree<int> second;
    //
    // second.insert(15);
    // second.insert(17);
    // second.insert(12);
    // second.insert(14);
    // second.insert(10);
    // second.insert(8);
    // second.insert(6);
    // second.insert(1);
    //
    // // true
    // std::cout << "similar: " << first.isSimilar(second) << '\n';
    //
    // second.remove(17);
    // // false
    // std::cout << "similar: " << first.isSimilar(second) << '\n';
    //
    // first.remove(17);
    // // true
    // std::cout << "similar: " << first.isSimilar(second) << '\n';
    //
    // first.remove(12);
    // // false
    // std::cout << "similar: " << first.isSimilar(second) << '\n';
    //
    //
    // // with empty tree
    // std::cout << "similar: " << first.isSimilar(BinarySearchTree<int>()) << '\n';
    // std::cout << "similar: " << BinarySearchTree<int>().isSimilar(second) << '\n';
    //
    // std::cout << "--similarTest end--\n";
}

void identicalTest()
{
    // Если нет в вашем варианте, замените на
    std::cout << "not implemented\n";

    // std::cout << "--identicalTest begin--\n";
    //
    // BinarySearchTree<int> first;
    //
    // first.insert(10);
    // first.insert(6);
    // first.insert(8);
    // first.insert(1);
    // first.insert(15);
    // first.insert(12);
    // first.insert(14);
    // first.insert(17);
    //
    // BinarySearchTree<int> second;
    //
    // second.insert(9);
    // second.insert(11);
    // second.insert(16);
    // second.insert(13);
    // second.insert(7);
    // second.insert(5);
    // second.insert(4);
    //
    // // false
    // std::cout << "equal keys: " << first.isIdenticalKey(second) << '\n';
    // std::cout << "equal keys: " << second.isIdenticalKey(first) << '\n';
    //
    // BinarySearchTree<int> third;
    // third.insert(9);
    // third.insert(11);
    // third.insert(16);
    // third.insert(15);  // !
    // third.insert(7);
    // third.insert(5);
    // third.insert(4);
    //
    // // true
    // std::cout << "equal keys: " << first.isIdenticalKey(third) << '\n';
    // std::cout << "equal keys: " << third.isIdenticalKey(first) << '\n';
    //
    // // with empty tree
    // std::cout << "equal keys: " << first.isIdenticalKey(BinarySearchTree<int>()) << '\n';
    // std::cout << "equal keys: " << BinarySearchTree<int>().isIdenticalKey(first) << '\n';
    //
    // std::cout << "--identicalTest end--\n";
}

int main()
{
    int i = 0;
    std::cin >> i;
    switch (i)
    {
    case 1:
        moveTest();
        break;
    case 2:
        insertTest();
        break;
    case 3:
        deleteTest();
        break;
    case 4:
        deleteDetailTest();
        break;
    case 5:
        searchTest();
        break;
    case 6:
        heightAndCountTest();
        break;
    case 7:
        emptyTreeTest();
        break;
    case 8:
        inorderWalkTest();
        break;
    case 9:
        inorderWalkIterativeTest();
        break;
    case 10:
        walkByLevelsTest();
        break;
    case 11:
        similarTest();
        break;
    case 12:
        identicalTest();
        break;
    }

    return 0;
}