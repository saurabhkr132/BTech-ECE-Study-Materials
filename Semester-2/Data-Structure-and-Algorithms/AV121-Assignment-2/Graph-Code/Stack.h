/*********************************************************************
 * Class Stack: Implements a stack using the linked list class lList
 **********************************************************************/

#include "lList.h"

class Stack {
public:	
	Stack ()
	{
	
	}
	lList stackList;
	void Push(int);
	int  Pop();
	void printStack();
};

