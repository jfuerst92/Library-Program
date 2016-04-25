/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class header file for the Movie class. It inherits the LibraryItem class. It 
** has a string to hold the name of the director. It has a static const int to store the max check out length
** It has a constructor to set title, id and director. It has a function to set and get director. And it also
** has a method to return CHECK_OUT_LENGTH
********************************************************************************************************/
#ifndef MOVIE_HPP
#define MOVIE_HPP
#include <string>
#include "LibraryItem.hpp"

using std::string;

class Movie : public LibraryItem
{
private:
	string director;
public:
	static const int CHECK_OUT_LENGTH = 7;
	Movie(string, string, string);
	void setDirector(string);
	string getDirector();
	int getCheckOutLength();
};

#endif