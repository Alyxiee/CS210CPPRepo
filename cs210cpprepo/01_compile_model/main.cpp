// TASK 01 -- How a C++ program actually becomes a program
//
// Every .cpp file you write goes through the same three-stage pipeline
// before it can run. This file is small on purpose: today's not about
// the code, it's about the pipeline that turns it into a binary.

#include <iostream>   // (1) PREPROCESS pulls this header's text in, literally,
                      //     before anything else happens. #include is a
                      //     copy-paste instruction, nothing more.

#define GREETING "Welcome to CS 210"   // also a preprocessor directive:
                                       // every later use of GREETING gets
                                       // textually replaced before compiling

int main() {
    // (2) COMPILE turns this human-readable C++ into assembly, then into
    //     an object file (main.o). The compiler checks your syntax and
    //     types here. This is where a missing semicolon gets caught.
    // TODO: print GREETING with std::cout (don't forget std::endl)
    std::cout << GREETING<<std::endl;


    // (3) LINK stitches your object file together with the object code
    //     for things you used but didn't write yourself, like the
    //     implementation of std::cout living inside the standard library.
    //     Linking is also where "undefined reference" errors come from:
    //     you declared something, but the linker never found where it's
    //     actually defined.
    // TODO: print "Preprocess -> Compile -> Link -> Executable" with std::cout
    std::cout << "Preprocess -> Compile -> Link -> Executable" << std::endl;

    return 0;   // 0 means "exited normally." We'll come back to this in
                // the main() wrap-up task.
}

// TRY IT LIVE: comment out the #include line and hit build. Read the
// error out loud with the class -- it will complain about std::cout
// being undeclared, because the preprocessor step never happened.
