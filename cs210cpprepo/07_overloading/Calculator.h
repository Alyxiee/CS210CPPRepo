// TASK 07 -- Overloading
//
// Overloading is giving several functions the SAME NAME but DIFFERENT
// parameter lists. The compiler picks which one to call based on the
// argument types you pass, at COMPILE time. This is different from
// overriding (Task 08), which is a runtime decision based on the
// actual object type behind a base class pointer or reference.

#pragma once

class Calculator {
public:
    int add(int a, int b);
    double add(double a, double b);
    int add(int a, int b, int c);   // different arity also counts as
                                     // a different signature
};
