// TASK 11 -- main(), the function that starts everything
//
// main() is the ONE function the operating system calls directly when
// your program launches. Nothing runs before it (well, some
// constructors of global objects, but that's a story for later) and
// the program ends when main() returns.

#include <iostream>
#include "Book.h"
#include "Catalog.h"

// argc = "argument count", how many command-line arguments were passed,
//   always at least 1 (the program's own name).
// argv = "argument vector", the actual strings, argv[0] is the program
//   name, argv[1] is the first real argument, and so on.
int main(int argc, char* argv[]) {
    std::cout << "Program name: " << argv[0] << std::endl;
    std::cout << "Extra arguments passed: " << (argc - 1) << std::endl;

    using cs210::library::Book;
    using cs210::library::Catalog;

    Catalog catalog;
    catalog.addBook(Book("Introduction to Algorithms", "Cormen et al."));
    catalog.addBook(Book("The C++ Programming Language", "Stroustrup"));
    catalog.addBook(Book("Effective Modern C++", "Meyers"));

    std::cout << "Catalog has " << catalog.count() << " books:" << std::endl;
    catalog.printAll();

    if (catalog.count() == 0) {
        // A non-zero return value is how a program tells whoever ran
        // it ("the shell", or another program, or CLion's own Run
        // window) that something went wrong. By convention 0 means
        // success. Run this from a real terminal and check with
        // "echo $?" right after -- that's this return value.
        std::cerr << "Catalog is empty, something is wrong." << std::endl;
        return 1;
    }

    return 0;   // success: everything above ran with no problems.
}

// TRY IT LIVE: in CLion, open the run configuration for this target
// (the dropdown, then "Edit Configurations...") and add a couple of
// words in the "Program arguments" field. Rerun and watch argc/argv
// change. Then, from an actual terminal, run the built binary and
// type "echo $?" right after -- that number is this file's return
// value making it out to the operating system.
