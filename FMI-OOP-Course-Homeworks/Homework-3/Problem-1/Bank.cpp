#include"Bank.h"

Bank::Bank(string name, string address)
{
	this->name = name;
	this->address = address;
}

Bank::~Bank()
{
	for (int i = 0; i < accounts.size(); i++)
	{
		delete accounts[i];
	}
}

string Bank::getName() const
{
	return name;
}

string Bank::getAddress() const
{
	return address;
}

void Bank::addCustomer(string customerId, string name, string address)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == customerId)
		{
			cout << " There is a customer with ID: " << customerId << endl;
			return;
		}
	}
	Customer currCustomer(customerId, name, address);
	customers.push_back(currCustomer);
}

void Bank::listCustomers() const
{
	for (int i = 0; i < customers.size(); i++)
	{
		customers[i].display();
	}
}

void Bank::deleteCustomer(string customerId)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == customerId)
		{
			customers.erase(customers.begin() + i);
			break;
		}
	}
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == customerId)
		{
			delete accounts[i];
			accounts.erase(accounts.begin() + i);
		}
	}
}

void Bank::addAccount(string accountType, string iban, string ownerId, long double amount)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			cout << "There is an account with " << iban << " IBAN" << endl;
			return;
		}
	}
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == ownerId)
		{
			Account * param;
			if (accountType == "CurrentAccount")
			{
				param = new CurrentAccount(iban, ownerId, amount);
			}
			else if (accountType == "PivilegeAccount")
			{
				param = new PivilegeAccount(iban, ownerId, amount);
			}
			else if (accountType == "SavingsAccount")
			{
				param = new SavingsAccount(iban, ownerId, amount);
			}
			else
			{
				cout << "There isn't such an account type." << endl;
			}
			accounts.push_back(param);
			return;
		}
	}
	cout << "There isn't a user with " << ownerId <<  " ID" << endl;
}

void Bank::deleteAccount(string iban)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			delete accounts[i];
			accounts.erase(accounts.begin() + i);
			break;
		}
	}
}

void Bank::listAccounts() const
{
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(string customerId) const
{
	cout << "Customer accounts of user with ID: " << customerId << " are:" << endl;
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == customerId)
		{
			accounts[i]->display();
		}
	}
}

void Bank::transfer(string fromIBAN, string toIBAN, long double amount)
{
	int indexOfToIban = -1;
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == toIBAN)
		{
			indexOfToIban = i;
			break;
		}
	}
	if (indexOfToIban == -1)
	{
		cout << "There isn't an account with IBAN: " << fromIBAN << endl;
		return;
	}
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == fromIBAN && (accounts[i]->withdraw(amount)))
		{
			accounts[indexOfToIban]->deposit(amount);
			return;
		}
	}
	cout << "There isn't an account with IBAN: " << toIBAN << endl;
}

void Bank::display() const
{
	cout << "Name of bank: " << name
		<< "\nAddress of bank: " << address
		<< "\nNumber of customers: " << customers.size()
		<< "\nNumber of accounts: " << accounts.size() << endl;
}