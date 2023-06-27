/*
File name : Node.h
Final project: Bank Account Information 
*/
#include "Node.h"
/*
function name: Node
function purpose: set all class data fields to default 
parameters: none
return: none
*/
Node::Node()
{
	transactionID = "";
	description = "";
	amount = 0;
	type = false;
	next = NULL;
}

/*
function name: Node
function type: Node class constructor
function purpose: set data fields to given values
parametes: string, string, double, bool
return: none
*/
Node::Node(const string& tID, string& aDescription, double& anAmount, bool aType)
{
	transactionID = tID;
	description = aDescription;
	amount = anAmount;
	type = aType;
	next = NULL;
}
/*
function name: Node
function type: Node class constructor 
function purpose: set data fields to given values as well as set next Node value
parameters: string, string, double, bool, Node pointer (class).
return: none
*/
Node::Node(const string& tID, string& aDescription, double& anAmount, bool aType, Node* nxtNode)
{
	transactionID = tID;
	description = aDescription;
	amount = anAmount;
	type = aType;
	next = nxtNode;
}
/*
function name: setTransactionID
function type: void
function purpose: set class data member transactionID 
parameters: string
return: none
*/
void Node::setTransactionID(const string &anEntry)
{
	transactionID = anEntry;
}
/*
function name: setDescription
function purpose: set class data member description
function type: void
parameters: string
return: none
*/
void  Node::setDescription(const string &anEntry)
{
	description = anEntry;
}
/*
function name: setAmount
function purpose: set class data member amount
function type: void
parameters: double
return: none
*/
void Node::setAmount(const double &anEntry)
{
	amount = anEntry;
}
/*
function name: setType
function purpose: set class data member type
function type: void
parameters: bool
return: none
*/
void Node::setType(const bool anEntry)
{
	type = anEntry;
}
/*
function name: setNext
function purpose: set class data member next
function type: void
parameters: Node (class)
return: none
*/
void Node::setNext(Node *nxtNode)
{
	next = nxtNode;
}
/*
function name: getTransactionID
function purpose: accessor method for transactionID class member
function type: string
parameters: none
return: transactionID 
*/
string Node::getTransactionID()const
{
	return transactionID;
}
/*
function name: getDescription
function purpose: accessor method for description class member
function type: string
parameters: none
return: a string description
*/
string Node::getDescription()const
{
	return description;
}
/*
function name: getAmount
function purpose: accessor method for amount class member
function type: void
parameters: none
return: a double amount
*/
double Node::getAmount()const
{
	return amount;
}
/*
function name: getType
function purpose: accessor method for type class member
function type: bool
parameters: none
return: a bool type
*/
bool Node::getType()const
{
	return type;
}
/*
function name: getNext
function purpose: accessor method for pointer to next node.
function type: Node (class)
parameters: none
return: a pointer to a node
*/
Node *Node::getNext()const
{
	return next;
}
