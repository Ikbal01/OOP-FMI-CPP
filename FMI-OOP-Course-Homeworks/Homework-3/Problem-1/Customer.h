#pragma once

#include<iostream>
#include<string>

using namespace std;

class Customer
{
public:
	Customer(string id, string name, string address);
	~Customer();

	/**
	 * Displays the customer info on the console.
	 */
	void display() const;

	string getId() const;

	string getName() const;

	string getAddress() const;

private:
	string id; // User's identifier.
	string name; // User name.
	string address; // Address of user.
};
