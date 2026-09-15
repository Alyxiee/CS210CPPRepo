// TASK 03 -- The Stack ADT's implementation
//
// This is where "how" lives. We chose std::vector as the backing
// storage: push_back is our push, back() is our top, pop_back() is our
// pop. A student could rewrite this whole file to use a raw fixed-size
// array instead, and as long as push/pop/top/isEmpty/size still behave
// the same way, nothing calling this class would ever notice.

#include "Stack.h"

void Stack::push(int value) {
    // TODO: add value to the top of data_ (vector has a method for this)

}

void Stack::pop() {
    // TODO: if data_ isn't empty, remove the top element
    if (!isEmpty()) {
        topIndex--;
    }
}

int Stack::peek() const {
    // TODO: return the top element of data_
    // undefined if empty -- callers should check isEmpty() first. We'll
    // harden this kind of thing later in the course.
}

bool Stack::isEmpty() const {
    // TODO: return whether data_ has zero elements
}

int Stack::size() const {
    // TODO: return how many elements are in data_ (cast to int)
}
