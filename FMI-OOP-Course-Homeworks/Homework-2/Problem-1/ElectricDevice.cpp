#include "ElectricDevice.h"

ElectricDevice::ElectricDevice()
{
	int nameSizeInChars = 7;
	name = new char[nameSizeInChars];
	strcpy_s(name, nameSizeInChars, "noName");
	kilowatts = 0;
}

ElectricDevice::ElectricDevice(const char * name, int kilowatts)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->kilowatts = kilowatts;
}

ElectricDevice::~ElectricDevice()
{
	delete[] name;
}

const char * ElectricDevice::getName() const
{
	return name;
}

int ElectricDevice::getKilowatts() const
{
	return kilowatts;
}

ElectricDevice & ElectricDevice::operator = (const ElectricDevice & param)
{
	if (this != &param)
	{
		name = new char[strlen(param.getName()) + 1];
		strcpy_s(name, strlen(param.getName()) + 1, param.getName());
		kilowatts = param.getKilowatts();
	}
	return *this;
}
