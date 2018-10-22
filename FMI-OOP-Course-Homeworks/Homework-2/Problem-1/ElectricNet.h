#ifndef ELECTRIC_NET_H
#define ELECTRIC_NET_H

#include "ElectricDevice.h"

class ElectricNet
{
public:
	ElectricNet();
	ElectricNet(int maxConsumption);
	ElectricNet(const ElectricNet & param);
	~ElectricNet();
	ElectricNet & operator=(const ElectricNet & param);

	ElectricNet & operator+=(const ElectricDevice & device); // Adds a new device to the network, if it's possible to be done without overloading the network.
	ElectricNet & operator+(const ElectricDevice & device); // Adds a new device to the network, if it's possible to be done without overloading the network.

	ElectricNet & operator-=(const ElectricDevice & device); // Removes an existing device from the network, if there is such.
	ElectricNet & operator-(const ElectricDevice & device); // Removes an existing device from the network, if there is such.

	ElectricDevice * operator[](char * name) const; // Access a given device in the network. Modifications are possible after access.
	bool operator!() const; // Checks if there is at least one device connected to the network.
	ElectricNet & operator++(); // Doubles the maximum energy consumption in the network.
	ElectricNet & operator++(int n); // Doubles the maximum energy consumption in the network.
	ElectricNet & operator--(); // Halves the maximum energy consumption in the network (if it doesn't lead to network overload).
	ElectricNet & operator--(int n);// Halves the maximum energy consumption in the network (if it doesn't lead to network overload).

private:
	int maxConsumption; // The maximum allowed consumption of the network.
	int currKilowatts; // The current consumption in kilowatts.
	ElectricDevice * devices; // Holds all devices connected to this network.
	int capacity; // The maximum capacity of the device array.
	int index; // The array index of the last device in the network.

	void growDevicesArr(); // Doubles the device array, if filled.
	void removeAt(int ind); // Removes an element at a given index.
};

#endif 
