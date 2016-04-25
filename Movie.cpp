/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for theMovie class. It inherits the LibraryItem class. 
** It has a static const int to store the max check out length. It has a constructor to set title, id and 
**director. It has a function to set and get director. And it also has a method to return CHECK_OUT_LENGTH
********************************************************************************************************/
#include "Movie.hpp"

/***************************************************************************************************************
*						Movie::Movie
* This constructor calls the base constructor for libraryItem and also sets director to dir
****************************************************************************************************************/
Movie::Movie(string t, string id, string dir) : LibraryItem(t, id)
{
	setDirector(dir);
}
/***************************************************************************************************************
*						Movie::setDirector
* This function sets director to dir
****************************************************************************************************************/
void Movie::setDirector(string dir)
{
	director = dir;
}
/***************************************************************************************************************
*						Movie::getDirector
* This function returns director
****************************************************************************************************************/
string Movie::getDirector()
{
	return director;
}
/***************************************************************************************************************
*						Movie::getCheckOutLength
* This function returns the max check out length for a Movie
****************************************************************************************************************/
int Movie::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}
