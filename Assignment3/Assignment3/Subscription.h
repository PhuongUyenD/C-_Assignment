#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>

// Name: Phuong Uyen Dang
// Assignment 3: Write a program that  to keep track of its magazine subscriptions.
//  specification file
using namespace std;

struct Magazine
{
	string name;
	string isbn;
	char delivery;
	Magazine* link;
};

class Subscription
{
public:
	Subscription(string/*distributor*/); // constructor
	~Subscription(); // destructor
	void showMagazines(ostream& /*out*/) const;
	void addMagazine(string /*name*/, string /*isbn*/, char/*delivery*/);
	void removeMagazine(string /*isbn*/);
	int getNoMagazines() const { return numbMagazines; }
	string getDistributortName() const { return distributor; }
private:
	Magazine* firstPtr;
	string distributor;
	int numbMagazines;
};