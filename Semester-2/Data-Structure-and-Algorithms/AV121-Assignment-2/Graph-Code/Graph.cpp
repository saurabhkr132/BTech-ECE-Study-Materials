/*********************************************************************
 * Class Graph: Implements a graph using linked lists. All main nodes
 * are represented as a linked list and each main node points to
 * another linked list with contains the adjacent nodes of that node
 * So if a graph has n nodes and all nodes have neighbors, it will be
 * represented by n+1 linked lists
 * **********************************************************************/

#include "Graph.h"
#include <iostream>

/*********************************************************************
 * Graph::addMainNode
 * Adds a new main node with value nodeVal. Also, creates a new instance
 * of the linked list lList to store the adjacency list of this main node.
 * Pointer to the linked list is stored as a member variable of the main
 * node
 * **********************************************************************/
void Graph::addMainNode(int nodeVal)
{
	lList *newAdjList;
	lNode *tempNode;
	newAdjList = new lList;
	mainNodes.addElement(-1,nodeVal);
	mainNodes.setParams(nodeVal,"White",0,newAdjList);
	tempNode = mainNodes.getNodeInfo(0,nodeVal);
}

/*********************************************************************
 * Graph::addAdjListNode
 * Adds a new adjacent node for the main node mainNodeVal.
 * **********************************************************************/
void Graph::addAdjListNode(int mainNodeVal, int adjListNodeVal)
{
	lList *adjList;
	adjList = (mainNodes.getNodeInfo(0,mainNodeVal))->lAdjListPointer;
	adjList->addElement(-1,adjListNodeVal);
}

/*********************************************************************
 * Graph::printListOfNodes
 * Prints all main nodes and their adjacent nodes
 * **********************************************************************/
void Graph::printListOfNodes()
{
	lList *adjList;	
	lNode *adjNode;
	int mainNodeCnt=0,adjListNodeCount=0;
	mainNodeCnt = mainNodes.getNumberOfElements();
	for (int i=0; i< mainNodeCnt; i++)
	{
		cout << "Main Node: " << mainNodes.getNodeInfo(1,i)->lNodeVal << endl; 
		adjList = (mainNodes.getNodeInfo(1,i))->lAdjListPointer;
		adjListNodeCount = adjList->getNumberOfElements();
		//Uncomment if the nodes are to be printed without calling the 
		//linked list member functions
		/*for (int j=0; j<adjListNodeCount;j++)
		  {
		  adjNode=adjList->getNodeInfo(1,j);
		  cout << " Node " << adjNode->lNodeVal;
		  }*/
		adjList->printList();
	}
	cout << "Exiting print nodes from graph" << endl;
}

/*********************************************************************
 * Graph::setParamsAllAdjList
 * Sets the parameters of node with value nodeVal in *ALL* adjacency lists
 * of the graph
 * **********************************************************************/
void Graph::setParamsAllAdjList(int nodeVal,string nodeColor, int nodeDistance, lList* adjListAddress )
{
	lList *adjList;	
	lNode *adjNode;
	int mainNodeCnt=0,adjListNodeCount=0;
	mainNodeCnt = mainNodes.getNumberOfElements();
	for (int i=0; i< mainNodeCnt; i++)
	{
		adjList = (mainNodes.getNodeInfo(1,i))->lAdjListPointer;
		adjList->setParams(nodeVal,nodeColor,nodeDistance,adjListAddress);
	}
}

/*********************************************************************
 * Graph::BFS
 * Do a Breadth First Search on the graph using a queue ADT. This starts at
 * each main node of the graph and prints the nodes at distance i from
 * the main node in line i
 * **********************************************************************/
void Graph::BFS(ofstream& oFile)
{	
	lNode* selNode, *uNode, *adjListNode, *tempNode;
	lList* adjList;
	Q bfsQ;
	int mainNodeCnt=0,adjListNodeCount=0,selNodeVal=0,u=0,uDist=0,prevDist=0;

	mainNodeCnt = mainNodes.getNumberOfElements();
	
	// Initialising all main and adjacent nodes to not visited
	for (int i=0;i<mainNodeCnt;i++)
	{
		selNode=mainNodes.getNodeInfo(1,i);
		selNodeVal=selNode->lNodeVal;
		for(int j=0;j<mainNodeCnt;j++)
		{
			mainNodes.setParams((mainNodes.getNodeInfo(1,j))->lNodeVal,"White",0,NULL);
			adjList = (mainNodes.getNodeInfo(1,j))->lAdjListPointer;
			adjListNodeCount = adjList->getNumberOfElements();
			for (int k=0; k<adjListNodeCount;k++)
			{
				adjListNode=adjList->getNodeInfo(1,k); 
				adjList->setParams(adjListNode->lNodeVal,"White",0,NULL);
			}
		}
	}

	// Starting BFS for each unvisited main node...
	for (int i=0;i<mainNodeCnt;i++)
	{
		selNode=mainNodes.getNodeInfo(1,i);
		selNodeVal=selNode->lNodeVal;
		// Uncommment this block if all nodes are to be reset to unvisited 
		// after each iteration. Then, graph will be traversed from each
		// main node regardless of whether it was visited in a previous
		// search or not
	/*	for(int j=0;j<mainNodeCnt;j++)
		{
			//if (i==j) continue;
			mainNodes.setParams((mainNodes.getNodeInfo(1,j))->lNodeVal,"White",0,NULL);
			adjList = (mainNodes.getNodeInfo(1,j))->lAdjListPointer;
			adjListNodeCount = adjList->getNumberOfElements();
			for (int k=0; k<adjListNodeCount;k++)
			{
				adjListNode=adjList->getNodeInfo(1,k); 
				adjList->setParams(adjListNode->lNodeVal,"White",0,NULL);
			}
		}*/
		if (selNode->lNodeColor == "Gray") continue; //Do not visit visited nodes again
		mainNodes.setParams(selNodeVal,"Gray",0,NULL); // Set main node as visited
		bfsQ.enQ (selNodeVal);
		oFile << "Selected main node: " << selNodeVal  << endl ;
		while (bfsQ.qList.getNumberOfElements()>0) // Starting iteration
		{
			u=bfsQ.deQ();
			uNode = mainNodes.getNodeInfo(0,u);
			uDist=uNode->lDistance;

			if (uNode->lNodeColor == "White") // Print deQd nodes if unvisited
			{
				 //Insert carriage return if distance changes
				if ((prevDist != uDist)&&(prevDist!=0)) oFile << endl;
				oFile << "\t " << u;
				mainNodes.setParams(u,"Gray",uDist+1,NULL);
				prevDist = uDist;
			}

			adjList=uNode->lAdjListPointer;
			adjListNodeCount=adjList->getNumberOfElements();
			//Enq all adjacent nodes of selected main node
			for (int k=0; k<adjListNodeCount; k++)
			{
				adjListNode = adjList->getNodeInfo(1,k);
				if ((adjListNode->lNodeColor == "White"))
				{
					setParamsAllAdjList(adjListNode->lNodeVal,"Gray",uDist+1,NULL);
					mainNodes.setParams(adjListNode->lNodeVal,"",uDist+1,NULL);
					bfsQ.enQ(adjListNode->lNodeVal);
				}
			}
		}
		oFile << endl;
		oFile << "..............................................." << endl;	
	}
}

/*********************************************************************
 * Graph::DFSRecursive
 * Does a recursive Depth First Search on the graph and prints the
 * nodes traversed
 * **********************************************************************/
void Graph::DFSRecursive(ofstream& oFile)
{
	int mainNodeCnt=0,selNodeVal=0,runTime=0,u=0,adjListNodeCnt=0;
	lNode *selNode, *uNode, *adjListNode;
	lList *adjList;

	mainNodeCnt = mainNodes.getNumberOfElements();

	// Initialising all nodes as unvisited 
	for(int i=0;i<mainNodeCnt;i++)
	{
		selNode = mainNodes.getNodeInfo(1,i);
		selNodeVal=selNode->lNodeVal;
		mainNodes.setParams(selNodeVal,"White",0,NULL);
		adjList = (mainNodes.getNodeInfo(1,i))->lAdjListPointer;
		adjListNodeCnt = adjList->getNumberOfElements();
		for (int k=0; k<adjListNodeCnt;k++)
		{
			adjListNode=adjList->getNodeInfo(1,k); 
			adjList->setParams(adjListNode->lNodeVal,"White",0,NULL);
		}
	}
	runTime=0;

	// For each node, visit if not already visited
	for (int i=0; i<mainNodeCnt; i++)
	{
		uNode = mainNodes.getNodeInfo(1,i);
		u=uNode->lNodeVal;
		if (uNode->lNodeColor == "White")
		{
			oFile << "Selected main node " << u  << endl;
			DFSVisit(u,oFile);
			oFile << "..............................................." << endl;	
		}
	}
	
}

/*********************************************************************
 * Graph::DFSVisit
 * Recursive function for Depth First Sort. Accepts a main node value as
 * argument and visits all its children recursively
 * **********************************************************************/
void Graph::DFSVisit(int uNodeVal, ofstream& oFile)
{
	int adjListCnt=0,v=0;
	lList *adjList;
	lNode *adjListNode;
	mainNodes.setParams(uNodeVal,"Gray",0,NULL);
	setParamsAllAdjList(uNodeVal,"Gray",0,NULL);
	adjList = (mainNodes.getNodeInfo(0,uNodeVal))->lAdjListPointer;
	adjListCnt = adjList->getNumberOfElements();
	oFile << "\tVisited node: " << uNodeVal  <<  endl;
	for (int j=0; j<adjListCnt; j++)
	{
		adjListNode = adjList->getNodeInfo(1,j);	
		v = adjListNode->lNodeVal;
		if (adjListNode->lNodeColor == "White")
		{
			DFSVisit(adjListNode->lNodeVal, oFile);
		}
	}
}

/*********************************************************************
 * Graph::DFSIterative
 * Does an iterative Depth First Search on the graph using a stack ADT
 * **********************************************************************/
void Graph::DFSIterative(ofstream& oFile)
{

	lNode* selNode, *uNode, *adjListNode, *tempNode;
	lList* adjList;
	Stack bfsStack;
	int mainNodeCnt=0,adjListNodeCount=0,selNodeVal=0,u=0,uDist=0;

	mainNodeCnt = mainNodes.getNumberOfElements();

	for (int i=0;i<mainNodeCnt;i++)
	{
		selNode=mainNodes.getNodeInfo(1,i);
		selNodeVal=selNode->lNodeVal;
		for(int j=0;j<mainNodeCnt;j++)
		{
			mainNodes.setParams((mainNodes.getNodeInfo(1,j))->lNodeVal,"White",0,NULL);
			adjList = (mainNodes.getNodeInfo(1,j))->lAdjListPointer;
			adjListNodeCount = adjList->getNumberOfElements();
			for (int k=0; k<adjListNodeCount;k++)
			{
				adjListNode=adjList->getNodeInfo(1,k); 
				adjList->setParams(adjListNode->lNodeVal,"White",0,NULL);
			}
		}
	}
	for (int i=0;i<mainNodeCnt;i++)
	{
		selNode=mainNodes.getNodeInfo(1,i);
		selNodeVal=selNode->lNodeVal;
		// Uncomment if you want a full search from each main node
		/*for(int j=0;j<mainNodeCnt;j++)
		{
			mainNodes.setParams((mainNodes.getNodeInfo(1,j))->lNodeVal,"White",0,NULL);
			adjList = (mainNodes.getNodeInfo(1,j))->lAdjListPointer;
			adjListNodeCount = adjList->getNumberOfElements();
			for (int k=0; k<adjListNodeCount;k++)
			{
				adjListNode=adjList->getNodeInfo(1,k); 
				adjList->setParams(adjListNode->lNodeVal,"White",0,NULL);
			}
		}*/
		bfsStack.Push (selNodeVal);
		if (selNode->lNodeColor == "Gray") continue;
		oFile << "Selected main node: " << selNodeVal  << endl ;
		while (bfsStack.stackList.getNumberOfElements()>0)
		{
			u=bfsStack.Pop();
			uNode = mainNodes.getNodeInfo(0,u);
			uDist=uNode->lDistance;

			if (uNode->lNodeColor == "White")
			{
				mainNodes.setParams(u,"Gray",0,NULL);
				oFile << "\tVisited node: " << u << endl;
			}

			adjList=uNode->lAdjListPointer;
			adjListNodeCount=adjList->getNumberOfElements();
			
			// Push all adjacent nodes of selected node to stack
			for (int k=0; k<adjListNodeCount; k++)
			{
				adjListNode = adjList->getNodeInfo(1,k);
				tempNode = mainNodes.getNodeInfo(0,adjListNode->lNodeVal);

				if ((tempNode->lNodeColor == "White"))
				{
					setParamsAllAdjList(adjListNode->lNodeVal,"Gray",uDist+1,NULL);
					//mainNodes.setParams(adjListNode->lNodeVal,"",uDist+1,NULL);
					bfsStack.Push(adjListNode->lNodeVal);
				}
			}

		}
		oFile <<  "..............................................." << endl;	
	}
}

