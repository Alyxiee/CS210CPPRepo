// TASK 02 -- The header file: WHAT exists, not HOW it works
//
// A header is a promise. It tells any .cpp file that #includes it
// "these functions exist, here are their names and types, trust me."
// It does NOT contain the actual instructions for how the functions work.
// That's the .cpp file's job.

#pragma once
// #pragma once is an include guard. Without it, if two different .cpp
// files (indirectly) #include this header twice into the same
// translation unit, the compiler sees these declarations twice and
// throws a redefinition error. #pragma once tells the preprocessor
// "only paste this file in once per translation unit, no matter how
// many times it's #included." The older, more portable way to write
// the same guard is:
//
//   #ifndef SHAPE_UTILS_H
//   #define SHAPE_UTILS_H
//   ... declarations ...
//   #endif
//
// Both do the same job. #pragma once is shorter and what you'll see
// in most modern codebases.

// These are DECLARATIONS. Just the signature: name, parameter types,
// return type. No body, ends in a semicolon.
double circleArea(double radius);
double rectangleArea(double width, double height);
