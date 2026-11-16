#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double startingBalance, double interestRate);

    void applyMonthlyInterest();

private:
    double interestRate_;
};
