/*********************************************************************
 * Class Q: Implements a queue using the linked list class lList
 * **********************************************************************/

#include "lList.h"

class Q {
	public:
		int qEmpty;
		lList qList;
		Q ()
		{
			qEmpty=1;
		}
		void enQ(int);
		int  deQ();
		void printQ();
};


