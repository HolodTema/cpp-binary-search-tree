#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <iostream>
#include "Queue.h"
#include "queueExceptions.h"

template <class T>
class QueueList: public Queue<T> {
public:
    QueueList() = default;

    QueueList(const QueueList& other) {
        if (other.head_ != nullptr) {
            head_ = new Node(other.head_->data, nullptr);

            Node* node = head_;
            Node* otherNode = other.head_->nextNode;

            try {
                while (otherNode != nullptr) {
                    node->nextNode = new Node(otherNode->data, nullptr);
                    otherNode = otherNode->nextNode;
                    node = node->nextNode;
                }
            }
            catch (const std::bad_alloc& e) {
                while (head_->nextNode != nullptr) {
                    const Node* exHead = head_;
                    head_ = head_->nextNode;
                    delete exHead;
                }
                delete head_;
            }

        }
    }

    QueueList(const QueueList&& other) noexcept:
        head_(other.head_)
    {

    }

    ~QueueList() override {
        if (head_ != nullptr) {
            while (head_->nextNode != nullptr) {
                const Node* exHead = head_;
                head_ = head_->nextNode;
                delete exHead;
            }
            delete head_;
        }
    }

    QueueList& operator=(const QueueList& other) {
        if (&other != this) {
            QueueList otherCopy(other);
            swap(otherCopy);
        }
        return *this;
    }

    QueueList& operator=(QueueList&& other) noexcept {
        if (&other != this) {
            head_ = other.head_;
        }
        return *this;
    }

    T deQueue() override {
        if (head_ == nullptr) {
            throw QueueUnderflow();
        }

        T result = head_->data;
        const Node* exHead = head_;
        head_ = head_->nextNode;
        delete exHead;
        return result;
    }

    void enQueue(const T& element) override {
        if (head_ == nullptr) {
            head_ = new Node(element, nullptr);
            return;
        }

        Node* lastNode = head_;
        while (lastNode->nextNode != nullptr) {
            lastNode = lastNode->nextNode;
        }
        lastNode->nextNode = new Node(element, nullptr);
    }

    bool isEmpty() override {
        return head_ == nullptr;
    }

    template <typename T1>
    friend std::ostream& operator<<(std::ostream& os, const QueueList<T1>& queue);

private:
    struct Node {
        T data;
        Node* nextNode;

        Node(T data, Node* nextNode):
            data(data),
            nextNode(nextNode)
        { }
    };

    Node* head_ = nullptr;

    void swap(QueueList& other) noexcept {
        std::swap(head_, other.head_);
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const QueueList<T>& queue) {
    std::cout << "head-> ";
    auto node = queue.head_;
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->nextNode;
    }
    std::cout << "<-tail\n";
    return os;
}
#endif //QUEUE_LIST_H
