#include "Product.h"
#include <fstream>

// Name: Phuong Uyen Dang
// Assignment 2: Write a program that simulates a store’s automatic check out system


// class Product
Product::Product(int newBarCode, string newProductName)
{
	productName = new string(newProductName.length() == 0 ? "NO NAME" : newProductName);
	assert(productName != NULL);
	barCode = newBarCode < 0 || newBarCode > 100 ? 0 : newBarCode;
}

Product::Product()
{
	productName = new string;
	assert(productName != NULL);
	cout << "Enter product name: ";
	getline(cin, *productName);
	while (productName->empty())
	{
		cout << "you must enter product name, re-enter: ";
		getline(cin, *productName);
	}

	cout << "Enter bar code of product: ";
	cin >> barCode;
	while (cin.fail() || barCode < 0 || barCode > 10000)
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Error must be 0-10000, re-enter: ";
		cin >> barCode;
	}
	cin.ignore(80, '\n');
}

void Product::show(ostream& out) const
{
	out << "Product name: " << *productName << " has bar code = " << barCode << endl;
}

Product::~Product()
{
	delete  productName;
}


// class PrePackedFood
PrePackedFood::PrePackedFood(int newBarCode, string newProductName, double newUnitPrice) :
	Product(newBarCode, newProductName)
{
	unitPrice = newUnitPrice < 0 || newUnitPrice > 1000.0 ? 0 : newUnitPrice;
}

PrePackedFood::PrePackedFood()
{
	cout << "Enter the unit price: ";
	cin >> unitPrice;
	while (cin.fail() || unitPrice < 0 || unitPrice > 1000.0)
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Error must be 0-1000.0, re-enter: ";
		cin >> unitPrice;
	}
	cin.ignore(80, '\n');
}

void PrePackedFood::show(ostream& out) const
{
	Product::show(out);
	out << "The unit price = " << unitPrice << endl;
}


// class FreshFood
FreshFood::FreshFood(int newbarCode, string newProductName, double newUnitPrice, double newWeight) :
	Product(newbarCode, newProductName)
{
	unitPrice = newUnitPrice < 0 || newUnitPrice > 1000.0 ? 0 : newUnitPrice;
	weight = newWeight < 0 || newWeight > 500.0 ? 0 : newWeight;
}

FreshFood::FreshFood()
{
	cout << "Enter the weight of product: ";
	cin >> weight;
	while (weight < 0 || weight > 1000.0)
	{
		cout << "Error must be 0-1000.0, re-enter: ";
		cin >> weight;
	}
	cout << "Enter the price per gram: ";
	cin >> unitPrice;
	while (cin.fail() || unitPrice < 0 || unitPrice > 1000.0)
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Error must be 0-1000.0, re-enter: ";
		cin >> unitPrice;
	}
}

void FreshFood::show(ostream& out) const
{
	Product::show(out);
	out << "Weight = " << weight << ", the price per gram = " << unitPrice << endl;
	out << "The total price of this product = " << weight * unitPrice << endl;
}


