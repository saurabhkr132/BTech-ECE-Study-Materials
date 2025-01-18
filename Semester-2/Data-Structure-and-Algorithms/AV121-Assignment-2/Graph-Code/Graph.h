/*********************************************************************
 * Class Graph: Implements a graph using linked lists. All main nodes
 * are represented as a linked list and each main node points to
 * another linked list with contains the adjacent nodes of that node
 * So if a graph has n nodes and all nodes have neighbors, it will be
 * represented by n+1 linked lists
 * **********************************************************************/
#include "Q.h"
#include "Stack.h"
#include <iostream>
#include <fstream>

class Stack;

class Graph
{
public:
	lList mainNodes;
//	Stack Temp;
	Graph()
	{
	}
	void addMainNode(int);
	void addAdjListNode(int mainNodeVal, int adjListNodeVal);
	void printListOfNodes();
	void BFS(ofstream&);
	void DFSRecursive(ofstream&);
	void DFSIterative(ofstream&);
	int getMainNodeVal(int currentNode);
	void setParamsAllAdjList(int, string, int, lList*);
	void DFSVisit(int,ofstream&);
};

