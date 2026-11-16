# CS 210 Fall 2026: C++ Foundations (starter code)

This is the fill-in version of the C++ Bootcamp. Each lecture's idea has been pulled out and left
as a `// TODO` for us to write together in class.

## Opening the project in CLion

`File > Open`, pick this folder, wait for
"CMake project loaded," then use the run-configuration dropdown (top
right, next to the green play button) to pick a target.

**Some targets won't build until their TODOs are filled in.** That's
expected, not a sign something's broken. A few will even compile with
just warnings (missing return values) before you touch them, and a
couple are built to fail on purpose (Tasks 09 and 10) until you make
the fix we talk about in class.

## What's blanked, task by task

| # | Folder | What to fill in |
|---|---|---|
| 1 | `01_compile_model` | Two `std::cout` lines in `main.cpp` |
| 2 | `02_header_cpp_split` | `circleArea` / `rectangleArea` bodies in `shape_utils.cpp` |
| 3 | `03_adt_stack` | All five `Stack` method bodies in `Stack.cpp` |
| 4 | `04_classes_objects` | Constructor + all four method bodies in `Rectangle.cpp` |
| 5 | `05_namespaces` | Both `circleArea` bodies in `geometry.cpp` (one takes a radius, one a diameter) |
| 6 | `06_constructors_modern` | All three `Point` constructors in `Point.cpp` -- rewrite each to use a member initializer list / delegation |
| 7 | `07_overloading` | All three `add` bodies in `Calculator.cpp` |
| 8 | `08_overriding_virtual` | `Circle` and `Square` constructors + `area()`/`name()` bodies |
| 9 | `09_diamond_inheritance` | One missing keyword in `Swimmer.h` and `Runner.h` (build it broken first, read the error, then fix it) |
| 10 | `10_access_specifiers` | The missing access specifier on `balance_` in `BankAccount.h`, plus `applyMonthlyInterest()`'s body |
| 11 | `11_main_wrapup` | `Book`'s constructor, and all three `Catalog` method bodies |

Every blanked spot has a comment telling you exactly what to write, and
sometimes the exact line to type. Tasks 9 and 10 are set up so the
*first* thing you do is build the broken version and read the real
compiler error, before fixing it.
