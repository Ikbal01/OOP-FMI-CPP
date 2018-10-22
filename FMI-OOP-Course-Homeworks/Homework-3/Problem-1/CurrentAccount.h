#pragma once

#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(string iban, string ownerId, long double amount);
	virtual ~CurrentAccount() {};

	virtual void deposit(long double amount);
	virtual bool withdraw(long double amount);
	virtual void display() const;

	string getAccountType() const;

};