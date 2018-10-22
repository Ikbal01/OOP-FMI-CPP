#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(char * make, char * model, char * color, int year, int mileage, double size);
	Truck(const Truck & param);
	~Truck();
	Truck & operator=(const Truck & param);

	void details() const;

	double getSize() const;
	void setSize(double size);
private:
	double size; // Size of the truck in meters.
};

#endif