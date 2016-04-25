/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the LibraryItem class.  It has a constructor
** that sets the data of a class object. It has two set functions to get patron check out and request info.
** It also has get methods for every field in the object.
********************************************************************************************************/
#include "LibraryItem.hpp"
/***************************************************************************************************************
*						LibraryItem::LibraryItem
* This constructor takes two strings and sets them to the value for idCode and title. It initializes checkedOutBy
and requestedBy to NULL, and sets location to ON_SHELF
****************************************************************************************************************/
LibraryItem::LibraryItem(std::string idc, std::string t)
{
	idCode = idc;
	title = t;
	checkedOutBy = NULL;
	requestedBy = NULL;
	location = ON_SHELF;
}
/***************************************************************************************************************
*						LibraryItem::getIdCode
* This function returns the value for IdCode
****************************************************************************************************************/
std::string LibraryItem::getIdCode()
{
	return idCode;
}
/***************************************************************************************************************
*						LibraryItem::getTitle
* This function returns the value for title
****************************************************************************************************************/
std::string LibraryItem::getTitle()
{
	return title;
}
/***************************************************************************************************************
*						LibraryItem::getLocation
* This function returns the value for location
****************************************************************************************************************/
Locale LibraryItem::getLocation()
{
	return location;
}
/***************************************************************************************************************
*						LibraryItem::setLocation
* This function takes a Locale enum and sets it to location
****************************************************************************************************************/
void LibraryItem::setLocation(Locale loc)
{
	location = loc;
}
/***************************************************************************************************************
*						LibraryItem::getCHeckedOutBy
* This function returns a pointer to the person who checked out the item.
****************************************************************************************************************/
Patron * LibraryItem::getCheckedOutBy()
{
	return checkedOutBy;
}
/***************************************************************************************************************
*						LibraryItem::setCHeckedOutBy
* This takes a pointer to a Patron and sets it to checkedOutBy
****************************************************************************************************************/
void LibraryItem::setCheckedOutBy(Patron *pat)
{
	checkedOutBy = pat;
}
/***************************************************************************************************************
*						LibraryItem::getRequestedBy
* This function returns a pointer to the person who requested the item.
****************************************************************************************************************/
Patron * LibraryItem::getRequestedBy()
{
	return requestedBy;
}
/***************************************************************************************************************
*						LibraryItem::setRequestedBy
* This takes a pointer to a Patron and sets it to requestedBy only if the item has not already been requested.
* If the same patron had already requested the book, it sets requestedBy to NULL. This second part is used by the 
* checkOutLibraryItem function in Library.cpp. It indicates that the patron that requested the book has picked it up.
****************************************************************************************************************/
void LibraryItem::setRequestedBy(Patron *pat)
{
	if (requestedBy == NULL) //checks that the book is not already requested
	{
		requestedBy = pat;
		if (location != CHECKED_OUT)
			location = ON_HOLD_SHELF; //if its not checked out, its moved to the hold shelf
	}
	else if (requestedBy == pat) //this unrequests the book when pat picks it up.
	{
		requestedBy = NULL;
	}
}
/***************************************************************************************************************
*						LibraryItem::getDateCheckedOut
* This function returns the date the item was checked out.
****************************************************************************************************************/
int LibraryItem::getDateCheckedOut()
{
	return dateCheckedOut;
}
/***************************************************************************************************************
*						LibraryItem::setDateCheckedOut
* This function takes an int as an argument and sets it to the dateCheckedOut.
****************************************************************************************************************/
void LibraryItem::setDateCheckedOut(int date)
{
	dateCheckedOut = date;
}
