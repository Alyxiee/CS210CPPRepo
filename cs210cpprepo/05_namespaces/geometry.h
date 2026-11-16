// TASK 05 -- Namespaces
//
// Two different libraries can both want to define something called
// circleArea. Without namespaces, the SECOND one to be linked in causes
// a "redefinition" error, because as far as the compiler is concerned
// they're both trying to claim the same global name. A namespace is a
// labeled box: it lets both exist, because their full names are
// actually cs210::circleArea and legacy_lib::circleArea, which are
// different names entirely.

#pragma once

namespace cs210 {
    // OUR convention: pass the radius.
    double circleArea(double radius);
}

namespace legacy_lib {
    // Imagine this is a 20-year-old library we depend on. Its author
    // made a different (and arguably worse) choice: this one takes the
    // DIAMETER. Same function name, same parameter type, completely
    // different meaning. This is exactly the kind of mix-up namespaces
    // exist to prevent -- the compiler will never let you call one
    // when you meant the other, because you have to say which box
    // you're reaching into.
    double circleArea(double diameter);
}
