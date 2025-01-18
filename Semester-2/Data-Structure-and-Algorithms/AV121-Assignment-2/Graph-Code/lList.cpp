/*********************************************************************
 * Class lList: A linked list using the primitive structure lNode
 * **********************************************************************/

#include <iostream>
#include "lList.h"
using namespace std;

/*********************************************************************
 * lList::addElement
 * Adds a new element with value 'newElementVal into the linked list
 * at position 'positionToInsert'. Position 0 will insert to beginning of
 * the list and -1 will insert to end of the list. Any other value will
 * insert at that position in the list
 * **********************************************************************/
void lList::addElement(int positionToInsert, int newElementVal)
{
	lNode  *tempNode, *dataNode;
	tempNode = startNode;
	dataNode = new lNode;
	dataNode->lNodeVal=newElementVal;

	if (tempNode == NULL)
	{
		startNode = dataNode;
		startNode->lNodeVal = newElementVal;
		startNode->lNext = NULL;
	}
	else
	{
		switch(positionToInsert)
		{
		case (0): // 0: Insert at beginning when position to insert is 0
			dataNode->lNext=startNode;
			startNode=dataNode;
			break;
		case (-1): //-1: Insert at end when position to insert is -1
			while (tempNode->lNext != NULL)
			{
				tempNode=tempNode->lNext;
			}
			tempNode->lNext = dataNode;
			dataNode->lNext = NULL;
			break;
		default: // Otherwise, insert at the required position
			for(int i=0; i<positionToInsert-1; i++)
			{
				if (tempNode->lNext != NULL)
				{
					tempNode = tempNode->lNext;
				}
				else
				{
					cout << "List has fewer entries than %d!" << positionToInsert << endl;
					delete dataNode; 
				}
			}
			// Now we are at the position to insert
			dataNode->lNext = tempNode->lNext;
			tempNode->lNext = dataNode;	
			break;
		}
	}
}

/*********************************************************************
 * lList::deleteElement
 * Deletes the element in the linked list at position 'positionOfElementToDelete'.
 * Position 0 will delete the first element and 1 will delete the last
 * element. Any other value will delete the element at that position.
 * This function returns the value of the element deleted
 * **********************************************************************/
int lList::deleteElement(int positionOfElementToDelete)
{
	lNode *tempNode,*nodeToBeDeleted,*prevNode;
	int elementVal=0;
	tempNode = startNode;
	if (startNode !=  NULL)
	{
		if (tempNode->lNext == NULL)
		{
			elementVal = tempNode->lNodeVal;
			delete tempNode;
			startNode = NULL;
		//	cout << "Last element deleted! Queue is empty" << endl;
		}
		else if (positionOfElementToDelete == 0) // Delete first element
		{
			elementVal = tempNode->lNodeVal;
			startNode=tempNode->lNext;
			delete tempNode;
		}
		else if (positionOfElementToDelete == -1) // Delete last element
		{
			while (tempNode->lNext != NULL)
			{
				prevNode=tempNode;
				tempNode=tempNode->lNext;
			}
			prevNode->lNext = NULL;
			elementVal = tempNode->lNodeVal;
			delete tempNode;
		}
		else // Delete any other element
		{
			for(int i=0;i<positionOfElementToDelete-1;i++) 
			{
				tempNode=tempNode->lNext;
				if (tempNode->lNext == NULL)
				{
					cout << "List has less than " << positionOfElementToDelete << " lines!!" << endl;
					return -666;
				}
			}
			nodeToBeDeleted=tempNode->lNext;
			tempNode->lNext = nodeToBeDeleted->lNext;
			elementVal = nodeToBeDeleted->lNodeVal;
			delete nodeToBeDeleted;
		}
		return elementVal;
	}
	else
	{
		cout << "Cannot delete! List is empty!!!" << endl;
		return -666;
	}
}

/*********************************************************************
 * lList::printList
 * Prints the value of each node in the list
 * **********************************************************************/
void lList::printList()
{
	int i=0;
	lNode *tempNode;
	tempNode=startNode;
	while (tempNode != NULL)
	{
		cout << "Value at node " << i++ << " is " <<  tempNode->lNodeVal << endl;
		tempNode=tempNode->lNext;
	}
}

/*********************************************************************
 * lList::getNumberOfElements
 * Returns the total number of elements in the list
 * **********************************************************************/
int lList::getNumberOfElements()
{
	int i=0;
	lNode *tempNode;
	tempNode=startNode;
	if (startNode == NULL)
	{	return 0;	}
	else
	{
		while (tempNode != NULL)
		{	
			i++;
			tempNode=tempNode->lNext;
		}
			
	}
	return i++;
}

/*********************************************************************
 * lList::setParams
 * Sets other parameters like lNodeColor, lnodeDistance, lAdjListAddress
 * for the element with value nodeVal
 * **********************************************************************/
void lList::setParams(int nodeVal, string nodeColor, int nodeDistance, lList* adjListAddress)
{
	lNode* tempNode;
	tempNode=startNode;
	while (tempNode != NULL)
	{
		if (tempNode->lNodeVal == nodeVal)
			break;
		else
			tempNode=tempNode->lNext;
	}
	if (tempNode == NULL)
	{
	//	cout << "No node with value " << nodeVal  << " found in list!!" << endl;
	}
	else
	{
		if (adjListAddress != NULL)
			tempNode->lAdjListPointer = adjListAddress;
		if (nodeColor != "") 
			tempNode->lNodeColor = nodeColor;
		tempNode->lDistance = nodeDistance;
	}
}

/*********************************************************************
 * lList::getNodeInfo
 * Returns a pointer to node specified by either the nodeValue or the
 * position of the node in the list. If howToSearch is 0, pointer to node
 * with value nodeVal is returned and if howToSearch is 1, pointer to
 * node at position howToSearch is returned
 * **********************************************************************/
lNode* lList::getNodeInfo(int howToSearch, int nodeVal) // How to search = 0 => Value, 1=> Element number
{

	lNode* tempNode;
	tempNode=startNode;
	if (howToSearch == 0 )
	{
		while (tempNode != NULL)
		{
			if (tempNode->lNodeVal == nodeVal)
				break;
			else
				tempNode=tempNode->lNext;
		}
		if (tempNode == NULL)
		{
			cout << "No node with value " << nodeVal  << " found in list!!" << endl;
		}
	}
	else
	{
		for(int i=0;i<nodeVal;i++)
		{
			tempNode=tempNode->lNext;
			if (tempNode == NULL)
			{	
				cout << "List has less than " << nodeVal << " elements!" << endl;
			}
		}
	}
	return tempNode;

}
