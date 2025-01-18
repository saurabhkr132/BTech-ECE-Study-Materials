/*********************************************************************
 * Class Stack: Implements a stack using the linked list class lList
 **********************************************************************/

#include "Stack.h"

/*********************************************************************
 *Stack::Push
 *Pushes elementToPush into the stack 
 * *******************************************************************/

void Stack::Push (int elementToPush)
{
	stackList.addElement(-1,elementToPush);
}

/*********************************************************************
 *Stack::Pop
 *Pops the element at stack top and return the value
 * *******************************************************************/
int Stack::Pop ()
{
	return stackList.deleteElement(-1);
}

void Stack::printStack()
{
	stackList.printList();
}
