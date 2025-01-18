/*********************************************************************
 * Class Q: Implements a queue using the linked list class lList
 * **********************************************************************/

#include "Q.h"

/*********************************************************************
 * Q::enQ
 * Enqueues an element to the tail of the queue
 * **********************************************************************/
void Q::enQ (int elementToEnQ)
{
	qList.addElement(-1,elementToEnQ);
	//qEmpty=0;
}

/*********************************************************************
 * Q::deQ
 * Dequeues an element from the head of the queue
 * **********************************************************************/
int Q::deQ ()
{	
	int qCount = qList.getNumberOfElements();
	if (qCount = 0)
	{
		cout << "Q is empty! Cannot deQ!!" << endl;
		qEmpty=1;
		return -666;
	}
	else if (qCount=1)
	{
		qEmpty=1;
	}
	return qList.deleteElement(0);
}

/*********************************************************************
 * Q::printQ
 * Prints the list of elements in the queue
 * **********************************************************************/
void Q::printQ()
{
	qList.printList();
}
