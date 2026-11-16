// TASK 05 -- Reaching into a namespace
//
// Three ways to call a namespaced name, from most explicit (safest) to
// least explicit (riskiest):

#include <iostream>
#include "geometry.h"

// 1. A "using declaration" for ONE specific name. This only pulls in
//    cs210::circleArea, nothing else from cs210. This is the style we
//    recommend by default: convenient, but scoped.
using cs210::circleArea;

int main() {
    // 2. Fully qualified: always correct, always clear, more typing.
    //    Notice these two calls give DIFFERENT answers for the same
    //    number, because the two libraries disagree on what a
    //    "circleArea" argument even means.
    std::cout << "cs210::circleArea(4.0)      = "
              << cs210::circleArea(4.0) << std::endl;
    std::cout << "legacy_lib::circleArea(4.0) = "
              << legacy_lib::circleArea(4.0) << std::endl;

    // 3. Thanks to our using-declaration above, plain circleArea(4.0)
    //    unambiguously means cs210::circleArea here.
    std::cout << "circleArea(4.0) via using-declaration = "
              << circleArea(4.0) << std::endl;

    // We are deliberately NOT writing "using namespace legacy_lib;" or
    // "using namespace cs210;" up top. Do that with both at once and
    // plain circleArea(4.0) becomes AMBIGUOUS -- the compiler refuses
    // to guess which one you meant. That's the namespace system
    // working as designed.

    return 0;
}

// TRY IT LIVE: add "using namespace legacy_lib;" right under the
// #include lines, keep the existing "using cs210::circleArea;", and
// rebuild. Read the ambiguity error together.
