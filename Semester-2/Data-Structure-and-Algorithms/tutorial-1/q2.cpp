/*#include <iostream>
using namespace std;

class numberList{
  private:
    struct listNode{
      double value;
      listNode* next;
      listNode(double value1, listNode* next1=NULL) : value(value1), next(next1) {}
    };
    listNode* head;
  public:
    // Constructor
    numberList(){head = NULL;}

    // Destructor
    ~numberList(){
      listNode* nodePtr = head;
      while(nodePtr){
        listNode* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
      }
    }

    // Addition function
    void add(double num)
    {
      if(head == NULL){
        head = new listNode(num);
      }
      else{
        listNode* nodePtr = head;
        while(nodePtr->next!=NULL){
          nodePtr = nodePtr->next;
        }
        nodePtr->next = new listNode(num);
      }
    }

    //Removal function
    void remove(double num)
    {
      if(head==NULL)
        return;
      listNode *nodePtr = head, *previousNodePtr;
      while(nodePtr!=NULL && nodePtr->value!=num){
        previousNodePtr = nodePtr;
        nodePtr = nodePtr->next;
      }
      if(nodePtr){
        previousNodePtr->next = nodePtr->next;
        delete nodePtr;
      }
    }

    //Display function
    void displayList(){
      listNode* nodePtr = head;
      while(nodePtr!=NULL)
      {
        cout<<nodePtr->value<<" ";
        nodePtr = nodePtr->next;
      }
    }

    friend listNode listConcat(listNode *list1, listNode *list2);
};

listNode listConcat(listNode *list1, listNode *list2){
  listNode* nodePtr = list1;
  if(nodePtr->next==NULL){
    nodePtr->next=list2;
  }
  else{
    listConcat(nodePtr->next, list2);
  }
  return list1;
}

int main()
{
  numberList list1, list2;
  list1.add(2);
  list1.add(48);
  list1.add(738);
  list1.add(-3);

  list2.add(21);
  list2.add(7);
  list2.add(1);

  list1.displayList();
  list2.displayList();
}*/
#include <iostream>
using namespace std;

class numberList{
  public:
    struct listNode{
      double value;
      listNode* next;
      listNode(double value1, listNode* next1=NULL) : value(value1), next(next1) {}
    };
    listNode* head;
    // Constructor
    numberList(){head = NULL;}

    // Destructor
    ~numberList(){
      listNode* nodePtr = head;
      while(nodePtr){
        listNode* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
      }
    }

    // Addition function
    void add(double num)
    {
      if(head == NULL){
        head = new listNode(num);
      }
      else{
        listNode* nodePtr = head;
        while(nodePtr->next!=NULL){
          nodePtr = nodePtr->next;
        }
        nodePtr->next = new listNode(num);
      }
    }

    //Removal function
    void remove(double num)
    {
      if(head==NULL)
        return;
      listNode *nodePtr = head, *previousNodePtr;
      while(nodePtr!=NULL && nodePtr->value!=num){
        previousNodePtr = nodePtr;
        nodePtr = nodePtr->next;
      }
      if(nodePtr){
        previousNodePtr->next = nodePtr->next;
        delete nodePtr;
      }
    }

    //Display function
    void displayList(){
      listNode* nodePtr = head;
      while(nodePtr!=NULL)
      {
        cout<<nodePtr->value<<" ";
        nodePtr = nodePtr->next;
      }
    }
};

// Concatenate two lists recursively
listNode* listConcat(listNode *list1, listNode *list2){
  if(list1 == NULL) return list2;
  list1->next = listConcat(list1->next, list2);
  return list1;
}

int main()
{
  numberList list1, list2;
  list1.add(2);
  list1.add(48);
  list1.add(738);
  list1.add(-3);

  list2.add(21);
  list2.add(7);
  list2.add(1);

  listConcat(list1.head, list2.head);
  list1.displayList();
}
