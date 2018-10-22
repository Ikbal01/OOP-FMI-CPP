#include"PivilegeAccount.h"

PivilegeAccount::PivilegeAccount(string iban, string ownerId, long double amount, long double overdraft) : Account(iban, ownerId, amount)
{
	this->overdraft = overdraft;
}

void PivilegeAccount::deposit(long double amount)
{
	this->amount += amount;
}

bool PivilegeAccount::withdraw(long double amount)
{
	if ((this->amount + overdraft) >= amount)
	{
		this->amount -= amount;
		return true;
	}
	return false;
}

void PivilegeAccount::display() const
{
	std::cout << "Account type: Pivilege Account" << " IBAN: " << iban << " Owner ID: " << ownerId << " Allowed overdraft: " << overdraft << " Balance: " << amount << std::endl;
}

long double PivilegeAccount::getOverdraft() const
{
	return overdraft;
}

string PivilegeAccount::getAccountType() const
{
	return "PivilegeAccount";
}