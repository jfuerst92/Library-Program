/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the Patron class.  It has a constructor
** that sets the the name and id of a patron to the arguments, and sets fineAmount to zero. It has get 
** functions for all of these fields. It also has a functions to remove and add a LibraryItem to the patron's
**list of checked out items. Finally it has a function to increase or decrease late fee amount.
********************************************************************************************************/
#include "Patron.hpp"
#include <iostream>
using std::cout;
using std::endl;

/***************************************************************************************************************
*						Patron::Patron
* This constructor takes two strings and sets them to the value for idNum and name. It sets fineAmount to 0.
****************************************************************************************************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0;
}
/***************************************************************************************************************
*						Patron::getIdNum
* This function returns the idNum.
****************************************************************************************************************/
std::string Patron::getIdNum()
{
	return idNum;
}
/***************************************************************************************************************
*						Patron::getName
* This function returns the patron's name.
****************************************************************************************************************/
std::string Patron::getName()
{
	return name;
}
/***************************************************************************************************************
*						Patron::getCheckedOutItems
* This function returns the vector containing all the items the patron has checked out.
****************************************************************************************************************/
std::vector<LibraryItem*> Patron::getCheckedOutItems()
{
	return checkedOutItems;
}
/***************************************************************************************************************
*						Patron::addLibraryItem
* This function adds a checked out LibraryItem to the end of the checkedOutItems vector
****************************************************************************************************************/
void Patron::addLibraryItem(LibraryItem * b)
{
	checkedOutItems.push_back(b);
}
/***************************************************************************************************************
*						Patron::removeLibraryItem
* This function removes a checked out LibraryItem from the checkedOutItems vector
****************************************************************************************************************/
void Patron::removeLibraryItem(LibraryItem * b)
{
	int size = checkedOutItems.size();
	for (int i = 0; i < size; i++) //searches through vector
	{
		if (checkedOutItems[i] == b) //looks for matching item
		{
			checkedOutItems.erase(checkedOutItems.begin() + i); //removes it
		}
	}
}
/***************************************************************************************************************
*						Patron::getFineAmount
* This function returns the fineAmount
****************************************************************************************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}
/***************************************************************************************************************
*						Patron::amendFine
* This function subtracts the amount in the argument from the current fineAmount. A negative argument adds money
* to the fineAmount
****************************************************************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount = getFineAmount() - amount;
	
}
