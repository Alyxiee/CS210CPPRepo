// TASK 10 -- private, protected, and public in action

#include <iostream>
#include "BankAccount.h"
#include "SavingsAccount.h"

int main() {
    BankAccount checking(100.0);
    checking.deposit(50.0);
    checking.withdraw(30.0);
    std::cout << "Checking balance: " << checking.balance() << std::endl;

    // checking.balance_ = 1000000.0;   // <-- should NOT compile, no
    // matter which access specifier you pick for balance_ in
    // BankAccount.h. Try uncommenting this once you've filled in that
    // TODO, to prove outside code never gets in, whether balance_ ends
    // up protected or private.

    SavingsAccount savings(1000.0, 0.02);
    savings.applyMonthlyInterest();
    std::cout << "Savings balance after interest: " << savings.balance()
              << std::endl;

    return 0;
}

// DO THIS FIRST: in SavingsAccount.cpp, write the one line
// applyMonthlyInterest() needs (see its TODO) before touching anything
// else. Right now balance_ in BankAccount.h has no access specifier at
// all, which means it defaults to private -- so that line will fail to
// compile with a "balance_ is private within this context" error. Read
// that error together, then go fix BankAccount.h's TODO. Once you pick
// the right specifier, SavingsAccount.cpp should compile, and the
// commented-out "checking.balance_ = ..." line above should still
// refuse to compile no matter what you picked, because it's outside
// the class hierarchy entirely.
