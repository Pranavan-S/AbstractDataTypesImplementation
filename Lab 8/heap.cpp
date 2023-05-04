#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int maximum  = root;
   int left = (2*root)+1;
   int right = (2*root)+2;

   if (right < n && arr[root] < arr[right]){
      maximum = right;
   }
   if (left < n && arr[maximum] < arr[left]){
      maximum = left;
   }
   if (maximum != root){
      swap(arr[root],arr[maximum]);
      heapify(arr,n,maximum);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int range = (n/2) - 1;
   for (int i = range; i>=0; i--){
      heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   int size = n;
   for (int i = n-1; i>=1; i--){
      swap(arr[i],arr[0]);
      size--;
      heapify(arr, size, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{  
   //length of the heap array
   int length;
   cout<<"Enter the array length: ";
   cin>>length;
   int heap_arr[length];
   
   //getting the elements for the heap.
   cout<<"Enter the array elements: ";
   for (int i = 0; i<length; i++){
      cin>>heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,length);
  
   heapSort(heap_arr, length);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, length);
   return 0;
}
