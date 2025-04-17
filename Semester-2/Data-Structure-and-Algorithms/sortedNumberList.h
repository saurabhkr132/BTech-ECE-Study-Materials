#include "numberList.h"

class sortedNumberList:public numberList
{
  public:
    void add(double number);
};

void sortedNumberList::add(double number)
{
  listNode *nodePtr, *previousNodePtr;
  if(head==NULL || head->value>=number)
  {
    // The new node goes to the beginning of list
    head = new listNode(number,head);
  }
  else
  {
    previousNodePtr = head;
    nodePtr = head->next;
    //Find the insertion point
    while(nodePtr!=NULL && nodePtr->value<number){
      previousNodePtr = nodePtr;
      nodePtr = nodePtr->next;
    }
    //Insert the new node just before nodePtr
    previousNodePtr->next = new listNode(number,nodePtr);
  }
}

/*
Remove a particular node from the list
1. Locating the node containing this number to be removed.
2. Look into that node from list
3. Delete the momory allocated to that node.
*/

void numberList::remove(double number)
{
  listNode *previousNodePtr, *nodePtr;
  //If the list is empty, do nothing
  if(!head)
    return;
  //Determine whether the first node is to be deleted
  if(head->value==number){
    nodePtr=head;
    head = head->next;
    delete nodePtr;
  }
  else
  {
    // Initialize nodePtr to head of the list
    nodePtr = head;
    // Skip nodes value memeber is not given number
    while(nodePtr!=NULL && nodePtr->value!=number)
    {
      previousNodePtr = nodePtr;
      nodePtr = nodePtr->next;
    }
    // Link the previous node to the node after nodePtr
    //then delete nodePtr
    if(nodePtr)
    {
      previousNodePtr->next = nodePtr->next;
      delete nodePtr;
    } //if closed
  } //else closed
} //function closed

//remove() is common for both classes numberList and sortedNumberList