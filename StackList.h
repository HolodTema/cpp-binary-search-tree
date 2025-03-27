#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>
#include "Stack.h"
#include "stackExceptions.h"

template<class T>
class StackList: public Stack<T> {
public:

    StackList() = default;

    StackList(const StackList &other) = delete;

    StackList(const StackList &&other) noexcept:
        head_(other.head_)
    { }

    ~StackList() override {
        while (head_ != nullptr) {
            Node* node = head_;
            head_ = head_->prevNode;
            delete node;
        }
    }

    StackList& operator=(const StackList &other) = delete;

    StackList& operator=(StackList &&other) noexcept {
        if (this != &other) {
            head_ = other.head_;
        }
        return *this;
    }

    void push(const T &element) override {
        Node* prevHead = head_;
        head_ = new Node(element, prevHead);
    }

    T pop() override {
        if (head_ == nullptr) {
            throw StackUnderflow();
        }
        T result = head_->data;
        head_ = head_->prevNode;
        return result;
    }

    bool isEmpty() const override {
        return head_ == nullptr;
    }

private:
    struct Node {
        T data;
        Node* prevNode;

        Node(T data, Node* prevNode):
            data(data),
            prevNode(prevNode)
        { }
    };

    Node* head_ = nullptr;

    void swap(StackList& other) noexcept {
        std::swap(head_, other.head_);
    }
};

#endif //STACK_LIST_H
