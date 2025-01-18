#include<iostream>
using namespace std;

class numberList{
  protected:
    struct listNode
    {
      double value;
      listNode *next;
      listNode(double value1, listNode *next1=NULL){
        value = value1;
        next = next1;
      }
    };
    listNode *head;
  public:
    numberList(){ head = NULL;}
    ~numberList();
    void add(double number);
    void remove(double number);
    void displayList();
};