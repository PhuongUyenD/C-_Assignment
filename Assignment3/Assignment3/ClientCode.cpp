#include "Subscription.h"

// Name: Phuong Uyen Dang
// Assignment 3: Write a program that  to keep track of its magazine subscriptions.
// Client code

int main()
{
	//a 
	Subscription* book = new Subscription("News Mailer");
	cout << book->getDistributortName() << endl << endl;
	//b
	book->addMagazine("Geographic", "0234", 'd');
	book->addMagazine("Life", "1453", 'm');
	book->addMagazine("Economist", "5674", 'w');
	book->addMagazine("People", "6587", 'd');
	book->addMagazine("Country Gardens", "1453", 'd');
	book->addMagazine("Economist", "5674", 'w');
	book->addMagazine("Sunset", "5421", 'm');
	book->addMagazine("InStyle", "1093", 'w');
	//c
	book->showMagazines(cout);
	//d
	book->removeMagazine("0234");
	book->showMagazines(cout);
	book->removeMagazine("6587");
	book->showMagazines(cout);
	book->removeMagazine("5421");
	book->showMagazines(cout);
	book->removeMagazine("6587");
	book->showMagazines(cout);
	//e
	book->showMagazines(cout);

	delete book;

	system("pause");

}

/*
News Mailer

Economist already exists
Distributor Name:             News Mailer
Magazine Name       ISBN              Delivery Type

Country Gardens     1453              Daily

Economist           5674              Weekly

Geographic          0234              Daily

InStyle             1093              Weekly

Life                1453              Monthly

People              6587              Daily

Sunset              5421              Monthly

# of magazines = 7



0234 was deleted
Distributor Name:             News Mailer
Magazine Name       ISBN              Delivery Type

Country Gardens     1453              Daily

Economist           5674              Weekly

InStyle             1093              Weekly

Life                1453              Monthly

People              6587              Daily

Sunset              5421              Monthly

# of magazines = 6



6587 was deleted
Distributor Name:             News Mailer
Magazine Name       ISBN              Delivery Type

Country Gardens     1453              Daily

Economist           5674              Weekly

InStyle             1093              Weekly

Life                1453              Monthly

Sunset              5421              Monthly

# of magazines = 5



5421 was deleted
Distributor Name:             News Mailer
Magazine Name       ISBN              Delivery Type

Country Gardens     1453              Daily

Economist           5674              Weekly

InStyle             1093              Weekly

Life                1453              Monthly

# of magazines = 4



ISBN not found
Distributor Name:             News Mailer
Magazine Name       ISBN              Delivery Type

Country Gardens     1453              Daily

Economist           5674              Weekly

InStyle             1093              Weekly

Life                1453              Monthly

# of magazines = 4



Distributor Name:             News Mailer
Magazine Name       ISBN              Delivery Type

Country Gardens     1453              Daily

Economist           5674              Weekly

InStyle             1093              Weekly

Life                1453              Monthly

# of magazines = 4

Press any key to continue . . .

*/