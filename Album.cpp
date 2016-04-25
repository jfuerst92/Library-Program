/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the Album class. It inherits the LibraryItem class.
** It has a static const int to store the max check out length. It has a constructor to set title, id and
** artist. It has a function to set and get artist. And it also has a method to return CHECK_OUT_LENGTH
********************************************************************************************************/
#include "Album.hpp"
/***************************************************************************************************************
*						Album::Album
* This constructor calls the base constructor for libraryItem and also sets artist to art
****************************************************************************************************************/
Album::Album(string t, string id, string art) : LibraryItem(t, id)
{
	setArtist(art);
}
/***************************************************************************************************************
*						Album::setArtist
* This function sets artist to art
****************************************************************************************************************/
void Album::setArtist(string art)
{
	artist = art;
}
/***************************************************************************************************************
*						Album::setArtist
* This function returns artist
****************************************************************************************************************/
string Album::getArtist()
{
	return artist;
}
/***************************************************************************************************************
*						Album::getCHeckOutLength
* This function returns the max check out time for an album
****************************************************************************************************************/
int Album::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}
