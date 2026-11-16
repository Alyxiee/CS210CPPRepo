// TASK 02 -- Using the split
//
// main.cpp only ever #includes the HEADER. It never #includes
// shape_utils.cpp. The compiler compiles shape_utils.cpp separately
// into its own object file, and the LINKER (see Task 01) is what
// connects this call site to that implementation.

#include <iostream>
#include "shape_utils.h"

int main() {
    double area1 = circleArea(4.0);
    double area2 = rectangleArea(3.0, 5.0);

    std::cout << "Circle area: " << area1 << std::endl;
    std::cout << "Rectangle area: " << area2 << std::endl;

    return 0;
}

// TRY IT LIVE: open shape_utils.h and shape_utils.cpp side by side with
// main.cpp (three-pane view). Ask: "if I change 3.14159265 to just 3.14
// in the .cpp, does main.cpp need to change?" Answer: no. That's the
// interface/implementation boundary doing its job.
