#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(char * make, char * model, char * color, int year, int mileage);
	Car(const Car & param);
	~Car();
	Car & operator=(const Car & param);

	void details() const;
private:
};

#endif