#include <iostream>
using namespace std;

struct listNode
{
  double value;
  listNode *next;
  listNode(int x){value=x; next = NULL;}
};

void printFirst(listNode *ptr){
  if(ptr==NULL){
    cout<<"The list is empty";
    exit(1);
  }
  else{
    cout<<ptr->value;
  }
}

int main()
{
  listNode* head = new listNode(3);
  head->next = new listNode(2);
  head->next->next = new listNode(10);

  printFirst(head);

  listNode* emptyList = NULL;
  printFirst(emptyList);

  return 0;
}