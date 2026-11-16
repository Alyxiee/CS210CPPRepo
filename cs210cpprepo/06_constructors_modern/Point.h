// TASK 06 -- Constructors, the modern way
//
// Compare this class to Rectangle from Task 04. Same idea (a couple of
// numbers wrapped in a class), but every constructor idiom below is
// what you'll actually see in current C++ code and in this course's
// later assignments.

#pragma once

class Point {
public:
    // DELEGATING CONSTRUCTOR: instead of repeating "set x_ and y_ to
    // 0.0" here, this constructor just calls the other constructor
    // below with the values it wants. One source of truth for what
    // "default point" means.
    Point();

    // MEMBER INITIALIZER LIST: the ": x_(x), y_(y)" part. This
    // constructs x_ and y_ directly with the given values, as part of
    // building the object, rather than default-constructing them and
    // then reassigning in the body (which is what Task 04's Rectangle
    // did). For simple doubles the difference is mostly style, but for
    // const members, reference members, or members that are themselves
    // objects with expensive constructors, the initializer list isn't
    // just nicer, it's the only option or the only efficient one.
    Point(double x, double y);

    // EXPLICIT single-argument constructor. Without "explicit", C++
    // would happily let you write "Point p = 5.0;" and silently
    // convert 5.0 into a Point(5.0, 5.0). That kind of silent
    // conversion causes confusing bugs. "explicit" forces callers to
    // write Point(5.0) on purpose.
    explicit Point(double xy);

    // "= default" tells the compiler "generate the normal, member-wise
    // copy constructor yourself, I'm not writing anything custom."
    // Writing it out explicitly like this documents the decision, even
    // though the compiler would have generated the same thing silently
    // if we said nothing at all.
    Point(const Point& other) = default;

    double x() const { return x_; }
    double y() const { return y_; }

private:
    // DEFAULT MEMBER INITIALIZERS. If a constructor's initializer list
    // doesn't mention x_ or y_, these values (0.0) are used instead of
    // leaving the memory uninitialized. This is a safety net, not a
    // replacement for the initializer list above.
    double x_ = 0.0;
    double y_ = 0.0;
};
