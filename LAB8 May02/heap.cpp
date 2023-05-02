#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   if(root==0){
      return;
   }
   if(root%2==1){ // left root
      if(arr[root]>arr[root/2]){
         int temp = arr[root/2];
         arr[root/2] = arr[root];
         arr[root] = temp;
         heapify(arr, n, root/2);
      }
   
   }
   else{ // right root
      int max = arr[root-1];
      int maxindex = root-1;
      if (arr[root]>arr[root-1]){
         max = arr[root];
         maxindex = root;
      }
      if (arr[maxindex]>arr[(maxindex-1)/2]){  
         int temp = arr[(maxindex-1)/2];
         arr[(maxindex-1)/2] = arr[maxindex];
         arr[maxindex] = arr[(maxindex-1)/2];
         heapify(arr, n, (maxindex-1)/2);
      }
      
   }
   
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=1; i<n; i++){
      heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   for (int i=0; i<n; i++){
      int temp = arr[n-1-i];
      arr[n-1-i] = arr[0];
      arr[0] = temp;
      heapify(arr, i, 0);
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
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}