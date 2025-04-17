#include <iostream>
using namespace std;

struct listNode
{
  double value;
  listNode *next;
  listNode(double value1, listNode *next1=NULL){
    value = value1;
    next = next1;
  }
};

int main()
{
  // listNode *secondPtr = new listNode(30);
  // listNode *head = new listNode(15,secondPtr);
  
  //Simpler version:
  listNode *head = new listNode(30);
  head = new listNode(15,head);
  return 0;
}