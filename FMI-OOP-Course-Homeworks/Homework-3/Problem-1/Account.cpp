#include "Account.h"

Account::Account(string iban, string ownerId, long double amount)
{
	this->iban = iban;
	this->ownerId = ownerId;
	this->amount = amount;
}

Account::~Account()
{}

long double Account::getBalance() const
{
	return amount;
}

string Account::getIban() const
{
	return iban;
}

string Account::getOwnerId() const
{
	return ownerId;
}