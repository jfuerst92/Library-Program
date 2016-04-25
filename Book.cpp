/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the Book class. It inherits the LibraryItem class.
** It has a static const int to store the max check out length. It has a constructor to set title, id and
**author. It has a function to set and get author. And it also has a method to return CHECK_OUT_LENGTH
********************************************************************************************************/
#include "Book.hpp"
/***************************************************************************************************************
*						Book::Book
* This constructor calls the base constructor for libraryItem and also sets author to aut
****************************************************************************************************************/
Book::Book(string t, string id, string aut) : LibraryItem(t, id)
{
	setAuthor(aut);
}
/***************************************************************************************************************
*						Book::setAuthor
* This function sets author to aut
****************************************************************************************************************/
void Book::setAuthor(string aut)
{
	author = aut;
}
/***************************************************************************************************************
*						Book::setAuthor
* This function returns author
****************************************************************************************************************/
string Book::getAuthor()
{
	return author;
}
/***************************************************************************************************************
*						Book::getCheckOutLength
* This function returns the max check out time for a Book
****************************************************************************************************************/
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}
