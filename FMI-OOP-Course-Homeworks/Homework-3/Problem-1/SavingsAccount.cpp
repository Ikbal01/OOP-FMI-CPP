#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(string iban, string ownerId, long double amount, long double interestRate) : Account(iban, ownerId, amount)
{
	this->interestRate = interestRate;
}

long double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

void SavingsAccount::deposit(long double amount)
{
	this->amount += amount;
}

bool SavingsAccount::withdraw(long double amount)
{
	if (this->amount >= amount)
	{
		this->amount -= amount;
		return true;
	}
	return false;
}

void SavingsAccount::display() const
{
	std::cout << "Account type: Savings Account"
		<< " IBAN: " << iban
		<< " Owner ID: " << ownerId
		<< " Interest Rate: " << interestRate
		<< " Balance: " << amount << std::endl;
}

string SavingsAccount::getAccountType() const
{
	return "SavingsAccount";
}