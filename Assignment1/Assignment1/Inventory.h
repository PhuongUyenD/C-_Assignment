#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/***************************************************************************
Name: Phuong Uyen Dang
Assignment #1
Design and implement a C++ program that simulates a store’s automatic check out system
 ************************************************************************************/

//The ProductRec struct contains a product code, description and price.
struct ProductRec {
	int productCode;
	string description;
	double price;
};

const int SIZE = 25;

class Inventory
{
public:
	void showProduct(int /*productCode*/);
	void writeInventory(ostream& /*output file*/) const;
	int getNoProducts() const { return noProducts; }
	void increasePrice(int /*productCode*/, double /*price*/);

	Inventory(string/*inventory.data*/, int = 25/*maxProducts*/);

private:
	int maxProducts;
	int noProducts;
	ProductRec products[SIZE];
	int searchProduct(int /*productCode*/);
};



