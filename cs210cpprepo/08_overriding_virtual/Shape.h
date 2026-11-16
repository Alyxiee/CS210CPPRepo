// TASK 08 -- Overriding and virtual functions
//
// Overloading (Task 07) is resolved at compile time by parameter list.
// Overriding is resolved at RUNTIME, based on the actual type of object
// a base class pointer or reference is pointing at. That runtime
// lookup only happens if the function is declared "virtual" here in
// the base class.

#pragma once
#include <string>

class Shape {
public:
    // A virtual destructor. If you delete a derived object through a
    // Shape*, and ~Shape() is NOT virtual, only the base class part
    // gets cleaned up: the derived part leaks. This one line is the
    // single most common "gotcha" in intro inheritance code.
    virtual ~Shape() = default;

    virtual double area() const = 0;      // "= 0" makes this PURE
                                            // virtual: Shape itself
                                            // can never be built directly,
                                            // it only exists to be a
                                            // common base. This makes
                                            // Shape an abstract class.
    virtual std::string name() const = 0;
};
