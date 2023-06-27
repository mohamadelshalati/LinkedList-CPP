/*
Name: Mohamad Elshalati
File name : Node.h
Final project: Bank Account Information 
*/

#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT
#include <string>
using namespace std;

class Node
{
	private:
	//Node data memberes:
		string transactionID;
		string description;
		double amount;
		bool type;
		Node* next;
	public:
	//methods to set data memberes
 		Node();
		Node(const string &tID, string &aDescription, double &anAmount, bool aType);
		Node(const string& tID, string& aDescription, double& anAmount, bool aType, Node *nxtNode);
		void setTransactionID(const string &anEntry);
		void setDescription(const string &anEntry);
		void setAmount(const double &anEntry);
		void setType(const bool anEntry);
		void setNext(Node *nxtNode);
		string getTransactionID()const;
		string getDescription()const;
		double getAmount()const;
		bool getType()const;
		Node *getNext()const;
}; // END OF NODE CLASS

#include "Node.cpp"
#endif // BANKACCOUNT
