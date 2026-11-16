// TASK 04 -- One class, many objects
//
// Each Rectangle object below is a separate chunk of memory. Changing
// one has zero effect on the others. That independence is the entire
// point of instantiation.

#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle a(4.0, 5.0);
    Rectangle b(2.0, 2.0);

    std::cout << "Rectangle a: area = " << a.area()
              << ", perimeter = " << a.perimeter() << std::endl;
    std::cout << "Rectangle b: area = " << b.area()
              << ", perimeter = " << b.perimeter() << std::endl;

    a.setWidth(10.0);
    std::cout << "After resizing a's width, a's area = " << a.area()
              << " (b is untouched: " << b.area() << ")" << std::endl;

    return 0;
}

// TRY IT LIVE: draw two boxes on the whiteboard labeled "a" and "b",
// each with its own width_ and height_ slots, BEFORE running this.
// Then run it and show that setWidth on a never touches b's box.
