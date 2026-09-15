// TASK 03 -- The Stack ADT's implementation
//
// This is where "how" lives. We chose std::vector as the backing
// storage: push_back is our push, back() is our top, pop_back() is our
// pop. A student could rewrite this whole file to use a raw fixed-size
// array instead, and as long as push/pop/top/isEmpty/size still behave
// the same way, nothing calling this class would ever notice.

#include "Stack.h"

#include <iostream>
#include <ostream>

void Stack::push(const int value) {
    // TODO: add value to the top of data_ (vector has a method for this)

    if (!isFull()) {
        topIndex++;
        data[topIndex] = value;
    } else {
        std::cout << "Stack is full" << std::endl;
    }


}

void Stack::pop() {
    // TODO: if data_ isn't empty, remove the top element
    if (!isEmpty()) {
        topIndex--;
        return;
    }
    std::cout << "Stack is empty" << std::endl;
}

int Stack::peek() const {
    // TODO: return the top element of data_
    // undefined if empty -- callers should check isEmpty() first. We'll
    // harden this kind of thing later in the course.
    if (!isEmpty()) {
        return data[topIndex];
    }
    std::cout << "Stack is empty" << std::endl;
    return -1;
}

bool Stack::isEmpty() const {
    // TODO: return whether data_ has zero elements
    if (topIndex == -1) {
        return true;
    }
    return false;
}

int Stack::size() const {
    // TODO: return how many elements are in data_ (cast to int)
    return topIndex + 1;
}

bool Stack::isFull() const {
    if (topIndex == 101) {
        return true;
    }
    return false;
}
