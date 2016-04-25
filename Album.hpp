/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class header file for the Album class. It inherits the LibraryItem class. It
** has a string to hold the name of the artist. It has a static const int to store the max check out length
** It has a constructor to set title, id and artist. It has a function to set and get artist. And it also
** has a method to return CHECK_OUT_LENGTH
********************************************************************************************************/
#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include "LibraryItem.hpp"

using std::string;

class Album : public LibraryItem
{
private:
	string artist;
public:
	static const int CHECK_OUT_LENGTH = 14;
	Album(string, string, string);
	void setArtist(string);
	string getArtist();
	int getCheckOutLength();
};

#endif