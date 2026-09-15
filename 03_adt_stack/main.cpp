// TASK 03 -- Using the Stack ADT
//
// Read this file without ever opening Stack.cpp. You should still be
// able to tell exactly what this program does. That's the ADT promise
// in action: the header alone is enough documentation to use the type.

#include <iostream>
#include "Stack.h"

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Top: " << s.peek() << std::endl;

    s.pop();
    std::cout << "After pop, top: " << s.peek() << std::endl;
    std::cout << "Is empty? " << (s.isEmpty() ? "yes" : "no") << std::endl;

    return 0;
}

// TRY IT LIVE: ask the class "what data structure is UNDER this stack?"
// Nobody can answer just from reading this file, and that's correct --
// it's not their business. Then open Stack.h to reveal it's a vector.
