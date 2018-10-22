#include<iostream>
#include"Store.h"
#include"Store.h"


Store::Store()
{
	products = new Product[20];
	size = 20;
	count = 0;
}

Store::~Store()
{
	delete[] products;
}

void Store::addProduct()
{
	Product currPrdct;
	std::cin >> currPrdct;
	if (count >= size)
	{
		grow();
	}
	products[count] = currPrdct;
	count++;
}

void Store::deleteProduct()
{
	char * skuu = new char[50];
	std::cin >> skuu;
	for (int i = 0; i < count; i++)
	{
		if (products[i].SKU == skuu)
		{
			removeAt(products, count, i, 1);
			count--;
		}
	}
}

void Store::changeProduct()
{
	char * skuu = new char[50];
	std::cin >> skuu;
	for (int i = 0; i < count; i++)
	{
		if (products[i].SKU == skuu)
		{
			std::cin >> products[i];
		}
	}
}

void Store::printAvailblePrdcts() const
{
	for (int i = 0; i < count; i++)
	{
		products[i].productInfo();
	}
}

void Store::removeAt(Product * arr, int size, int startFrom, int positions)
{
	int write = startFrom;
	int read = startFrom + positions;
	while (read < size)
	{
		arr[write++] = arr[read++];
	}
}

void Store::grow()
{
	Product * currProducts = new Product[size * 2];
		for (int i = 0; i < size; i++)
		{
			currProducts[i] = products[i];
		}
		delete[] products;
		products = currProducts;
		size *= 2;
}
