/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class header file for the Book class. It inherits the LibraryItem class. It
** has a string to hold the name of the author. It has a static const int to store the max check out length
** It has a constructor to set title, id and author. It has a function to set and get author. And it also
** has a method to return CHECK_OUT_LENGTH
********************************************************************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "LibraryItem.hpp"

using std::string;

class Book : public LibraryItem
{
private:
	string author;
public:
	static const int CHECK_OUT_LENGTH = 21;
	Book(string, string, string);
	void setAuthor(string);
	string getAuthor();
	int getCheckOutLength();
};

#endif