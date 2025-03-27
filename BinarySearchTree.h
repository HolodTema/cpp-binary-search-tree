#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "QueueList.h"
#include "StackList.h"

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTree():
        root_(nullptr)
    { }

    BinarySearchTree(const BinarySearchTree<T> &other) = delete;

    BinarySearchTree(BinarySearchTree<T> &&other) noexcept: root_(other.root_)
    { }

    BinarySearchTree<T> &operator=(const BinarySearchTree<T> &src) = delete;

    BinarySearchTree<T> &operator=(BinarySearchTree<T> &&src) noexcept {
        if (this != &src) {
            root_ = src.root_;
        }
        return *this;
    }

    virtual ~BinarySearchTree() {
        auto onDeleteListener = [](const Node<T>* node)->void {
            delete node;
        };

        walkByLevels(onDeleteListener);
    }

    bool searchIterative(const T &key) const {
        return searchIterativePrivate(key) != nullptr;
    }

    bool insert(const T &key) {
        if (root_ == nullptr) {
            root_ = new Node<T>(key);
            return true;
        }

        Node<T> *currentNode = root_;
        while (currentNode != nullptr) {
            if (key == currentNode->key_) {
                return false;
            }
            else if (key < currentNode->key_) {
                if (currentNode->left_ == nullptr) {
                    currentNode->left_ = new Node<T>(key, nullptr, nullptr, currentNode);
                    return true;
                }
                currentNode = currentNode->left_;
            }
            else {
                if (currentNode->right_ == nullptr) {
                    currentNode->right_ = new Node<T>(key, nullptr, nullptr, currentNode);
                    return true;
                }
                currentNode = currentNode->right_;
            }
        }
        return false;
    }

    bool remove(const T &key) {
        Node<T> *node = searchIterativePrivate(key);
        if (node == nullptr) {
            return false;
        }

        Node<T> *parentNode = node->p_;
        delete node;

        if (key <= parentNode->key_) {
            parentNode->left_ = nullptr;
        }
        else {
            parentNode->right_ = nullptr;
        }
        return true;
    }

    void output(std::ostream &out) const {
        output(out, root_);
        if (root_ != nullptr) {
            out << '\n';
        }
    }

    int getNumberOfNodes() const {
        return getNumberOfNodes(root_);
    }

    int getHeight() const {
        return getHeight(root_);
    }

    void inorderWalkIterative(std::ostream &out) const {
        StackList<Node<T>*> stackList;
        Node<T>* node = root_;

        while (!stackList.isEmpty() || node != nullptr) {
            if (node != nullptr) {
                stackList.push(node);
                node = node->left_;
            }
            else {
                node = stackList.pop();
                out << node->key_ << ' ';
                node = node->right_;
            }
        }
        if (root_ != nullptr) {
            out << '\n';
        }
    }

    void inorderWalkIterative(void (*listener)(const T&)) const {
        StackList<Node<T>*> stackList;
        Node<T>* node = root_;

        while (!stackList.isEmpty() || node != nullptr) {
            if (node != nullptr) {
                stackList.push(node);
                node = node->left_;
            }
            else {
                node = stackList.pop();
                listener(node->key_);
                node = node->right_;
            }
        }
    }

    void inorderWalkRecursive(std::ostream &out) const {
        inorderWalkRecursive(out, root_);
        if (root_ != nullptr) {
            out << '\n';
        }
    }

    void walkByLevels(std::ostream &out) const {
        if (root_ == nullptr) {
            return;
        }

        Node<T> *nodeToPrint = nullptr;
        QueueList<Node<T>*> queueList;
        queueList.enQueue(root_);

        while (!queueList.isEmpty()) {
            nodeToPrint = queueList.deQueue();
            if (nodeToPrint->left_ != nullptr) {
                queueList.enQueue(nodeToPrint->left_);
            }
            if (nodeToPrint->right_ != nullptr) {
                queueList.enQueue(nodeToPrint->right_);
            }
            out << nodeToPrint->key_ << ' ';
        }

        out << '\n';
    }

    int countKeysInRange(const int& low, const int& high) {
        int result = 0;

        auto inorderWalkListener = [&result, &low, &high](const T& key)->void {
            if (key >= low && key <= high) {
                ++result;
            }
        };
        inorderWalkIterative(inorderWalkListener);
        return result;
    }

private:
    template<typename T1>
    struct Node {
        T1 key_;
        Node<T1> *left_;
        Node<T1> *right_;
        Node<T1> *p_;

        Node(T1 key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr): key_(key),
            left_(left),
            right_(right),
            p_(p) {
        }
    };

    Node<T> *root_;

    Node<T> *searchIterativePrivate(const T &key) const {
        Node<T> *currentNode = root_;
        while (currentNode != nullptr) {
            if (currentNode->key_ == key) {
                return currentNode;
            }
            if (key < currentNode->key_) {
                currentNode = currentNode->left_;
            }
            if (key > currentNode->key_) {
                currentNode = currentNode->right_;
            }
        }
        return nullptr;
    }

    void output(std::ostream &out, Node<T> *node) const {
        if (node == nullptr) {
            return;
        }
        out << '(' << node->key_;
        output(out, node->left_);
        output(out, node->right_);
        out << ')';
    }

    int getNumberOfNodes(const Node<T> *node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + getNumberOfNodes(node->left_) + getNumberOfNodes(node->right_);
    }

    int getHeight(const Node<T> *node) const {
        if (node == nullptr) {
            return -1;
        }
        const int heightLeft = getHeight(node->left_) + 1;
        const int heightRight = getHeight(node->right_) + 1;
        return (heightLeft >= heightRight) ? heightLeft : heightRight;
    }

    void inorderWalkRecursive(std::ostream &out, Node<T> *node) const {
        if (node == nullptr) {
            return;
        }
        inorderWalkRecursive(out, node->left_);
        out << node->key_ << ' ';
        inorderWalkRecursive(out, node->right_);
    }

    void walkByLevels(void (*listener)(const Node<T>*)) const {
        if (root_ == nullptr) {
            return;
        }

        Node<T> *nodeToPrint = nullptr;
        QueueList<Node<T>*> queueList;
        queueList.enQueue(root_);

        while (!queueList.isEmpty()) {
            nodeToPrint = queueList.deQueue();
            if (nodeToPrint->left_ != nullptr) {
                queueList.enQueue(nodeToPrint->left_);
            }
            if (nodeToPrint->right_ != nullptr) {
                queueList.enQueue(nodeToPrint->right_);
            }
            listener(nodeToPrint);
        }
    }

    void swap(BinarySearchTree &other) noexcept {
        std::swap(root_, other.root_);
    }
};

#endif //BINARY_SEARCH_TREE_H
