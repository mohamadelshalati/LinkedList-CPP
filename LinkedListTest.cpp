/*
File name : LinkedListTest.cpp
Final project: Bank Account Information 
*/
#include <iostream>
#include<string>
using namespace std;
#include "LinkedList.h"


int main()
{
	int userChoice;
	string userTID;
	string userDes;
	double userAmount;
	int userTransactionType;
	bool type;
	
	LinkedList *userList = new LinkedList;// create an object
	
	while (true) //infinite loop to make a list
	{
		//create user list
		cout << "What would you like to do, please choose from the following list: \n" 
			<< "-(1) To enter a transaction.\n"
			<< "-(2) To remove last item on the list.\n"
			<< "-(3) To display total charges made.\n"
			<<"-(4)  To display largest withdrawal transaction made.\n"
			<<"-(5) To display all transactions made.\n"
			<<"-(6) To delete all transactions.\n"
			<< "Your Choice: ";
			cin >> userChoice;
			cin.ignore();
		switch(userChoice)
		{
			case 1:
				cout<< "You choose to enter a transaction..\n"
				<<"What is the transaction ID: ";
				getline(cin,userTID);
				cout << "What is the transaction description: ";
				getline(cin,userDes);
				cout << "What is the amount of the transaction: ";
				cin >> userAmount;
				
				while(userAmount <= 0)//check if input is valid
				{
					cout << "\nIncorrect input. Please enter an amount that is greater than 0: ";
					cin >> userAmount;
				}
				cout << "Please enter transaction type: \n"
					<< "(1). For deposit\n"
					<< "(2). For withdraw\n"
					<<"Your choice: ";
				cin >> userTransactionType;
				while (userTransactionType != 1 && userTransactionType!= 2)//check if input is valid
				{
					cout <<	"Incorrect input. Please enter:\n(1). For deposit\n(2). For withdraw:\nYour Choice:  ";
					cin >> userTransactionType;
				}
				if (userTransactionType == 1)//check transaction type if 1/ it is a deposit. 2/withdraw
				{
					type = false;
				}
				else
				{
					type = true;
				}

				userList->insert(userTID, userDes, userAmount,type);//setting items using insert function
				cout << " :::::::::Transaction has been added. Thanks:::::::::\n\n";
				break;
			case 2:
				userList->remove();//call to remove fuction to remove last item on list
				break;
			case 3:
				cout << "Total transactions made: \n";
				userList->displayTotals();// call to displayTotals function to display total at anytime
				cout << endl;
				break;
			case 4:
				userList->displayLargestWithdrawal();//call to displayLargestWithdrawal function to display largest withdrawal made
				break;
			case 5:
				userList->display();//call to display function to display all list items(Nodes Content)
				break;

			case 6:
				userList->clear();// call to clear to delete all avaliable Nodes in the list.
				break;
		}
	}

	return 0;
	
}//end of main.



//THANK YOU PROFESSOR RODRIGUES FOR ALL THE WORK YOU HAVE DONE TO TEACH ME ALL I KNOW NOW, I REALLY APPRECIATE YOU
//YOU ARE SUCH A GREAT PASSIONATE TEACHER.
