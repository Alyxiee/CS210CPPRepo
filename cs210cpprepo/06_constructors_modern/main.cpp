// TASK 06 -- Four ways to build a Point

#include <iostream>
#include "Point.h"

void printPoint(const Point& p) {
    std::cout << "(" << p.x() << ", " << p.y() << ")" << std::endl;
}

int main() {
    Point origin;              // delegating default constructor
    Point p1(3.0, 4.0);        // member initializer list constructor
    Point p2(7.0);             // explicit single-argument constructor
    Point p3(p2);              // = default copy constructor

    std::cout << "origin = "; printPoint(origin);
    std::cout << "p1 = ";     printPoint(p1);
    std::cout << "p2 = ";     printPoint(p2);
    std::cout << "p3 (copy of p2) = "; printPoint(p3);

    // Point p4 = 9.0;   // <-- would NOT compile: constructor is explicit.
    Point p4(9.0);        // this is the only way in: on purpose.
    std::cout << "p4 = "; printPoint(p4);

    return 0;
}

// TRY IT LIVE: uncomment the "Point p4 = 9.0;" line and rebuild. Show
// the compiler refusing the implicit conversion, then remove "explicit"
// from Point.h's declaration and rebuild again to show it now silently
// works. Put "explicit" back before moving on.
