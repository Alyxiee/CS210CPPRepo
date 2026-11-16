#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    explicit Circle(double radius);

    // "override" is not required by the compiler, but always write it.
    // It tells the compiler "I believe this matches a virtual function
    // in my base class, check that for me." If you typo the signature
    // (wrong type, missing const), "override" turns a silent bug (you
    // accidentally overloaded instead of overrode, and the base
    // version still runs) into a compile error.
    double area() const override;
    std::string name() const override;

private:
    double radius_;
};
