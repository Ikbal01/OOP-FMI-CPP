#include<iostream>
#include "ElectricNet.h"

ElectricNet::ElectricNet()
{
	maxConsumption = 10000;
	currKilowatts = 0;
	capacity = 10;
	devices = new ElectricDevice[capacity];
	index = 0;
}

ElectricNet::ElectricNet(int maxConsumption)
{
	this->maxConsumption = maxConsumption;
	currKilowatts = 0;
	capacity = 10;
	devices = new ElectricDevice [capacity];
	index = 0;
}

ElectricNet::~ElectricNet()
{
	delete[] devices;
}

ElectricNet & ElectricNet::operator += (const ElectricDevice & device)
{
	if ((currKilowatts + device.getKilowatts()) <= maxConsumption)
	{
		if (capacity <= index)
		{
			growDevicesArr();
		}
		devices[index] = device;
		index++;
		currKilowatts += device.getKilowatts();
	}
	else
	{
		std::cout << "maximum network consumption\n";
	}
	return *this;
}

ElectricNet & ElectricNet::operator + (const ElectricDevice & device)
{

	if ((currKilowatts + device.getKilowatts()) <= maxConsumption)
	{
		if (capacity <= index)
		{
			growDevicesArr();
		}
		devices[index] = device;
		index++;
		currKilowatts += device.getKilowatts();
	}
	else
	{
		std::cout << "maximum network consumption\n";
	}
	return *this;
}

ElectricNet & ElectricNet::operator -= (const ElectricDevice & device)
{
	for (int i = 0; i < index; i++)
	{
		if (strcmp(devices[i].getName(), device.getName()) == 0)
		{
			removeAt(i);
			break;
		}
	}
	return *this;
}

ElectricNet & ElectricNet::operator-(const ElectricDevice & device)
{
	for (int i = 0; i < index; i++)
	{
		if (strcmp(devices[i].getName(), device.getName()) == 0)
		{
			removeAt(i);
			break;
		}
	}
	return *this;
}

ElectricDevice * ElectricNet::operator[](char * name) const
{
	ElectricDevice * newElDev = nullptr;
	for (int i = 0; i < index; i++)
	{
		if (strcmp(devices[i].getName(), name) == 0)
		{
			newElDev = &devices[i];
			break;
		}
	}
	return newElDev;
}

bool ElectricNet::operator!() const
{
	if (index == 0)
	{
		return false;
	}
	return true;
}

ElectricNet & ElectricNet::operator++()
{
	maxConsumption *= 2;
	return *this;
}

ElectricNet & ElectricNet::operator++(int n)
{
	maxConsumption *= 2;
	return *this;
}

ElectricNet & ElectricNet::operator--()
{
	if (currKilowatts < (maxConsumption / 2))
	{
		maxConsumption /= 2;
	}
	
	return *this;
}

ElectricNet & ElectricNet::operator--(int n)
{
	if (currKilowatts < (maxConsumption / 2))
	{
		maxConsumption /= 2;
	}

	return *this;
}

void ElectricNet::growDevicesArr()
{
	ElectricDevice * currDevices = new ElectricDevice[capacity * 2];
	for (int i = 0; i < index; i++)
	{
		currDevices[i] = devices[i];
	}
	delete[] devices;
	devices = currDevices;
	capacity *= 2;
}

void ElectricNet::removeAt(int ind)
{
	currKilowatts -= devices[ind].getKilowatts();
	int write = ind;
	int read = ind + 1;
	while (read < capacity)
	{
		devices[write++] = devices[read++];
	}
	index--;
}

ElectricNet & ElectricNet::operator = (const ElectricNet & param)
{
	if (this != &param)
	{
		delete[] devices;
		maxConsumption = param.maxConsumption;
		currKilowatts = param.currKilowatts;
		devices = new ElectricDevice[param.capacity];
		for (int i = 0; i < param.index; i++)
		{
			devices[i] = param.devices[i];
		}
		capacity = param.capacity;
		index = param.index;
	}
	return *this;
}

ElectricNet::ElectricNet(const ElectricNet & param)
{
	maxConsumption = param.maxConsumption;
	currKilowatts = param.currKilowatts;
	devices = new ElectricDevice[param.capacity];
	for (int i = 0; i < param.index; i++)
	{
		devices[i] = param.devices[i];
	}
	capacity = param.capacity;
	index = param.index;
}

