#include "numberList.h"
using namespace std;

int main()
{
  numberList list;
  // Build the list
  list.add(12);
  list.add(15);
  list.add(17.7);

  //Display the list
  cout<<"The values of the list are\n";
  list.displayList();
  cout<<"Removing the node";
  list.remove(15);
  list.displayList();

  return 0;
}