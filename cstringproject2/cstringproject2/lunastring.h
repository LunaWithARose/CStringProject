////
// Name: Luna Waller
// Program Name: LunaString
//
// Description: String functions that holds a string. 
////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#ifndef LUNASTRING_H
#define LUNASTRING_H

using namespace std;

class LunaString {
	public:
		LunaString();	 //creates an empty string;
		LunaString(const char* inputString); //takes an input string and stores it.
		LunaString(const LunaString& InputClass); // copy constructor
		~LunaString(); //destructor 

		char at(int x);  //returns the character at an index
		int length();    //returns the length of the string
		int capacity();  //returns the capacity of the string
		void capacity(int newCap); //changed the capacity of a class if need be
		char* c_str(); // returns pointer to the str array

		int compareTo(const LunaString& InputClass); //returns negative if the arg string is less than the str in the class, positive if opposite, equal if the same
		void setEqualTo(const char* inputClass);

		char operator[](int index);  //same as at function without bound checking
		LunaString& operator+(const LunaString& rhs); //adds rhs to the lhs
		LunaString& operator=(const LunaString& InputClass); //sets lhs to rhs

		bool operator<(const LunaString& rhs); // returns true if lhs is greater than rhs
		bool operator>(const LunaString& rhs); // opposite of above
		bool operator==(const LunaString& rhs); //returns true if they are equal.

		bool friend operator>>(istream& istrm, LunaString& InputClass); //Friend key word allows them to be non-member 
		void friend operator<<(ostream& ostrm, LunaString& InputClass); //func but still access private data

		int getCurrentCount(); //returns current count
		int getCreatedCount(); //returns created count
	private:
		int cap;
		char* str = nullptr;
		int end;
		static int currentCount;
		static int createdCount;
};



#endif