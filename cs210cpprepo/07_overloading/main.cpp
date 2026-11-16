// TASK 07 -- The compiler picks the overload, not you at runtime

#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;

    std::cout << "add(2, 3)         -> " << calc.add(2, 3) << std::endl;
    std::cout << "add(2.5, 3.5)     -> " << calc.add(2.5, 3.5) << std::endl;
    std::cout << "add(1, 2, 3)      -> " << calc.add(1, 2, 3) << std::endl;

    // The return TYPE alone is never enough to pick an overload. Only
    // parameter types and count matter. You could not have both
    //   int add(int a, int b);
    //   double add(int a, int b);
    // at the same time, because the compiler can't tell them apart at
    // the call site.

    return 0;
}

// TRY IT LIVE: add a fourth overload, add(int a, double b), and call
// calc.add(2, 3.5). Ask the class which one runs, then confirm.
