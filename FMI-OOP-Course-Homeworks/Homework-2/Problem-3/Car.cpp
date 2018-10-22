#include"Car.h"

Car::Car() : Vehicle()
{

}

Car::Car(char * make, char * model, char * color, int year, int mileage) : Vehicle(make, model, color, year, mileage)
{}

Car::Car(const Car & param) : Vehicle(param)
{}

Car::~Car()
{}

Car & Car::operator=(const Car & param)
{
	if (this != &param)
	{
		Vehicle::operator=(param);
	}
	return *this;
}

void Car::details() const
{
	cout << "Car details:\nMake: " << getMake()
		<< "\nModel: " << getModel() 
		<<"\nColor: " << getColor()
		<<"\nYear: " << getYear() 
		<<"\nMileage: " << getMileage() << endl << endl;
}
