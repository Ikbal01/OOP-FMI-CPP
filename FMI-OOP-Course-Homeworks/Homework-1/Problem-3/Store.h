#ifndef STORE_H
#define STORE_H

#include"Product.h"

class Store
{
private:
	Product * products;
	int count;
	int size;
	
	void grow();
	void removeAt(Product * arr, int size, int starFrom, int pos);
public:
	Store();
	~Store();
	void addProduct();
	void deleteProduct();
	void changeProduct();
	void printAvailblePrdcts() const;

};
#endif // !STORE_H