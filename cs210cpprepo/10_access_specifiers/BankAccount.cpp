#include "BankAccount.h"

BankAccount::BankAccount(double startingBalance) : balance_(startingBalance) {}

void BankAccount::deposit(double amount) {
    balance_ += amount;
    ++transactionCount_;
}

bool BankAccount::withdraw(double amount) {
    if (amount > balance_) {
        return false;
    }
    balance_ -= amount;
    ++transactionCount_;
    return true;
}

double BankAccount::balance() const {
    return balance_;
}
