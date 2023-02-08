#include "Inventory.h"

/***************************************************************************
Name: Phuong Uyen Dang
Assignment #1
Design and implement a C++ program that simulates a store’s automatic check out system
 ************************************************************************************/


// The data in the file is loaded into the product array. 
// Validate the maximum number of products.
Inventory::Inventory(string nameFile, int initialMaxProducts)
{
	if (initialMaxProducts > SIZE)
		maxProducts = 12;
	else
		maxProducts = initialMaxProducts;

	ifstream fin(nameFile);
	if (!fin.is_open())
	{
		cout << "error opening inventory.data";
		system("pause");
		exit(-1);
	}

	int index = 0;
	for (; index < maxProducts; index++)
	{
		fin >> products[index].productCode;
		if (fin.eof())
			break;
		fin.ignore(80, '\n');
		getline(fin, products[index].description);
		fin >> products[index].price;
	}
	noProducts = index;
}

// Writes all of the products in the array to an output file or the screen
// At the end of the report, indicate the number of products in the array. 
void Inventory::writeInventory(ostream& out) const
{
	out << fixed << setprecision(2);
	out << left << setw(30) << "Product Code" << setw(20) << right << "Description" <<
		setw(20) << right << "Price" << endl << endl;
	for (int ctr = 0; ctr < noProducts; ctr++)
	{
		out << left << setw(30) << products[ctr].productCode << setw(20) << right << products[ctr].description <<
			setw(20) << right << products[ctr].price << endl;
	}
	out << endl;
	out << "Number of products is " << getNoProducts() << endl;
}

// Search the array of type ProductRec for a specific product code.
int Inventory::searchProduct(int newProductCode)
{
	int pos = 0;
	for (; pos < noProducts; pos++)
	{
		if (products[pos].productCode == newProductCode)
			break;
	}
	if (pos < noProducts)
		return pos;
	else
		return pos = noProducts;
}

// Display the product’s description and price 
void Inventory::showProduct(int initialCode)
{
	int position = searchProduct(initialCode);
	if (position == noProducts)
		cout << "We couldn't find this product" << endl;
	else
		cout << "Product code " << initialCode << " is " << products[position].description << 
				", it costs $" << products[position].price << endl;
}


void Inventory::increasePrice(int code, double addPrice)
{
	int posProduct = searchProduct(code);
	if (posProduct == noProducts)
		cout << "This product doesn't exist" << endl;
	else {
		products[posProduct].price += addPrice;
		if (products[posProduct].price > 1000)
		{
			products[posProduct].price = 1000;
			cout << "The maximum price of $1000 was assigned" << endl;
		}
	
	}
}
