/*
File name: LinkedList.h
Final project: Bank Account Information
*/

#ifndef LINKED_LIST
#define LINKED_LIST
#include <string>
#include "Node.h"

class LinkedList : public Node //call to base function public fields
{
private:
	//LinkedList class private members
	Node *headPtr;
public:
	//LinkedList class public methods
	LinkedList();
	void insert(const string& tID,const string& aDescription,const double& anAmount, bool aType);
	void remove();
	void display();
	void displayTotals();
	void displayLargestWithdrawal();
	void clear();

}; // END OF LinkedList class

#include "Linkedlist.cpp"

#endif // End of LINKEDLIST.h
