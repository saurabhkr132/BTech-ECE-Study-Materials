#include <iostream>
#include <fstream>
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

listNode *numberList = NULL;

int main()
{
  // Open the file
  ifstream numberFile("numberdata.txt");
  if(!numberFile)
  {
    cout<<"Error in opening the file";
    exit(1);
  }
  double number;
  cout<<"Contents of the file are: ";
  while(numberFile>>number)
  {
    cout<<number<<" ";
    // Create node to hold this number
    numberList = new listNode(number,numberList);
  }
  
  cout<<endl;

  listNode *ptr = numberList;
  while(ptr!=NULL)
  {
    cout<<ptr->value<<" ";
    ptr=ptr->next;
  }
  return 0;
}