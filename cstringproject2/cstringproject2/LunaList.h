////
// Name: Luna Waller
// Program Name: LunaList
//
// Description: Creates a linked lists of 
// LunaStrings. Inserts them in alphabetical order.
////

#include "lunastring.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#ifndef LUNALIST_H
#define LUNALIST_H

using namespace std;

template <typename T>
class Node {
public:
	T nodeString;
	Node* nextNodeptr;
	Node* prevNodeptr;

	Node() {
		nextNodeptr = nullptr;
		prevNodeptr = nullptr;
	}
	Node(T input) {
		nextNodeptr = nullptr;
		prevNodeptr = nullptr;
		nodeString = input;
	}
};

template <typename T>
class DoubleLinkedList {
private:
	Node<T>* headNodeptr;
	Node<T>* tailNodeptr;
	mutable Node<T>* itNodeptr;
	int count;

public:
	DoubleLinkedList() {
		headNodeptr = nullptr;
		tailNodeptr = nullptr;
		itNodeptr = nullptr;
		count = 0;
	}

	DoubleLinkedList(DoubleLinkedList& dll) {
		dll.resetIteration();
		Node<T>* newNode = new Node<T>(dll.itNodeptr->nodeString);
		headNodeptr = newNode;
		tailNodeptr = newNode;
		dll.itNodeptr = dll.itNodeptr->nextNodeptr;
		itNodeptr = headNodeptr;
		count = dll.count;
		while (dll.hasMore()) {
			Node<T>* newNode = new Node<T>(dll.itNodeptr->nodeString);
			itNodeptr->nextNodeptr = newNode;
			newNode->prevNodeptr = itNodeptr;
			tailNodeptr = newNode;
			itNodeptr = newNode;
			dll.itNodeptr = dll.itNodeptr->nextNodeptr;
		}
	}

	DoubleLinkedList& operator=(DoubleLinkedList& dll) {
		dll.resetIteration();
		Node<T>* newNode = new Node<T>(dll.itNodeptr->nodeString);
		headNodeptr = newNode;
		tailNodeptr = newNode;
		dll.itNodeptr = dll.itNodeptr->nextNodeptr;
		itNodeptr = headNodeptr;
		count = dll.count;
		while (dll.hasMore()) {
			Node<T>* newNode = new Node<T>(dll.itNodeptr->nodeString);
			itNodeptr->nextNodeptr = newNode;
			newNode->prevNodeptr = itNodeptr;
			tailNodeptr = newNode;
			itNodeptr = newNode;
			dll.itNodeptr = dll.itNodeptr->nextNodeptr;
		}
		return *this;
	}

	~DoubleLinkedList() {
		headNodeptr = nullptr;
		tailNodeptr = nullptr;
		itNodeptr = nullptr;
		count = 0;
	}

	bool insert(const T& str) {
		Node<T>* newNode = new Node<T>(str);
	if (headNodeptr == nullptr) {
		headNodeptr = newNode;
		tailNodeptr = newNode;
		count++;
		return true;
	}
	else if (headNodeptr->nodeString > str) {
		newNode->nextNodeptr = headNodeptr;
		headNodeptr->prevNodeptr = newNode;
		headNodeptr = newNode;
		count++;
		return true;
	}
	else {
		itNodeptr = headNodeptr;
		while (itNodeptr != nullptr) {
			if (itNodeptr->nodeString == str) {
				return false;
			}
			else if (itNodeptr->nodeString > str) {
				newNode->prevNodeptr = itNodeptr->prevNodeptr;
				itNodeptr->prevNodeptr->nextNodeptr = newNode;
				newNode->nextNodeptr = itNodeptr;
				itNodeptr->prevNodeptr = newNode;
				count++;
				return true;
			}
			else {
				itNodeptr = itNodeptr->nextNodeptr;
			}
		}
		
		tailNodeptr->nextNodeptr = newNode;
		newNode->prevNodeptr = tailNodeptr;
		tailNodeptr = newNode;
		count++;
		return true;
	}
	}
	bool remove(const T& str) {
		itNodeptr = headNodeptr;
		while (itNodeptr != nullptr) {
			if (itNodeptr->nodeString == str) {
				if (itNodeptr == headNodeptr) {
					itNodeptr->nextNodeptr->prevNodeptr = nullptr;
					headNodeptr = itNodeptr->nextNodeptr;
					count--;
					return true;
				}
				else if (itNodeptr == tailNodeptr) {
					itNodeptr->prevNodeptr->nextNodeptr = nullptr;
					tailNodeptr = itNodeptr->prevNodeptr;
					count--;
					return true;
				}
				else {
					itNodeptr->prevNodeptr->nextNodeptr = itNodeptr->nextNodeptr;
					itNodeptr->nextNodeptr->prevNodeptr = itNodeptr->prevNodeptr;
					count--;
					return true;
				}
			}
			else {
				itNodeptr = itNodeptr->nextNodeptr;
			}
		}
		return false;
	}

	void friend operator<<(ostream& ostrm, DoubleLinkedList& dll) {
		dll.itNodeptr = dll.headNodeptr;
		while (dll.itNodeptr != nullptr) {
			ostrm << dll.itNodeptr->nodeString;
			ostrm << " ";
			dll.itNodeptr = dll.itNodeptr ->nextNodeptr;
		}
	}

	int getCount() {
		return count;
	}

	void resetIteration() {
		itNodeptr = headNodeptr;
	}

	T next() {
		T lstring(itNodeptr->nodeString);
		itNodeptr = itNodeptr->nextNodeptr;
		return lstring;
	}

	bool hasMore() {
		if (itNodeptr != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

};


#endif



