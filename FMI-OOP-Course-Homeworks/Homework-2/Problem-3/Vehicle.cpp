#include"Vehicle.h"

Vehicle::Vehicle()
{
	make = new char[7];
	strcpy_s(make, 7, "noMake");
	model = new char[8];
	strcpy_s(model, 8, "noModel");
	color = new char[8];
	strcpy_s(color, 8, "noColor");
	year = 0;
	mileage = 0;
}

Vehicle::Vehicle(char * make, char * model, char * color, int year, int mileage)
{
	this->make = copyFrom(make);
	this->model = copyFrom(model);
	this->color = copyFrom(color);
	this->year = year;
	this->mileage = mileage;
}

Vehicle::Vehicle(const Vehicle & param)
{
	make = copyFrom(param.getMake());
	model = copyFrom(param.getModel());
	color = copyFrom(param.getColor());
	year = param.getYear();
	mileage = param.getMileage();
}

Vehicle & Vehicle::operator=(const Vehicle & param)
{
	if (this != &param)
	{
		destroy();
		make = copyFrom(param.getMake());
		model = copyFrom(param.getModel());
		color = copyFrom(param.getColor());
		year = param.getYear();
		mileage = param.getMileage();
	}
	return *this;
}

Vehicle::~Vehicle()
{
	delete[] make;
	delete[] model;
	delete[] color;
	//destroy();
}

const char * Vehicle::getMake() const
{
	return make;
}

const char * Vehicle::getModel() const
{
	return model;
}

const char * Vehicle::getColor() const
{
	return color;
}

int Vehicle::getYear() const
{
	return year;
}

int Vehicle::getMileage() const
{
	return mileage;
}

void Vehicle::setMake(char * make)
{
	delete[] this->make;
	this->make = copyFrom(make);
}

void Vehicle::setModel(char * model)
{
	delete[] this->model;
	this->model = copyFrom( model);
}
void Vehicle::setColor(char * color)
{
	delete[] this->color;
	this->color = copyFrom(color);
}
void Vehicle::setYear(int year)
{
	this->year = year;
}
void Vehicle::setMileage(int mileage)
{
	this->mileage = mileage;
}

void Vehicle::destroy()
{
	delete[] make;
	delete[] model;
	delete[] color;
}

char * Vehicle::copyFrom(const char * param)
{
	char * newParam = new char[strlen(param) + 1];
	strcpy_s(newParam, strlen(param) + 1, param);
	return newParam;
}