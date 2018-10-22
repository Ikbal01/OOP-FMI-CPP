#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<string.h>

using namespace std;

class Vehicle
{
public:
	Vehicle();
	Vehicle(char * make, char * model, char * color, int year, int mileage);
	Vehicle(const Vehicle & param);
	virtual ~Vehicle();
	Vehicle & operator=(const Vehicle & param);

	virtual void details()const{} // Details of the vehicle.

	const char * getMake() const;
	const char * getModel() const;
	const char * getColor() const;
	int getYear() const;
	int getMileage() const;

	void setMake(char * make);
	void setModel(char * model);
	void setColor(char * color);
	void setYear(int year);
	void setMileage(int mileage);

private:
	char * make; // The vehicle brand.
	char * model; // The model.
	char * color; // Exterior color.
	int year; // Year of production.
	int mileage; // Mileage of the vehicle.

	char* copyFrom(const char * param);
	void destroy();

};

#endif