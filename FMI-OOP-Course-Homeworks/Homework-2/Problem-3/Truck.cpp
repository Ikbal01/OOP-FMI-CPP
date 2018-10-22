#include "Truck.h"

Truck::Truck() : Vehicle()
{
	size = 10;
}

Truck::Truck(char * make, char * model, char * color, int year, int mileage, double size) : Vehicle(make, model, color, year, mileage)
{
	this->size = size;
}

Truck::Truck(const Truck & param) : Vehicle(param)
{
	size = param.size;
}

Truck::~Truck()
{

}

Truck & Truck::operator=(const Truck & param)
{
	if (this != &param)
	{
		Vehicle::operator=(param);
		size = param.size;
	}
	return *this;
}

void Truck::details() const
{
	cout << "Truck details:\nMake: " << getMake()
		<< "\nModel: " << getModel() 
		<< "\nColor: " << getColor() 
		<< "\nYear: " << getYear() 
		<< "\nMileage: " << getMileage() 
		<< "\nSize: " << getSize() << endl << endl;
}

double Truck::getSize() const
{
	return size;
}
void Truck::setSize(double size)
{
	this->size = size;
}
