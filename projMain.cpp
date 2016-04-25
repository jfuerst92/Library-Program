#include "Library.hpp"
#include <iostream>

using namespace std;

int main()
{
	//Tests for each function
	Book b1("123", "War and Peace", "Tolstoy");
	cout << b1.getTitle() << ", " << b1.getIdCode() << ", " << b1.getAuthor() << endl;
	Book b2("234", "Moby Dick", "Melville");
	cout << b2.getTitle() << ", " << b2.getIdCode() << ", " << b2.getAuthor() << endl;
	Book b3("345", "Phantom Tollbooth", "Juster");
	cout << b3.getTitle() << ", " << b3.getIdCode() << ", " << b3.getAuthor() << endl;
	Patron p1("abc", "Felicity");
	cout << p1.getName() << ", " << p1.getIdNum() << endl;
	Patron p2("bcd", "Waldo");
	cout << p2.getName() << ", " << p2.getIdNum() << endl;
	Library lib;
	lib.addLibraryItem(&b1);
	lib.addLibraryItem(&b2);
	lib.addLibraryItem(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	cout << lib.requestLibraryItem("bcd", "234") << endl; //waldo requests moby dick
	cout << lib.checkOutLibraryItem("bcd", "234") << endl; //waldo checks out moby dick
	cout << lib.checkOutLibraryItem("abc", "234") << endl; //felicity checks out moby dick, fails
	cout << lib.requestLibraryItem("abc", "234") << endl; //felicity requests moby dick, 
	cout << lib.returnLibraryItem("234") << endl; //waldo returns moby dick, it goes to hold shelf
	cout << lib.checkOutLibraryItem("cde", "234") << endl; //someone doesnt have an account yet
	cout << lib.checkOutLibraryItem("bcd", "2134") << endl; //waldo checks out a book that they dont have
	cout << lib.checkOutLibraryItem("bcd", "234") << endl; //waldo checks out moby dick, fails
	cout << lib.requestLibraryItem("bcd", "234") << endl; //waldo requests moby dick, fails
	for (int i = 0; i<7; i++)
		lib.incrementCurrentDate();
	cout << lib.checkOutLibraryItem("bcd", "123") << endl; //waldo checks out war and peace
	cout << lib.checkOutLibraryItem("abc", "345") << endl; //felicity checks out juster
	for (int i = 0; i<24; i++)
		lib.incrementCurrentDate();
	double p2Fine = p2.getFineAmount();
	cout << "$" << p2Fine << " is waldo's fine.";
	cout << lib.payFine("bcd", 1.4) << endl; //waldo pays 140 cents towards his fine
	double p1Fine = p1.getFineAmount();
	p2Fine = p2.getFineAmount();
	cout << "$" << p1Fine << " is Felicity's fine." << endl;
	cout << "$" << p2Fine << " is waldo's fine.";

	return 0;
}