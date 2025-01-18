/* Q1. Given an Unsorted array of integers, sort the array into a wave array. An array arr[0⋯n−1]
 is sorted in wave form if:
arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=⋯

Write a function SortInwave(int arr[], int n) that uses the idea of sorting and then implement in the main() function.
*/

#include <iostream>
using namespace std;

//Function to sort in wave form using bubble sorting
void SortInWave(int arr[], int n)
{
  for(int i=0; i<n; ++i)
  {
    if(i%2==0){ //for element at even index
      if(arr[i]<arr[i+1]){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }
    else{ //for element at odd index
      if(arr[i]>arr[i+1]){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }
  }
}

int main()
{
  int arr[] = {5,20,18,20,5,23,-8,100};

  // Printing original array
  cout<<"Given array: ";
  for(int i=0; i<8; ++i)
    cout<<arr[i]<<" ";

  //Sorting array
  SortInWave(arr, 8);

  // Printing sorted array
  cout<<"\nSorted array: ";
  for(int i=0; i<8; ++i)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}

