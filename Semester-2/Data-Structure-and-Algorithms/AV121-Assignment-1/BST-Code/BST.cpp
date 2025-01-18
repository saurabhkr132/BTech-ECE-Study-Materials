/***************************************************************************
 * class BST
 * A Binary Search Tree implementation built up from the primitive data 
 * structure bNode containing a integer data and parent, left and right
 * pointers. This class has member functions for adding an element, deleting
 * an element, searching, find successor, find predecessor, in-order
 * traversal, find maximum element and find minimum element
 * *************************************************************************/ 

#include <string>
#include <sstream>
#include "BST.h"
using namespace std;

/************************************************************
 * BST::insertElement
 * Inserts the element specified by elementToInsert into the
 * BST. Returns 0 on successful insert operation, -1 if failed
 ************************************************************/
int BST::insertElement (int elementToInsert)
{
	bool elementExistsWarned=0;
	bNode *traverseNodeX,*traverseNodeY,*tempNode;
	tempNode = new bNode;
	
	traverseNodeY = NULL;
	traverseNodeX = treeRoot;
	// Traverse the tree from root, looking for a leaf where new element can be inserted
	while (traverseNodeX != NULL)
	{
		if ((traverseNodeX->bNodeVal == elementToInsert)&&(!elementExistsWarned)) // Warn if element already present
		{
			cout << "Warning: Value " << elementToInsert << " already present in the tree!" << endl; 
			elementExistsWarned = 1;
		}
		traverseNodeY = traverseNodeX;
		if (elementToInsert < traverseNodeX->bNodeVal) // Checks to ensure BST property
		{
			traverseNodeX = traverseNodeX->left;
		}
		else
		{
			traverseNodeX = traverseNodeX->right;
		}
	}
	tempNode->bNodeVal = elementToInsert;
	tempNode->parent = traverseNodeY;
	tempNode->left = NULL; // New element always as leaf. So right = left = NULL
	tempNode->right = NULL;
	
	if (traverseNodeY == NULL) // Tree was empty
	{
		treeRoot = tempNode;
		treeRoot->parent = NULL;
		treeRoot->left = NULL;
		treeRoot->right = NULL;
	}
	else if (elementToInsert < traverseNodeY->bNodeVal) // Append new element to appropriate leaf
	{
		traverseNodeY->left = tempNode;
	}
	else 	
	{
		traverseNodeY->right = tempNode;
	}

	return 0;	
}


/************************************************************
 * BST:deleteElement
 * Deletes the element with value elementToDelete
 * Return Values
 * 	0 - Element successfully deleted
 *     -1 - Search key not found in tree
 *     -2 - Tree is empty (root is NULL)
 ************************************************************/
int BST::deleteElement (int elementToDelete)
{	
	
	if (treeRoot == NULL) return -2;
	bNode* nodeToBeDeleted = searchElementRetNode(elementToDelete);
	if (nodeToBeDeleted == NULL) return -1;

	// Node to be deleted is a leaf node
	// Delete and parent's left and right to NULL
	if (nodeToBeDeleted->right == NULL && nodeToBeDeleted->left == NULL)
	{	
		if (nodeToBeDeleted == treeRoot)
		{
			treeRoot = NULL;
		}
		else
		{
			if (nodeToBeDeleted->parent->right == nodeToBeDeleted)
				nodeToBeDeleted->parent->right = NULL;
			else
				nodeToBeDeleted->parent->left = NULL;
		}
		delete nodeToBeDeleted;
	}
	// Node to be deleted has no right child
	// Check if the node to be deleted is left or right child of its parent
	// Then, set appropriate pointer of parent so that it points to 
	// left child of the node to be deleted
	else if (nodeToBeDeleted->right == NULL)
	{
		if (nodeToBeDeleted == treeRoot)
		{
			treeRoot = treeRoot->left;
			treeRoot->parent = NULL;
		}
		else
		{
			if (nodeToBeDeleted->parent->right == nodeToBeDeleted)
				nodeToBeDeleted->parent->right = nodeToBeDeleted->left;
			else
				nodeToBeDeleted->parent->left = nodeToBeDeleted->left;
			nodeToBeDeleted->left->parent = nodeToBeDeleted->parent;
		}
		delete nodeToBeDeleted;
	}
	// Node to be deleted has no left child
	// Check if the node to be deleted is left or right child of its parent
	// Then, set appropriate pointer of parent so that it points to 
	// right child of the node to be deleted
	else if (nodeToBeDeleted->left == NULL)
	{	
		if (nodeToBeDeleted == treeRoot)
		{
			treeRoot = treeRoot->right;
			treeRoot->parent = NULL;
		}
		else
		{
			if (nodeToBeDeleted->parent->right == nodeToBeDeleted)
				nodeToBeDeleted->parent->right = nodeToBeDeleted->right;
			else 
				nodeToBeDeleted->parent->left = nodeToBeDeleted->right;
			nodeToBeDeleted->right->parent = nodeToBeDeleted->parent;
		}		
		delete nodeToBeDeleted;
	}
	// Node to be deleted has both children
	else
	{
		bNode* tempNode;
		int tempNodeVal;
		tempNode = findMaxElementFromNode(nodeToBeDeleted->left);
		tempNodeVal = tempNode->bNodeVal;
		deleteElement(tempNode->bNodeVal);
		nodeToBeDeleted->bNodeVal = tempNodeVal;
	}
	return 0;	
}

/************************************************************
 * BST:searchElement
 * Searches for a given element in the BST
 * Return Values
 * 	0 - Search key not found in tree
 * 	1 - Search key found in tree
 *     -1 - Tree is empty (root is NULL)
 ************************************************************/
int BST::searchElement (int elementToSearch)
{
	bNode* resultNode = searchElementRetNode(elementToSearch); // Calls searchElementRetNode to get pointer to result
	return (treeRoot!=NULL)?((resultNode!=NULL)?1:0):-1; // Return Found(1)/NotFound(0)/TreeEmpty(-1)
}

/************************************************************
 * BST:searchElementRetNode
 * Searches for a given element in the BST and returns pointer
 * to result node
 * Return Values
 * 	Value found - Pointer to result node
 * 	Value not found - NULL pointer
 ************************************************************/
bNode* BST::searchElementRetNode (int elementToSearch)
{
	bNode *traverseNode, *resultNode=NULL;
	traverseNode = treeRoot;
	while (traverseNode != NULL)
	{
		if (elementToSearch < traverseNode->bNodeVal)
			traverseNode = traverseNode->left;
		else if (elementToSearch > traverseNode->bNodeVal)
			traverseNode = traverseNode->right;
		else
		{
			resultNode = traverseNode;
			break;
		}
	}
	return resultNode;
}


/************************************************************
 * BST:findPredecessor
 * Finds the predecessor of elementToFind from the tree
 * Return Values
 *      Normal case: Value of the predecessor
 *     -1 - Selected element has no predecessor (Smallest element)
 *     -2 - Selected element was not found in the tree
 ************************************************************/
int BST::findPredecessor (int elementToFind)
{
	bNode* searchKeyNode = searchElementRetNode(elementToFind);
	bNode* tempNode;
	if (searchKeyNode == NULL)  // Element was not there in the tree
	{
		cout << "Element " << elementToFind << " not found in tree!!" << endl;
		return -2;
	}
	if (searchKeyNode->left != NULL) // Has left sub-tree => Pred = maxElement(leftSubTree)
	{
		return (findMaxElementFromNode (searchKeyNode->left))->bNodeVal;
	}
	tempNode = searchKeyNode->parent;
	while ((tempNode != NULL) && (searchKeyNode == tempNode->left)) // No left subtree => Pred = parent where current node is left child
	{
		searchKeyNode = tempNode;
		tempNode = tempNode->parent;
	}
	return (tempNode!=NULL)?tempNode->bNodeVal:-1; // No predecessor if no such parent could be found
}


/************************************************************
 * BST:findSuccessor
 * Finds the successor of elementToFind from the tree
 * Return Values
 *      Normal case: Value of the successor
 *     -1 - Selected element has no predecessor (Largest element)
 *     -2 - Selected element was not found in the tree
 ************************************************************/
int BST::findSuccessor   (int elementToFind)
{
	bNode* searchKeyNode = searchElementRetNode(elementToFind);
	bNode* tempNode;
	if (searchKeyNode == NULL) // Element was not there in the tree
	{
		cout << "Element " << elementToFind << " not found in tree!!" << endl;
		return -2;
	}
	if (searchKeyNode->right != NULL) // Has a right sub-tree => Succ = minElement(rightSuubTree)
	{
		return (findMinElementFromNode (searchKeyNode->right))->bNodeVal;
	}
	tempNode = searchKeyNode->parent;
	while ((tempNode != NULL) && (searchKeyNode == tempNode->right))  //No right subtree => Succ = parent where curr node is right child
	{
		searchKeyNode = tempNode;
		tempNode = tempNode->parent;
	}
	return (tempNode!=NULL)?tempNode->bNodeVal:-1; // No successor if no such parent found
}


/************************************************************
 * BST:displayInOrder
 * Does an inorder traversal of the BST and returns the traversal
 * as a string
 ************************************************************/
string BST::displayInOrder  ()
{	
	string retVal;
	if (treeRoot != NULL)
		retVal=inOrderTreeWalk (treeRoot); // Call inOrderTreeWalk starting at root
	else
		retVal="Tree is empty!\n";
	return retVal;
}


/************************************************************
 * BST:findMinElement
 * Returns value of the minimum element in the BST 
 * Return Values
 * 	Normal case : Value of minimum element
 * 	-1 : If tree is empty
 ************************************************************/
int BST::findMinElement     ()
{
	bNode* traverseNode = treeRoot;
	bNode* minNode=NULL;

	if (treeRoot == NULL) return -1;

	while (traverseNode != NULL)
	{
		minNode = traverseNode;
		traverseNode = traverseNode->right;
	}
	
	return minNode->bNodeVal ;
}


/************************************************************
 * BST:findMinElementFromNode
 * Returns value of the minimum element in the sub-tree with
 * traverseNode as root
 * Return Values
 * 	Normal case : Pointer to node with minimum element
 * 	NULL Pointer: If subtree root itself is NULL
 ************************************************************/
bNode* BST::findMinElementFromNode(bNode* traverseNode)
{	
	bNode* minNode=NULL;
	while (traverseNode != NULL)
	{
		minNode = traverseNode;
		traverseNode = traverseNode->left;
	}
	if (treeRoot == NULL)
	{
		return NULL;
	}
	else
	{
		return minNode;
	}


}

/************************************************************
 * BST:findMaxElement
 * Returns value of the maximum element in the BST 
 * Return Values
 * 	Normal case : Value of maximum element
 * 	-1 : If tree is empty
 ************************************************************/
int BST::findMaxElement     ()
{
	bNode* traverseNode = treeRoot;
	bNode* minNode=NULL;

	if (treeRoot == NULL) return -1;

 
	
	return treeRoot->bNodeVal ;
}


/************************************************************
 * BST:findMaxElementFromNode
 * Returns value of the maximum element in the sub-tree with
 * traverseNode as root
 * Return Values
 * 	Normal case : Pointer to node with maximum element
 * 	NULL Pointer: If subtree root itself is NULL
 ************************************************************/
bNode* BST::findMaxElementFromNode (bNode* traverseNode)
{
	bNode* maxNode=NULL;
	while (traverseNode != NULL)
	{
		maxNode = traverseNode;
		traverseNode = traverseNode->right;
	}
	if (treeRoot == NULL)
	{
		return NULL;
	}
	else
	{
		return maxNode;
	}
}


/************************************************************
 * BST:inOrderTreeWalk
 * Performs an in-order walk of the BST and returns a string 
 * containing the traversal
 ************************************************************/
string BST::inOrderTreeWalk (bNode* startNode)
{
	string retVal="";
	ostringstream outputStream;
	if (startNode != NULL)
	{
		outputStream << inOrderTreeWalk (startNode->left)  ;
		outputStream << startNode->bNodeVal << " "; 
		/*outputStream << " P: "; // Uncomment this block for diagonostics: Parent, Left and Right for each node
		outputStream << ((startNode->parent!=NULL)?(startNode->parent->bNodeVal):(0)) ;
		outputStream << " L: ";
		outputStream << ((startNode->left!=NULL)?(startNode->left->bNodeVal):(0));
		outputStream << " R: ";
		outputStream << ((startNode->right!=NULL)?(startNode->right->bNodeVal):(0));
		outputStream << endl ;*/ 
		outputStream << inOrderTreeWalk (startNode->right) ;
	}
	retVal = outputStream.str();
	return retVal;
}
