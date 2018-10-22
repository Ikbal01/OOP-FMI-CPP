#include <iostream>
#include <string.h>

#include"Settings.h"

using namespace std;

// Example usage of the API.
int main()
{
	Pair<int> a("one", 1);
	Pair<int> b("two", 2);
	Pair<int> c("three", 3);
	Pair<int> d("four", 4);
	Pair<int> e("five", 5);
	Pair<int> f("six", 6);

	a.setValue(55);
	cout << a.getKey() << " " << a.getValue() << endl;

	Pair<int> * pairs = new Pair<int>[10];
	pairs[0] = a;
	pairs[1] = b;
	pairs[2] = c;
	pairs[3] = d;

	int numberOne = 10;
	int numberTwo = 22;

	Settings<int> A(pairs, 4);
	A.set("one", 8);
	A.set("seven", 7);

	cout << A.get("four", numberOne) << endl;
	cout << A.get("alabala", numberTwo) << endl;
	cout << "number one: " << numberOne << " number two: " << numberTwo << endl;


	Settings<int> B = A;
	Settings<int> C;
	C = A;

	system("pause");
	return 0;
}