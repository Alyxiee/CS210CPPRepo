// TASK 10 -- private vs protected vs public
//
// public:    anyone holding an object of this type can use it.
// protected: only this class AND classes that inherit from it can use it.
// private:   only this exact class can use it. Not even derived classes.
//
// The only way to actually SEE the difference between private and
// protected is to have a derived class try to reach in. That's why
// this task also has SavingsAccount, which inherits from BankAccount.

#pragma once
#include <string>

class BankAccount {
public:
    explicit BankAccount(double startingBalance);
    virtual ~BankAccount() = default;

    void deposit(double amount);
    bool withdraw(double amount);   // returns false if funds are insufficient
    double balance() const;

    // TODO: SavingsAccount (below, in this same task) needs to reach in
    // and adjust balance_ directly to apply interest, without going
    // through deposit()/withdraw(). Which access specifier -- public,
    // protected, or private -- lets a DERIVED class touch a member,
    // while still keeping it closed off to code outside the hierarchy?
    // Add that keyword (with a colon) on its own line, right above
    // balance_.
    double balance_;

private:
    // Nobody outside BankAccount itself, not even SavingsAccount,
    // should be able to see or touch this. It's an internal
    // implementation detail: a running count purely for our own
    // bookkeeping/logging, unrelated to the public interface.
    int transactionCount_ = 0;
};
