#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

// Name: Phuong Uyen Dang
// Assignment 2: Write a program that simulates a store’s automatic check out system


using namespace std;

// Specification file
class Product
{
public:
	Product();
	Product(int /*barCode*/, string /*productName*/);
	virtual ~Product(); // destructor
	virtual void show(ostream& /*file or console*/) const;
	int getBarCode() const { return barCode; }
	string getProductName() const { return *productName; }
protected: //  Allow any derived class access to the data members.
	int barCode;
	string* productName;
};

class FreshFood : public Product
{
public:
	FreshFood();
	FreshFood(int /*barCode*/, string /*productName*/, double /*unitPrice*/, double /*weight*/);
	void show(ostream& /*file or console*/) const;
	double getUnitPrice() const { return unitPrice; }
	double getWeight() const { return weight; }
private:
	double unitPrice;
	double weight;
};

class PrePackedFood : public Product
{
public:
	PrePackedFood();
	PrePackedFood(int /*barCode*/, string /*productName*/, double /*unitPrice*/);
	void show(ostream& /*file or console*/) const;
	double getUnitPrice() const { return unitPrice; }
private:
	double unitPrice;
};