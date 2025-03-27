#ifndef STACK_EXCEPTIONS_H
#define STACK_EXCEPTIONS_H

#include <stdexcept>

class StackUnderflow final: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: stack underflow.\n";
    }
};

#endif //STACK_EXCEPTIONS_H
