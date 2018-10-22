#include<iostream>
#include"ElectricNet.h"

using namespace std;

// Example usage of source code.
int main()
{
	ElectricDevice a("burzovar", 1200);
	ElectricDevice b("burzovar", 1400);
	ElectricDevice c("laptop", 1300);
	ElectricDevice d("kotlon", 5700);
	ElectricDevice e("peralnq", 1100);

	ElectricNet A(10000);
	A = A + a;
	A += b;
	A += c;
	A += d;
	A += e;
	A = A - c;
	A -= d;
	ElectricDevice * l = A["burzovar"];
	cout << "There are " << (!A ? "" : "no " ) << "devices connected to this network" << endl;

	A++;
	++A;
	A--;
	--A;

	system("pause");
	return 0;
}
