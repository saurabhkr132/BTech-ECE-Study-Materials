/*********************************************************************
 * Class lList: A linked list using the primitive structure lNode
 * **********************************************************************/

#include <iostream>
#ifndef CLASS_LLIST_DEFINED
 #define CLASS_LLIST_DEFINED
class lList;
using namespace std;

struct lNode {
public:
	lNode* lNext;
	int lNodeVal;
	int lDistance;
	string lNodeColor;
	lList* lAdjListPointer;
};

class lList {
	lNode* startNode;	
public:
	lList ()
	{
		startNode = NULL;
	}
	void addElement(int,int);
	int  deleteElement(int);
	int  getNumberOfElements();
	void printList();
	void setParams(int, string, int, lList*);
	lNode* getNodeInfo(int,int);
};
#endif
