#include "numberList.h"
using namespace std;

void numberList::add(double number)
{
  if(head==NULL)
    head = new listNode(number);
  else
  {
    // List is not empty
    listNode *nodePtr = head;
    while(nodePtr->next!=NULL)
      nodePtr = nodePtr->next;
    // Create a new node
    nodePtr->next = new listNode(number);
  }
}

void numberList::displayList()
{
  listNode *nodePtr = head;
  while(nodePtr)
  {
    // Print value in the current node
    cout<<nodePtr->value<<" ";
    //Move onto next node
    nodePtr = nodePtr->next;
  }
}

//Destructor
numberList::~numberList()
{
  listNode *nodePtr = head; //Start at head of the list
  while(nodePtr!=NULL)
  {
    //garbage keeps track of nodes to be deleted
    listNode *garbage = nodePtr;
    nodePtr = nodePtr->next;
    // Delete the garbage node
    delete garbage;
  }
}