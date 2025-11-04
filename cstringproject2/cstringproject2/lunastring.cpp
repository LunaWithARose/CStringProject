#include "lunastring.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int LunaString::createdCount = 0;
int LunaString::currentCount = 0;

LunaString::LunaString() {
	end = 0;
	cap = 20;
	str = new char[cap];
	str[end] = '\0';
	++createdCount;
	++currentCount;
}

LunaString::LunaString(const char* inputString) {
	int i = 0;
	cap = 20;
	while (inputString[i] != '\0') {
		i++;
	}
	while(i >= cap){
		cap = cap + 20;
	}
	end = i;
	str = new char[cap];
	for (i = 0; i < end; i++) {
		str[i] = inputString[i];
	}
	str[end] = '\0';
	++createdCount;
	++currentCount;
}

LunaString::LunaString(const LunaString& InputClass) {
	cap = InputClass.cap;
	end = InputClass.end;
	str = new char[cap];
	for (int i = 0; i < end; i++) {
		str[i] = InputClass.str[i];
	}
	str[end] = '\0';
	++createdCount;
	++currentCount;
}

LunaString::~LunaString() {
	delete[] str;
	str = nullptr;
	--currentCount;
}

LunaString& LunaString::operator=(const LunaString& InputClass) {
	if (this != &InputClass) {
		delete[] str;
		cap = InputClass.cap;
		str = new char[cap];
		end = InputClass.end;
		for (int i = 0; i < cap; ++i) {
			str[i] = InputClass.str[i];
		}
	}
	return *this;
}

char LunaString::at(int index) {
	char output;
	if (index >= 0 && index < end) {
		output = str[index];
		return output;
	}
	else {
		throw runtime_error("Out of bounds");
	}
}

int LunaString::capacity() {
	return cap;
}

int LunaString::length() {
	return end;
}

int LunaString::compareTo(const LunaString& InputClass) {
	int shortestLen = (end < InputClass.end ? end : InputClass.end);
	int dif;

	for (int i = 0; i <= shortestLen; ++i) {
		dif = tolower(str[i]) - tolower(InputClass.str[i]);
		if (dif != 0) {
			return dif;
		}
	}

	return 0;			
}

char* LunaString::c_str() {
	return str;
}


void LunaString::setEqualTo(const char* inputString) {
	delete[] str;
	int i = 0;
	while (inputString[i] != '\0') {
		i++;
	}
	end = i + 1;
	cap = i + 1;
	str = new char[cap];
	for (i = 0; i < end; i++) {
		str[i] = inputString[i];
	}
}


bool operator>>(istream& istrm, LunaString& InputClass){ 
	if (istrm.good()) {
		char inputStr[100];
		istrm >> inputStr;
		for (InputClass.end = 0; inputStr[InputClass.end] != '\0'; InputClass.end++);

		InputClass.capacity(((InputClass.end/20) + 1)*20);
		for (int j = 0; j <= InputClass.end; j++) {
			InputClass.str[j] = inputStr[j];
		}
		if (InputClass.str[InputClass.end - 1] == '.' || InputClass.str[InputClass.end - 1] == ',' || InputClass.str[InputClass.end - 1] == '?' || InputClass.str[InputClass.end - 1] == '!' || InputClass.str[InputClass.end - 1] == ';' || InputClass.str[InputClass.end - 1] == ':') {
			InputClass.end = InputClass.end - 1; 
			InputClass.str[InputClass.end] = '\0';
		}
		return true;
	}
	else {
		return false;
	}
}

void operator<<(ostream& ostrm, LunaString& InputClass) {
	ostrm << InputClass.str;
}

char LunaString::operator[](int index){
	return str[index];
}

void LunaString::capacity(int newCap) {
	char* newStr = new char[newCap];
	for (int i = 0; i <= end; i++) {
		newStr[i] = str[i];
	}
	delete[] str;
	str = newStr;
	cap = newCap;
}

LunaString& LunaString::operator+(const LunaString& rhs) {
	this->capacity(cap + rhs.cap);
	for (int i = end; i < rhs.end + end; i++) {
		str[i] = rhs.str[i - end];
	}
	end = end + rhs.end;
	str[end] = '\0';
	return *this;
}

bool LunaString::operator>(const LunaString& rhs) {
	int shortestLen = (end < rhs.end ? end : rhs.end);

	for (int i = 0; i < shortestLen; i++) {
		if (tolower(str[i]) > tolower(rhs.str[i])) {
			return true;
		}
		else if (tolower(str[i]) == tolower(rhs.str[i])) {
		}
		else {
			return false;
		}
	}
	return false;
}

bool LunaString::operator<(const LunaString& rhs) {
	if (this->compareTo(rhs) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool LunaString::operator==(const LunaString& rhs) {
	if (this->compareTo(rhs) == 0) {
		return true;
	}
	else {
		return false;
	}
}

int LunaString::getCreatedCount() {
	return createdCount;
}

int LunaString::getCurrentCount() {
	return currentCount;
}