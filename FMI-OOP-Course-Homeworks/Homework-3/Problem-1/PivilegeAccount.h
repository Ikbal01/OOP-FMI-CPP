#pragma once

#include"Account.h"

class PivilegeAccount : public Account
{
public:
	PivilegeAccount(string iban, string ownerId, long double amount, long double overdraft = 3000);
	virtual ~PivilegeAccount() {};

	virtual void deposit(long double amount);

	/**
	 * Withdraws money from the bank account
	 * if the money in the account + the allowed overdraft
	 * is less than the desired amount.
	 * @param amount
	 * @return
	 */
	virtual bool withdraw(long double amount);
	virtual void display() const;

	long double getOverdraft() const;

	string getAccountType() const;

private:
	long double overdraft;
};