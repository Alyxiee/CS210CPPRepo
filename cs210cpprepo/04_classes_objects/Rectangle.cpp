#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) {
    width_=width;

    // Old-school constructor body: assign the members one at a time,
    // like any other function. This works, but it's not the style
    // we'll write once we hit Task 06.
    // TODO: assign the width parameter to width_, and height to height_
}

double Rectangle::area() const {
    // TODO: return width_ times height_
    return width_*height_;
}

double Rectangle::perimeter() const {
    // TODO: return 2 * (width_ + height_)
    return 2*width_*height_;
}

void Rectangle::setWidth(double width) {
    // TODO: assign the parameter to width_
    width_=width;
}

void Rectangle::setHeight(double height) {
    // TODO: assign the parameter to height_
    height_=height;
}
