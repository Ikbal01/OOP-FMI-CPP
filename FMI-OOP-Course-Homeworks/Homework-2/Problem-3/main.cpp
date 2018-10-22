#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include<iostream>

using namespace std;

int main()
{

	Vehicle *car = new Car("BMW", "655", "black", 2018, 2123);
	Vehicle *truck = new Truck("Mercedes", "400", "white", 1990, 1000000, 8);
	Vehicle *bike = new Motorcycle("Suzuki", "655", "black", 2018, 123, "chopper");

	car->details();
	truck->details();
	bike->details();

	system("pause");
	return 0;
}