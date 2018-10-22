#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>

class Product
{
private:
	char * brand;
	char * model;
	char * category;
	double price;
	char * color;
	double sizeInInches;
	double cameraMpixels;
	int count;

	void Destroy();
	

public:
	char * SKU;

	Product();
	Product(char* SKU, char* brand, char* model, char * category, double price, char * color, double sizeInInches, double cameraMpixels, int count);
	~Product();
	friend std::istream & operator>>(std::istream & input, Product & currPrdct);
	friend std::ostream & operator<<(std::ostream & output, const Product & currPrdct);
	void productInfo() const;
	void changePrdct(char* SKU, char* brand, char* model, char * category, double price, char * color, double sizeInInches, double cameraMpixels, int count);
};
#endif // !PRODUCT_H
