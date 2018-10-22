#include<iostream>
#include"Product.h"
#include"Store.h"

using namespace std;

int main()
{
	Store myStore;
	myStore.addProduct();
	myStore.addProduct();
	std::cout << "SKU of product for delete: \n";
	myStore.deleteProduct();
	myStore.printAvailblePrdcts();

	system("pause");
	return 0;
}