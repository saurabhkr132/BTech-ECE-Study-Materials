/***************************************************************************
 * ui.cpp 
 * This file contains code for generating the menus for user interaction
 * and also validation of user input
 * *************************************************************************/ 

#include "ui.h"


/***************************************************************************
 * getUserOption 
 * This function displays a set of options to the user and accepts an input
 * corresponding to one of the options. Validation is done to ensure that
 * only integer inputs are accepted
 * Return Value
 * integer, containing selected menu option
 * *************************************************************************/ 
int getUserOption ()
{
	int userOption=0;
	string userOptionString="";
	istringstream outString;
	
	cout << endl << endl;
	cout << "*************** Binary Search Tree Utility ****************" << endl << endl;

	cout << "\t 1. Insert a new element" << endl;
	cout << "\t 2. Delete an element" << endl;
	cout << "\t 3. Search for an element" << endl;
	cout << "\t 4. Find predecessor of an element" << endl;
	cout << "\t 5. Find successor of an element" << endl;
	cout << "\t 6. Display inorder traversal" << endl;
	cout << "\t 7. Find the minimum element" << endl;
	cout << "\t 8. Find the maximum element" << endl;
	cout << "\t 0. Exit BST Utility" << endl;
	cout << endl << "Please select an option: " ;

	cin >> userOptionString;
	if (isNumeric(userOptionString)) 
	{
		istringstream outString(userOptionString);
		outString >> userOption;
		if (userOption >= INT_MAX)
		{
			userOption = -1;
		}
		else if (userOption <= INT_MIN)
		{
			userOption = -1;
		}
		return userOption;
	}
	else
		return -1;
}


/***************************************************************************
 * isNumeric 
 * Checks whether the user input is numeric, character by character
 * Return value
 * true - If the input is numeric
 * false - If the input contains non-numeric characters
 * *************************************************************************/ 
bool isNumeric (string inString)
{
	for (int i=0; i< inString.length(); i++)
	{
		if  (!isdigit(inString[i]))
		{
			return false;
		}
	}
	return true;
}


/***************************************************************************
 * trimSpaces 
 * Accepts a string and trims leading and trailing spaces. Trimming is done
 * on the input string itself
 * *************************************************************************/ 
void trimSpaces(string &inString) 
{ 
	size_t startPos = inString.find_first_not_of(" \t"); 
	size_t endPos  = inString.find_last_not_of(" \t"); 
	if ((startPos == string::npos) || (endPos == string::npos)) 
	{ 
		inString = ""; 
	} 
	else 
	{ 
		inString = inString.substr(startPos,endPos-startPos+1); 
	} 
} 



/***************************************************************************
 * processString 
 * Processes inString, ensures that it is numeric and returns the value as
 * integer. 
 * *************************************************************************/ 
int processString (string inString)
{
	int retVal=0;
	string tempString="";
	trimSpaces(inString);
	if(isNumeric(inString))
	{
		istringstream outString;
		outString.str(inString);
		outString >> retVal;
		if (retVal >= INT_MAX)
		{
			retVal = INT_MAX;
			cout << "Input exceeded maximum value of int data type. Limiting to " << INT_MAX << endl;
		}
		else if (retVal <= INT_MIN)
		{
			retVal = INT_MIN;
			cout << "Input exceeded maximum negative value of int data type. Limiting to " << INT_MIN << endl;
		}
	}
	else
		retVal = -1;
	return retVal;
}


/***************************************************************************
 * processOption 
 * Accepts an option from the user and a BST pointer and performs the 
 * requested action. This function validates user inputs and interprets
 * return values from BST operations
 * *************************************************************************/ 
void processOption (int userOption, BST* myTree)
{
	int readValue=0,retVal=0;
	string readValueString="";
	switch (userOption)
	{
		// 0: Exit
		case 0: cout << "Thank you for using the BST utility!" << endl;
			break;
		// 1: Insert Element
		case 1: 
			cout << "Please enter the value of the element you want to insert: ";
			cin >> readValueString;
			readValue = processString(readValueString);	
			if (readValue > 0)
			{
				cout << ((myTree->insertElement(readValue)==0)?("Inserted element!"):("Failed to insert!"));
				cout << endl;	
			}
			else	
			{
				cout << "Invalid value! Only positive integers are accepted!" << endl;
			}
			break;
		// 2: Delete element
		case 2: 
			cout << "Please enter the value of the element you want to delete: ";
			cin >> readValueString;
			readValue = processString(readValueString);	
			if (readValue > 0)
			{
				retVal= myTree->deleteElement(readValue);
				cout << ((retVal==0)?("Element deleted!"):((retVal==-1)?"Element not found in tree!":"Tree is empty!"));
				cout << endl;
			}
			else
			{
				cout << "Invalid value! Only positive integers are accepted!" << endl;
			}
			break;
		// 3: Search for element
		case 3:
			cout << "Please enter the value of the element to search for: ";
			cin >> readValueString;
			readValue =  processString(readValueString);
			if (readValue > 0)
			{
				retVal = myTree->searchElement(readValue);
				cout << ((retVal==1)?("Element found in tree!"):((retVal==0)?"Element not found in tree!":"Tree is empty!"));
				cout << endl;
			}
			else
			{
				cout << "Invalid value! Only positive integers are accepted!" << endl;
			}
			break;
		// 4: Find predecessor
		case 4:	
			cout << "Please enter the value of the element: ";
			cin >> readValueString;
			readValue =  processString(readValueString);
			if (readValue > 0)
			{
				retVal = myTree->findPredecessor(readValue);
				if (retVal > 0)
					cout << "Predecessor of " << readValue << " is " << retVal  << endl;	
				else if (retVal == -1)
					cout << readValue << " does not have a predecessor (Smallest element)" << endl;
				//else
				//	cout << readValue << " was not found in the tree!" << endl;
			}
			else
			{
				cout << "Invalid value! Only positive integers are accepted!" << endl;
			}
			break;
		// 5: Find successor
		case 5:
			cout << "Please enter the value of the element: ";
			cin >> readValueString;
			readValue =  processString(readValueString);
			if (readValue > 0)
			{
				retVal = myTree->findSuccessor(readValue);
				if (retVal > 0)
					cout << "Successor of " << readValue << " is " << retVal  << endl;	
				else if (retVal == -1)
					cout << readValue << " does not have a successor (Largest element)" << endl;
				//else
				//	cout << readValue << " was not found in the tree!" << endl;
			}
			else
			{
				cout << "Invalid value! Only positive integers are accepted!" << endl;
			}
			break;
		// 6: Display in-order traversal
		case 6:
			cout << "Inorder traversal: " << myTree->displayInOrder() << endl;
			break;
		// 7: Find minimum element
		case 7:	
			retVal = myTree->findMinElement();
			if (retVal > 0)
				cout << "Minimum element in the tree: " << retVal << endl;
			else
				cout << "Tree is empty!" << endl;
			break;
		// 8: Find maximum element
		case 8:
			retVal = myTree->findMaxElement();
			if (retVal > 0)
				cout << "Maximum element in the tree: " << retVal << endl;
			else
				cout << "Tree is empty!" << endl;
			break;
		// Other inputs
		default:
			cout << "Invalid input! Please select a valid option (0-8)" << endl;
			break;

	}

}

