/*
File name : LinkedList.cpp
Final project: Bank Account Information 
*/
#include "LinkedList.h"//include header file
#include <iostream>
/*
function name: LinkedList
function purpose: set class data members to default values
function type: constructor
parameters: none
return: none
*/
LinkedList::LinkedList()
{
	headPtr = NULL;
}
/*
function name: insert
function purpose: set class Node data members to given values.
function type: void
parameters: (string, string, double, bool)
return: none
*/
void LinkedList::insert(const string& tID,const string& aDescription,const double& anAmount, bool aType)
{
	//create new node
	Node *newNode = new Node();
	//set items in Node to given values
	newNode->setTransactionID(tID);
	newNode->setDescription(aDescription);
	newNode->setAmount(anAmount);
	newNode->setType(aType);
	
	newNode->setNext(headPtr);//set next of new Node to (headPtr) which will be NULL at first and then will be next Node on list
	headPtr = newNode;//make headPtr point to newest Node created
}
/*
function name: remove
function purpose: removes last item on the list
function type: void
parameters: none
return: none
*/
void LinkedList::remove()
{
	bool found = false;
	Node *ptr;
	ptr = headPtr;
	while (!found)
	{
		if (ptr == NULL)//if list is empty
		{
			cout << "List is empty.\n";
			found = true;
		}
		else if (ptr->getNext()==NULL)// check if the item next to headPtr is equal to NULL
		{
			delete ptr; 
			found = true;//item is found no need to go through loop again
			ptr = NULL;//set deleted Node to point to NULL
			headPtr = NULL;//set again headPtr to NULL since there was only one Node next to it and it was deleted
			cout << "Deleting..\nDone, item has been deleted! \n";
		}
		else if (ptr->getNext()->getNext()==NULL)//check if the NULL is two Nodes away from current ptr.
		{
			delete ptr->getNext();//delete item thats pointing to NULL
			found = true;//item is found no need to go through loop again
			ptr->setNext(NULL); // set current pointer (last item before the deleted one) to point to NULL
			cout << "Deleting..\nDone, item has been deleted! \n";
		}
		else //in case item to be deleted was not found 
		{
			ptr = ptr->getNext(); // move over to next node and go through loop again
			found = false;// not found go though loop again
		}
	}
}
/*
function name: display
function purpose: display created Nodes content
function type: void
parameters: none
return: none
*/
void LinkedList::display()
{
	Node *ptr;
	ptr = headPtr;
	int count = 1;// keep track of transactions entered just for display purposes
	if (ptr == NULL)// check if list is empty
	{
		cout << "No transactions found..\n";
	}
	else//list is not empty then display content
	{
		while ( ptr!= NULL)//go though items until finding Node that's poiinting to NULL (base case)
		{
	
			cout << " ::::::::::::Transaction("<< count ++ <<"):::::::::::: \n"
				<< "Transaction ID: (" << ptr->getTransactionID() << ") | "
				<< "Transaction Description: (" << ptr->getDescription()<<") | "
				<< "Transaction Amount: (" << ptr->getAmount() <<") | ";  
				if (ptr->getType() == true)//check bool type to display the transaction type
				{
					cout << "Transaction Type: Withdraw\n\n";
				}
				else
				{
					cout << "Transaction Type: Deposit\n\n";
				}
					 
			ptr = ptr->getNext(); //set ptr to point to next node to go though all Nodes created
		}
	}

}
/*
function name: displayTotals
function purpose: display total transactions made in case of withdraw it will subtract from total, in case of deposit it will add
function type: void
parameters: none
return: none
*/
void LinkedList::displayTotals()
{
	Node *ptr;
	ptr = headPtr;
	double totals = 0;
	
	while (ptr!= NULL)//go though all Nodes
	{
		if (ptr->getType()== true)// check whether the transaction is a withdrawal
		{
			(totals -= ptr->getAmount()); // if yes then subtract from total
		}
		else //in this casethe transaction is a deposit and it will add to total
		{
			(totals += ptr->getAmount()); 
		}
		ptr = ptr->getNext();//go to next node
		}
	cout << "Total = " << totals << endl;
}
/*
function name: displayLargestWithdrawal
function purpose: search for greatest withdrawal made.
function type: void
parameters: none
return: none
*/
void LinkedList::displayLargestWithdrawal()
{
	double max = 0;
	Node *ptr;
	ptr = headPtr;
	while (ptr != NULL)//go through all Nodes
	{
		if(ptr->getType() == true)//look for withdrawals only 
		{
			if (ptr->getAmount() > max)//check which is greater
			{
				max = ptr->getAmount();// if amount is greater set equal to max
			}
		}
		
		ptr = ptr->getNext();//go to next item.
	}
	//display info related to greatest withdrawal made
	ptr = headPtr;
	while (ptr != NULL)//go through all Nodes until Node is found 
	{
		if(ptr->getType() == true)//make sure it is a withdrawal
		{
			if (ptr->getAmount() == max)//search for Node with matching amount to max 
			{
				ptr = ptr;
				break;//break loop when found
			}
		}
		
		ptr = ptr->getNext();
		
	}
	if (headPtr == NULL)//check if list is empty
	{
		cout << "List is empty.. Nothing to display.\n";
	}
	else if (headPtr != NULL && max == 0)//check if there is any withdrawal transactions made 
	{
		cout << "No withdrawals has been made..\n"; 
	}
	else//if withdrawal transaction is found then display data
	{
		cout << "Largest withdrawal made is the following transaction: \n"
			<<"Transaction ID: " << ptr->getTransactionID() << endl
			<<"Description: " << ptr->getDescription() << endl
			<<"Amount: " << ptr->getAmount() << endl
			<<"Transaction type: Withdraw\n";
	}
}
/*
function name: clear
function purpose: delete all Nodes leaving list empty
function type: void
parameters: none
return: none
*/
void LinkedList::clear()
{
	Node *ptr;
	ptr = headPtr;
	if (headPtr!= NULL)// go though list. check if it is empty
	{
		headPtr = headPtr->getNext();//set headPtr to next ptr and delete headPtr content then set to NULL
		delete ptr;
		ptr = NULL;
		clear();//recursive call
	}
	else //when list is empty. 
	{
	 	cout << "List is empty.\n";
	}
	  
}

