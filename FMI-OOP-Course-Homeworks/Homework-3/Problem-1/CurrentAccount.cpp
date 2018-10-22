#include"CurrentAccount.h"

CurrentAccount::CurrentAccount(string iban, string ownerId, long double amount) : Account(iban, ownerId, amount)
{}

void CurrentAccount::deposit(long double amount)
{
	this->amount += amount;
}

bool CurrentAccount::withdraw(long double amount)
{
	if (this->amount >= amount)
	{
		this->amount -= amount;
		return true;
	}
	return false;
}

void CurrentAccount::display() const
{
	cout << "Account type: Current Account" << " IBAN: " << iban << " Owner ID: " << ownerId << " Balance: " << amount << endl;
}

string CurrentAccount::getAccountType() const
{
	return "CurrentAccount";
}