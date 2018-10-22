#pragma once

#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(string iban, string ownerId, long double amount, long double interestRate = 2.3);
	virtual ~SavingsAccount() {};

	virtual void deposit(long double amount);
	virtual bool withdraw(long double amount);
	virtual void display() const;

	long double getInterestRate() const;

	string getAccountType() const;
private:
	long double interestRate;
};