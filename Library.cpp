/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the Library class.  It has a constructor
** that sets the date of a class object to 0. It has functions to add patons and library items to the database.
** It has functions to check out, request and return libraryItems. It also has functions to return info about 
** stored LibraryItems and Patrons. It has a function to pay fines and increment the date.
********************************************************************************************************/
#include "Library.hpp"

/***************************************************************************************************************
*						Library::Library
* This constructor sets the currentDate to 0.
****************************************************************************************************************/
Library::Library()
{
	currentDate = 0;
}
/***************************************************************************************************************
*						Library::addLibraryItem
* This function takes a pointer to LibraryItem as an argument and stores it in the holdings vector
****************************************************************************************************************/
void Library::addLibraryItem(LibraryItem *lib)
{
	holdings.push_back(lib);
}
/***************************************************************************************************************
*						Library::addPatron
* This function takes a pointer to Patron as an argument and stores it in the members vector
****************************************************************************************************************/
void Library::addPatron(Patron *pat)
{
	members.push_back(pat);
}
/***************************************************************************************************************
*						Library::checkOutLibraryItem
* This function takes an Id for a patron and an Id for an item and records that item as having been checked out by
* the patron, along with updating the relevant parameters.
****************************************************************************************************************/
std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
	//get the pointers for the patron and item
	Patron *pat = getPatron(patronID);
	LibraryItem *lib = getLibraryItem(ItemID);

	if (pat == NULL) //if patron is not on record
		return "patron not found";
	else if (lib == NULL) //if item is not on record
		return "Item not found";
	else if (lib->getLocation() == CHECKED_OUT) //item is already checked out
		return "Item already checked out.";
	else if (lib->getLocation() == ON_HOLD_SHELF && lib->getRequestedBy() != pat) //item is being held by someone other than the patron
		return "Item on hold by another patron.";
	else
	{
		lib->setCheckedOutBy(pat); 
		lib->setDateCheckedOut(currentDate);
		lib->setLocation(CHECKED_OUT);
		if (lib->getRequestedBy() == pat) //if the book was on hold for the patron
		{
			lib->setRequestedBy(pat);  //this resets the requestedBy value to NULL, so someone else may request it.
		}
		pat->addLibraryItem(lib); //adds the item to patron's checked out items.
		return "Check out successful";
	}
		
}
/***************************************************************************************************************
*						Library::returnLibraryItem
* This function takes an Id for an item and records that item as having been returned by
* the patron, along with updating the relevant parameters.
****************************************************************************************************************/
std::string Library::returnLibraryItem(std::string ItemID)
{
	//get pointers to item and patron
	LibraryItem *lib = getLibraryItem(ItemID);
	Patron *pat = lib->getCheckedOutBy();
	if (lib == NULL) //if item is not on record
	{
		return "Item not found";
	}
	else if (lib->getLocation() == ON_SHELF) //if item is somehow already returned
	{
		return "Item already in library";
	}
	pat->removeLibraryItem(lib); //removes the item from the patrons checked-out items.
	if (lib->getRequestedBy() != NULL) //if someone else requested the item.
	{
		lib->setLocation(ON_HOLD_SHELF); //puts item on hold shelf
	}
	else
	{
		lib->setLocation(ON_SHELF); //if no request, put on normal shelf
	}
	lib->setCheckedOutBy(NULL); //reset checked out status of item
	return "return successful";

}
/***************************************************************************************************************
*						Library::requestLibraryItem
* This function takes an Id for a patron and an item and records that item as having been requested by
* the patron, along with updating the relevant parameters.
****************************************************************************************************************/
std::string Library::requestLibraryItem(std::string patronID, std::string ItemID)
{
	//get pointers for the patron and item
	Patron *pat = getPatron(patronID);
	LibraryItem *lib = getLibraryItem(ItemID);

	if (pat == NULL) //patron not on record
		return "patron not found";
	else if (lib == NULL) // item not on record
		return "Item not found";
	else if (lib->getRequestedBy() != NULL) //item is already on hold by someone else
		return "Item already on hold";
	else
	{
		lib->setRequestedBy(pat);
		if (lib->getLocation() == 0) //checks if item is on shelf
		{
			lib->setLocation(ON_HOLD_SHELF); //puts it on hold shelf
		}
		return "request successful";
	}
}
/***************************************************************************************************************
*						Library::payFine
* This function takes an Id for a patron and a payment amount and updates the amount the patrom owes to reflect the
* payment
****************************************************************************************************************/
std::string Library::payFine(std::string patronID, double payment)
{
	Patron *pat = getPatron(patronID); //get patron pointer
	if (pat == NULL) //patron not on record
		return "patron not found";
	pat->amendFine(payment); //subtracts payment from total
	return "payment successful";
}
/***************************************************************************************************************
*						Library::IncrementCurrentDate
* This function increments the date by one each time. But it also is responsible for checking and imposing fines
* for late fees. 
****************************************************************************************************************/
void Library::incrementCurrentDate()
{
	double fine = -0.10; //fine amount to be added to patron's fine
	currentDate++; //increments the date
	int size = members.size();
	for (int i = 0; i < size; i++) //goes through all members
	{
		std::vector<LibraryItem*> vec1 = members[i]->getCheckedOutItems(); //vec1 contains the items that the current patron checked out
		int sizeItems = vec1.size();
		for (int j = 0;j < sizeItems; j++) //goes through each item
		{
			int cODate = vec1[j]->getDateCheckedOut(); //gets date checked out
			int len = vec1[j]->getCheckOutLength(); //get the check out length
			if (currentDate - cODate > len) //checks if the item is overdue
			{
				members[i]->amendFine(fine); //adds a fine per overdue item each day.
			}
		}
	}
}
/***************************************************************************************************************
*						Library::getPatron
* This function takes an Id for a Patron and returns a pointer to the patron.
****************************************************************************************************************/
Patron * Library::getPatron(std::string patronID)
{
	int size = members.size();
	for (int i = 0; i < size; i++) //searches through members vector
	{
		if (members[i]->getIdNum() == patronID)
			return members[i]; //returns the pointer when it finds a match
	}
	return NULL; //cannot find the a patron with that id
}
/***************************************************************************************************************
*						Library::getLibraryItem
* This function takes an Id for an item and returns a pointer to the item.
****************************************************************************************************************/
LibraryItem * Library::getLibraryItem(std::string ItemID)
{
	int size = holdings.size();
	for (int i = 0; i < size; i++) //searches through holdings vector
	{
		if (holdings[i]->getIdCode() == ItemID)
			return holdings[i]; //returns pointer when it finds a match
	}
	return NULL; //cannot find a LibraryItem with that id
}
