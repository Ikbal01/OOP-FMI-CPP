#include"Customer.h"

Customer::Customer(string id, string name, string address)
{
	this->id = id;
	this->name = name;
	this->address = address;
}

Customer::~Customer()
{}

void Customer::display() const
{
	cout << "Id: " << id << " Name: " << name << " Address: " << address << endl;
}

string Customer::getId() const
{
	return id;
}

string Customer::getName() const
{
	return name;
}

string Customer::getAddress() const
{
	return address;
}
