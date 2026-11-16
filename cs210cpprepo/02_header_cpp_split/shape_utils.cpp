// TASK 02 -- The .cpp file: HOW it actually works
//
// This is the DEFINITION file. Every function promised in the header
// gets its full body here, exactly once. That "exactly once" rule has
// a name: the One Definition Rule (ODR). Break it (define the same
// function body in two .cpp files that both get linked together) and
// you get a linker error, not a compiler error -- because each .cpp
// file compiles just fine on its own. The problem only shows up when
// the linker tries to combine object files and finds two bodies for
// one name.

#include "shape_utils.h"   // pull in the promises we're about to keep

double circleArea(double radius){
    // TODO: return the area of a circle with this radius (pi * radius * radius)
    return 3.14 * radius *radius;
}

double rectangleArea(double width, double height) {
    // TODO: return width times height
    return width*height;
}

// Notice: this file has ZERO knowledge of who calls these functions.
// That's the whole point of the split. main.cpp only needs the header
// to call circleArea(). It never needs to see this file at all, and if
// we change the formula in here (say, to a more precise value of pi),
// main.cpp doesn't need to be touched or even recompiled if we're just
// re-linking against an updated object file.
