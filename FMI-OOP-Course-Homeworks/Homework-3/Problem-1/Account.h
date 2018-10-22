#pragma once

#include<iostream>
#include<string>

using namespace std;

class Account
{
public:
	Account(string iban, string ownerId, long double amount);
	virtual ~Account();


	/**
	 * 	Adds money into the account.
	 */
	virtual void deposit(long double amount) = 0;

	/**
	 * Takes money out of the account.
	 * @param amount amount to take out.
	 * @return true if operation is successful, false otherwise.
	 */
	virtual bool withdraw(long double amount) = 0;
	virtual void display() const = 0;

	long double getBalance() const;
	string getIban() const;
	string getOwnerId() const;

	virtual string getAccountType() const = 0;

protected:
	string iban;
	string ownerId;
	long double amount;
};