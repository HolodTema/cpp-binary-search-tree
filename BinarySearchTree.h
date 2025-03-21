#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <iostream>

template <class T>
class BinarySearchTree
{
public:

    BinarySearchTree() {

    }

    BinarySearchTree(const BinarySearchTree<T> & other) = delete;

    BinarySearchTree(BinarySearchTree<T>&& other) noexcept:
        root_(other.root_)
    {

    }

    BinarySearchTree <T>& operator=(const BinarySearchTree <T>& src) = delete;

    BinarySearchTree <T>& operator=(BinarySearchTree <T>&& src) noexcept {

    }

    virtual ~BinarySearchTree() {
        Node<T> node = root_;
        while(root_ != nullptr) {
            while(node->left_ != nullptr) {
                node = node.left_;
                while(node.right_ != nullptr) {
                    node = node.right_;
                }
                const Node<T>* nodeToDelete = node;
                node = node->p_;
                delete nodeToDelete;
            }
        }
    }

    // 1.1 Функция поиска по ключу в бинарном дереве поиска
    bool searchIterative (const T& key) const {
        Node<T>* currentNode = root_;
        while (currentNode != nullptr) {
            if (key == currentNode->key_) {
                return true;
            }
            else if (key < currentNode->key_) {
                currentNode = currentNode->left_;
            }
            else {
                currentNode = currentNode->right_;
            }
        }
        return false;
    }

    // 2 Вставка нового элемента в дерево: true, если элемент добавлен;
    // false, если элемент уже был
    bool insert(const T& key) {
        if (root_ == nullptr) {
            root_ = new Node<T>(key);
            return true;
        }

        Node<T>* currentNode = root_;
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

    // 3.1 Удаление элемента c заданным ключом, не нарушающее порядок элементов
    // true, если элемент удален; false, если элемента не было
    bool remove(const T& key) {

    }

    // 4.1 Вывод структуры (строкового изображения дерева) в выходной поток out,
    // использовать скобки, чтобы показать структуру дерева
    void output(std::ostream& out) const {

    }

    // 5.1 Определение количества узлов дерева
    int getNumberOfNodes () const {
        return getNumberOfNodes(root_);
    }

    // 6.1 Определение высоты дерева
    int getHeight() const {

    }

    // 7 Инфиксный обход дерева (итеративный)
    void inorderWalkIterative () const;

    // 8.1 Инфиксный обход дерева (рекурсивный)
    void inorderWalk() const;

    // 9 Обход двоичного дерева по уровням (в ширину).
    void walkByLevels() const;

private:
    template <class T1>
        struct Node {
        T1 key_; // значение ключа, содержащееся в узле
        Node<T1> *left_; // указатель на левое поддерево
        Node<T1> *right_; // указатель на правое поддерево
        Node<T1> *p_; // указатель на родителя !!! не используется

        // Конструктор узла
        Node(T1 key, Node *left = nullptr, Node *right= nullptr, Node *p =nullptr):
        key_(key), left_ (left), right_(right), p_(p)
        { }

    };

    Node<T>* root_; // Указатель на корневой узел

    //можно использовать внутри remove
    //он правильно переименован, так как иначе перегрузка методов не получается. Ибо возврат значение не явл частью сигнатуры
    //правильно переименовал
    Node<T>* searchIterativePrivate(const T& key) const {

    }

    // 4.2 Рекурсивная функция для вывода структуры дерева в выходной поток
    void output(std::ostream& out, Node<T>* root) const {

    }

    // 5.2 Рекурсивная функция определения количества узлов дерева
    int getNumberOfNodes(const Node<T>* node) const {
        if (node->right_ == nullptr && node->left_ == nullptr) {
            return 1;
        }
        if (node->right_ == nullptr && node->left_ != nullptr) {
            return getNumberOfNodes(node->left_) + 1;
        }
        if (node->left_ == nullptr && node->right_ != nullptr) {
            return getNumberOfNodes(node->right_) + 1;
        }
        return getNumberOfNodes(node->left_) + getNumberOfNodes(node->right_) + 1;
    }

    // 6.2 Рекурсивная функция определения высоты дерева
    int getHeight(const Node<T>* node) const {

    }

    // 8.2 Рекурсивная функция для инфиксного обхода узлов дерева.
    void inorderWalk(Node<T>* node) const {

    }

    void swap(BinarySearchTree& other) noexcept {
        std::swap(root_, other.root_);
    }
};

#endif //_BINARY_SEARCH_TREE_H

//строгая гарантия безопасности
//
