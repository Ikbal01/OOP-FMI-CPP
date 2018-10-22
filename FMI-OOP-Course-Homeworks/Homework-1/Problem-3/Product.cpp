#include"Product.h"
#include<iostream>

Product::Product()
{
	SKU = new char[50];
	brand = new char[50];
	model = new char[50];
	category = new char[50];
	price = 0.0;
	color = new char[50];
	sizeInInches = 0.0;
	cameraMpixels = 0.0;
	count = 0; 
}

Product::Product(char* SKU, char* brand, char* model, char * category, double price, char * color, double sizeInInches, double cameraMpixels, int count)
{
	this->SKU = SKU;
	this->brand = brand;
	this->model = model;
	this->category = category;
	this->price = price;
	this->color = color;
	this->sizeInInches = sizeInInches;
	this->cameraMpixels = cameraMpixels;
	this->count = count;
}

Product::~Product()
{
	Destroy();
}

std::istream & operator>>(std::istream & input, Product & currPrdct)
{
	std::cout << "SKU:\n";
	input >> currPrdct.SKU;
	std::cout << "brand:\n ";
	input >> currPrdct.brand;
	std::cout << "model:\n";
	input >> currPrdct.model;
	std::cout << "category:\n";
	input >> currPrdct.category;
	std::cout << "price:\n";
	input >> currPrdct.price;
	std::cout << "color:\n";
	input >> currPrdct.color;
	std::cout << "size in inches:\n";
	input >> currPrdct.sizeInInches;
	std::cout << "megapixels:\n";
	input >> currPrdct.cameraMpixels;
	std::cout << "count:\n";
	input >> currPrdct.count;

	return input;
}
std::ostream & operator<<(std::ostream & output, const Product & currPrdct)
{
	
	output << "SKU: " << currPrdct.SKU << "\nBrand: " << currPrdct.brand << "\nModel: " << currPrdct.model << "\nCategory: " << currPrdct.category << "\nPrice: " << currPrdct.price << "\nColor: " << currPrdct.color << "\nSize In Inches: " << currPrdct.sizeInInches << "\nCamera: " << currPrdct.cameraMpixels << " megapixels\n" << currPrdct.count << " left in stock\n";
	return output;
}

void Product::productInfo() const
{
	std::cout << "SKU: " << SKU << "\nBrand: " << brand << "\nModel: " << model << "\nCategory: " << category << "\nPrice: " << price << "\nColor: " << color << "\nSize In Inches: " << sizeInInches << "\nCamera: " << cameraMpixels << " megapixels" << "\n" << count << " left in stock\n";
}

void Product::changePrdct(char* SKU, char* brand, char* model, char * category, double price, char * color, double sizeInInches, double cameraMpixels, int count)
{
	this->SKU = SKU;
	this->brand = brand;
	this->model = model;
	this->category = category;
	this->price = price;
	this->color = color;
	this->sizeInInches = sizeInInches;
	this->cameraMpixels = cameraMpixels;
	this->count = count;
}

void Product::Destroy()
{
	delete[] SKU;
	delete[] brand;
	delete[] model;
	delete[] category;
	delete[] color;
}

