/***************************************************************************
 * class BST
 * A Binary Search Tree implementation built up from the primitive data 
 * structure bNode containing a integer data and parent, left and right
 * pointers. This class has member functions for adding an element, deleting
 * an element, searching, find successor, find predecessor, in-order
 * traversal, find maximum element and find minimum element
 * *************************************************************************/ 

#include <iostream>
#include <string>

using namespace std;

struct bNode
{
	bNode *parent, *left, *right;
	int bNodeVal;
};

class BST
{
public:
	BST()
	{
		treeRoot = NULL;
	}
	bNode *treeRoot;
	int insertElement (int );
	int deleteElement (int );
	int searchElement (int );
	int findPredecessor (int );
	int findSuccessor   (int );
	string displayInOrder  ();
	int findMinElement     ();
	int findMaxElement     ();
private:
	string inOrderTreeWalk (bNode*);
	bNode* findMinElementFromNode (bNode*);
	bNode* findMaxElementFromNode (bNode*);
	bNode* searchElementRetNode (int );
};

