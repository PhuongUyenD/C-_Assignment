#include "Subscription.h"

// Name: Phuong Uyen Dang
// Assignment 3: Write a program that  to keep track of its magazine subscriptions.
// implementation file

// Constructor
Subscription::Subscription(string newDistributor)
{
	distributor = newDistributor;
	numbMagazines = 0;
	firstPtr = NULL;
}

// Destructor: delete all nodes in the list
Subscription::~Subscription()
{
	Magazine* walker = firstPtr;
	while (walker != NULL)
	{
		walker = walker->link;
		delete firstPtr;
		firstPtr = walker;
	}
}

// Displays all of the nodes in the list
void Subscription::showMagazines(ostream& out) const
{
	Magazine* walker = firstPtr;
	string result;
	if (firstPtr == NULL)
		out << "There are no magazines" << endl;
	else
	{
		out << left << setw(30) << "Distributor Name: " << distributor << endl;
		out << left << setw(20) << "Magazine Name"
			<< left << setw(18) << "ISBN"
			<< left << setw(3) << "Delivery Type" << endl << endl;
		while (walker != NULL)
		{
			result = (walker->delivery == 'D') ? "Daily" : (walker->delivery == 'W') ? "Weekly" : "Monthly";
			out << left << setw(20) << walker->name
				<< left << setw(18) << walker->isbn
				<< left << setw(3) << result
				<< endl << endl;

			walker = walker->link;
		}

		out << "# of magazines = " << getNoMagazines() << endl << endl;
		out << endl << endl;
	}
}

// Insert a noted into the list in ascending order by magazine name
void Subscription::addMagazine(string newName, string newISBN, char newDelivery)
{
	Magazine* stalker = NULL;
	Magazine* walker = firstPtr;

	while (walker != NULL)
	{
		if (walker->name >= newName)
			break;
		stalker = walker;
		walker = walker->link;
	}
	if (walker != NULL && walker->name == newName)
		cout << newName << " already exists" << endl;
	else
	{
		Magazine* builder = new Magazine;
		assert(builder != NULL);
		builder->name = newName == "" ? "No name" : newName;
		builder->isbn = newISBN == "" ? "No ISBN" : newISBN;
		builder->delivery = (toupper(newDelivery) != 'D' || toupper(newDelivery) != 'W' || toupper(newDelivery) != 'M') ? 'W' : toupper(newDelivery);
		builder->link = walker;
		if (walker == firstPtr) // list is empty
		{
			firstPtr = builder; // add to the beginning
			numbMagazines++;
		}
		else
		{
			stalker->link = builder;
			numbMagazines++;
		}
	}
}

//  Removes a node from the list
void Subscription::removeMagazine(string deleteISBN)
{
	Magazine* walker = firstPtr, * stalker = NULL;
	if (firstPtr == NULL)
		cout << "List is empty, nothing to delete" << endl;
	else
	{
		while (walker != NULL)
		{
			if (walker->isbn == deleteISBN)
				break;
			stalker = walker;
			walker = walker->link;
		}
		if (walker == NULL)
			cout << "ISBN not found" << endl;
		else
		{
			if (stalker == NULL) // node at start of list
				firstPtr = walker->link;
			else
				stalker->link = walker->link;
			delete walker;
			numbMagazines--;
			cout << deleteISBN << " was deleted" << endl;
		}
	}
}