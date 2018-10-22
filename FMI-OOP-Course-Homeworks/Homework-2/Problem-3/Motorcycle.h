#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	Motorcycle(char * make, char * model, char * color, int year, int mileage, char * type);
	Motorcycle(const Motorcycle & param);
	~Motorcycle();
	Motorcycle & operator=(const Motorcycle & param);


	char * getType() const;
	void setType(char * type);

	void details() const;

private:
	char * type; // Type of bike (e.g. chopper, cruiser, etc.)
		
	void copyFrom(const Motorcycle & param);
};

#endif