#pragma once

#include<iostream>
#include<string>
#include<vector>

#include "Customer.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PivilegeAccount.h"

using namespace std;

class Bank
{
public:
	Bank(string name, string address);
	~Bank();

	string getName() const;
	string getAddress() const;
	void addCustomer(string customerId, string name, string address);
	void listCustomers() const;
	void deleteCustomer(string customerId);
	void addAccount(string accountType, string iban, string ownerId, long double amount);
	void deleteAccount(string iban);
	void listAccounts() const;
	void listCustomerAccount(string customerId) const;
	void transfer(string fromIBAN, string toIBAN, long double amount);
	void display() const;

private:
	string name;
	string address;
	vector<Customer> customers;
	vector<Account *> accounts;
};