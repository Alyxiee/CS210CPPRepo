#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double startingBalance, double interestRate)
    : BankAccount(startingBalance), interestRate_(interestRate) {}

void SavingsAccount::applyMonthlyInterest() {
    // TODO: increase balance_ by balance_ * interestRate_
    // This will only compile once BankAccount.h's access specifier for
    // balance_ lets a derived class reach it. If you see a "balance_ is
    // private/protected within this context" error, that's this task's
    // other TODO waiting to be fixed.
}
