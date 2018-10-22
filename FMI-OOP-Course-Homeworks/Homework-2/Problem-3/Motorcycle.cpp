#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle()
{
	int stringSize = 8;
	type = new char[stringSize];
	strcpy_s(type, stringSize, "chopper");
}

Motorcycle::Motorcycle(char * make, char * model, char * color, int year, int mileage, char * type) : Vehicle(make, model, color, year, mileage)
{
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

Motorcycle::Motorcycle(const Motorcycle & param) : Vehicle(param)
{
	copyFrom(param);
}

Motorcycle::~Motorcycle()
{
	delete[] type;
}

Motorcycle & Motorcycle::operator=(const Motorcycle & param)
{
	if (this != &param)
	{
		Vehicle::operator=(param);
		delete[] type;
		copyFrom(param);
	}
	return *this;
}

void Motorcycle::details() const
{
	cout << "Motorcycle details:\nMake: " << getMake()
		<< "\nModel: " << getModel()
		<< "\nColor: " << getColor()
		<< "\nYear: " << getYear()
		<< "\nMileage: " << getMileage()
		<< "\nType: " << getType() << endl << endl;
}

char * Motorcycle::getType() const
{
	return type;
}

void Motorcycle::setType(char * type)
{
	delete[] this->type;
	this->type = new char[strlen(type) + 1];
	strcat_s(this->type, strlen(type) + 1, type);
}

void Motorcycle::copyFrom(const Motorcycle & param)
{
	type = new char[strlen(param.type) + 1];
	strcpy_s(type, strlen(param.type) + 1, param.type);
}
