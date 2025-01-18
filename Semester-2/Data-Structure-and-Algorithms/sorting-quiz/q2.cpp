// Q2. Given an array of Strings arr[]. Sort given Strings Using Bubble sort and display the sorted array.

#include <iostream>
using namespace std;
#include <string>

//Function to sort strings using Bubble sort
void sortStrings(string str[], int n)
{
  for(int i=n-1; i>0; --i)
  {
    for(int j=0; j<i; ++j)
    {
      if(str[j]>str[j+1]){
        string temp = str[j];
        str[j] = str[j+1];
        str[j+1] = temp;
      }
    }
  }
}

int main()
{
  string arr[] = {"get","veto","bem","abc","gea","bcd"};

  // Printing original array
  cout<<"Given array: ";
  for(int i=0; i<6; ++i)
    cout<<arr[i]<<" ";

  //Sorting array
  sortStrings(arr, 6);

  // Printing sorted array
  cout<<"\nSorted array: ";
  for(int i=0; i<6; ++i)
    cout<<arr[i]<<" ";
  cout<<endl;
  
  return 0;
}