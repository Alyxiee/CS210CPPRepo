// TASK 08 -- One loop, many behaviors
//
// This is the payoff of overriding: main() doesn't know or care
// whether each Shape* is really a Circle or a Square. It calls
// ->area() and ->name() on a Shape*, and the CORRECT, RUNTIME-chosen
// version runs every time, because area() and name() are virtual.

#include <iostream>
#include <memory>
#include <vector>
#include "Circle.h"
#include "Square.h"

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Square>(4.0));
    shapes.push_back(std::make_unique<Circle>(1.0));

    for (const auto& shape : shapes) {
        std::cout << shape->name() << " area = " << shape->area()
                  << std::endl;
    }

    return 0;
}

// TRY IT LIVE: in Circle.h and Circle.cpp, remove "override" from
// area() and drop the trailing "const" from its signature in both
// files. It silently stops being an override of Shape's pure virtual
// "double area() const" and becomes an unrelated new function instead.
// Shape::area() is still unimplemented, so Circle is still abstract,
// and make_unique<Circle>(...) fails to compile. With "override" left
// in place, the SAME const typo is caught immediately, right where you
// made it, instead of showing up as a confusing error somewhere else.
// Put "override" and "const" back when you're done.
