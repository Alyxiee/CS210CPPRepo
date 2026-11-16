#include "geometry.h"

namespace cs210 {
    double circleArea(double radius) {
        // TODO: return pi * radius * radius
        return 3.14 * radius * radius;
    }
}

namespace legacy_lib {
    double circleArea(double diameter) {
        // TODO: this version takes a DIAMETER. Convert it to a radius
        // first, then return pi * radius * radius.
        double radius =diameter /2.0;
        return 3.14 * radius * radius;
    }
}
