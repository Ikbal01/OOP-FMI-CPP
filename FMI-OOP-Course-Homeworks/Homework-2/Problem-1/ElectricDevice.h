#ifndef ELECTRIC_DEVICE_H
#define ELECTRIC_DEVICE_H

#include<iostream>
#include<string.h>

class ElectricDevice
{
public:
	ElectricDevice();
	ElectricDevice(const char * name, int kilowatts);
	~ElectricDevice();
	ElectricDevice & operator=(const ElectricDevice & param);


	const char * getName() const; // Gets the name of the device

	int getKilowatts() const; // Gets the device power measured in kilowatts
private:
	char * name; // The device name
	int kilowatts; // The device power in kilowatts
};

#endif