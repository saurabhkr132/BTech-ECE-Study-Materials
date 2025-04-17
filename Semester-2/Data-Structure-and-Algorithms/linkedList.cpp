#include <iostream>
using namespace std;

struct listNode
{
  double value;
  listNode *next;
};

int main()
{
  listNode *head = NULL;
  head = new listNode;  //allocated new node
  head->value = 12.5; //store the value
  head->next=NULL;  //signify end of list

  listNode *secondPtr = new listNode;
  secondPtr->value = 30;
  secondPtr->next = NULL;
  head->next = secondPtr;

  cout<<"First item: "<<head->value<<endl;
  cout<<"Second item: "<<secondPtr->value<<endl;

  return 0;
}