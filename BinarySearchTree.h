#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <functional>
#include <stdexcept>
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
            if (key < currentNode->key_) {
                if (currentNode->left_ == nullptr) {
                    currentNode->left_ = new Node<T>(key, nullptr, nullptr, currentNode);
                    return true;
                }
                currentNode = currentNode->left_;
                continue;
            }
            if (key > currentNode->key_) {
                if (currentNode->right_ == nullptr) {
                    currentNode->right_ = new Node<T>(key, nullptr, nullptr, currentNode);
                    return true;
                }
                currentNode = currentNode->right_;
                continue;
            }
        }
        return false;
    }

    bool remove(const T &key) {
        Node<T> *node = searchIterativePrivate(key);
        if (node == nullptr) {
            return false;
        }

        if (node->left_ == nullptr && node->right_ == nullptr) {
            if (node->p_ != nullptr)  {
                if (node->p_->right_ == node) {
                    node->p_->right_ = nullptr;
                }
                if (node->p_->left_ == node) {
                    node->p_->left_ = nullptr;
                }
            }
            else {
                root_ = nullptr;
            }
            delete node;
            return true;
        }

        if (node->left_ != nullptr && node->right_ == nullptr) {
            if (node->p_ != nullptr) {
                if (node->p_->left_ == node) {
                    node->p_->left_ = node->left_;
                }
                if (node->p_->right_ == node) {
                    node->p_->right_ = node->left_;
                }
                node->left_->p_ = node->p_;
            }
            else {
                root_ = node->left_;
                root_->p_ = nullptr;
            }
            delete node;
            return true;
        }

        if (node->left_ == nullptr && node->right_ != nullptr) {
            if (node->p_ != nullptr) {
                if (node->p_->left_ == node) {
                    node->p_->left_ = node->right_;
                }
                if (node->p_->right_ == node) {
                    node->p_->right_ = node->right_;
                }
                node->right_->p_ = node->p_;
            }
            else {
                root_ = node->right_;
                root_->p_ = nullptr;
            }
            delete node;
            return true;
        }

        if (node->left_ != nullptr && node->right_ != nullptr) {
            Node<T>* successor = getInorderSuccessor(node);
            node->key_ = successor->key_;

            //now it is time to delete successor
            //it could be great to use recursion, but it is forbidden by task conditions
            if (successor->left_ == nullptr && successor->right_ == nullptr) {
                //here successor has parent, because here successor is not the ancestor of the node
                if (successor->p_->left_ == successor) {
                    successor->p_->left_ = nullptr;
                }
                if (successor->p_->right_ == successor) {
                    successor->p_->right_ = nullptr;
                }
                delete successor;
                return true;
            }
            else {
                //here successor has only right child, because in remove() method successor cannot be node's ancestor
                //so, here successor is node's descendant and it has parent.
                if (successor->p_->left_ == successor) {
                    successor->p_->left_ = successor->right_;
                }
                if (successor->p_->right_ == successor) {
                    successor->p_->right_ = successor->right_;
                }
                successor->right_->p_ = successor->p_;
                delete successor;
                return true;
            }
        }

        return false;
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

    void inorderWalkIterative(std::function<bool(const T&)> listener) const {
        StackList<Node<T>*> stackList;
        Node<T>* node = root_;

        while (!stackList.isEmpty() || node != nullptr) {
            if (node != nullptr) {
                stackList.push(node);
                node = node->left_;
            }
            else {
                node = stackList.pop();
                bool needRunning = listener(node->key_);
                if (!needRunning) {
                    break;
                }
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

    int countKeysInRangeNoOptimized(const int& low, const int& high) const {
        if (low > high) {
            throw std::invalid_argument("Error: low must be <= high.\n");
        }
        int result = 0;

        auto inorderWalkListener = [&result, low, high](const T& key)->bool {
            if (key >= low && key <= high) {
                ++result;
            }
            return key <= high;
        };

        std::function<bool(const T&)> listenerPointer = inorderWalkListener;
        inorderWalkIterative(listenerPointer);
        return result;
    }

    int countKeysInRange(const int& low, const int& high) const {
        if (low > high) {
            throw std::invalid_argument("Error: low must be <= high.\n");
        }
        Node<T>* node = root_;
        while (node != nullptr) {
            if (low == node->key_) {
                break;
            }
            if (low < node->key_) {
                if (node->left_ == nullptr) {
                    break;
                }
                node = node->left_;
            }
            if (low > node->key_) {
                if (node->right_ == nullptr) {
                    break;
                }
                node = node->right_;
            }
        }

        int result = 0;
        while (node != nullptr && node->key_ <= high) {
            if (node->key_ >= low && node->key_ <= high) {
                ++result;
            }
            node = getInorderSuccessor(node);
        }
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
                continue;
            }
            if (key > currentNode->key_) {
                currentNode = currentNode->right_;
                continue;
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

    Node<T>* getInorderSuccessor(Node<T>* node) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->right_ != nullptr) {
            node = node->right_;
            while (node->left_ != nullptr) {
                node = node->left_;
            }
            return node;
        }
        else {
            Node<T>* nodeAncestor = node->p_;
            while(nodeAncestor != nullptr) {
                if (nodeAncestor->key_ > node->key_) {
                    return nodeAncestor;
                }
                nodeAncestor = nodeAncestor->p_;
            }
        }
        return nullptr;
    }

    void swap(BinarySearchTree &other) noexcept {
        std::swap(root_, other.root_);
    }
};

#endif //BINARY_SEARCH_TREE_H
