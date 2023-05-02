#include <iostream>
using namespace std;
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// function to heapify the tree
void heapify(int arr[], int n, int root){
   // build heapify
   if(2*root+1>=n && 2*root+2>=n){
      return;
   }
   if(2*root+1>=n){
      if(arr[root]<arr[2*root+1]){
         int temp = arr[2*root+1];
         arr[2*root+1] = arr[root];
         arr[root] = temp;
         return heapify(arr, n, 2*root+1);
      }
   }
   else{ 
      if(arr[2*root+1]>arr[2*root+2]){
         if(arr[root]<arr[2*root+1]){
            int temp = arr[2*root+1];
            arr[2*root+1] = arr[root];
            arr[root] = temp;
            return heapify(arr, n, arr[2*root+1]);
         }
      }
      else{
         if(arr[root]<arr[2*root+2]){
            int temp = arr[2*root+2];
            arr[2*root+2] = arr[root];
            arr[root] = temp;
            return heapify(arr, n, arr[2*root+2]);
         }
      }
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=1; i<n; i++){
      int j = i;
      while ((j-1)/2>=0){
         if(arr[j]>arr[(j-1)/2]){
            int temp = arr[(j-1)/2];
            arr[(j-1)/2] = arr[j];
            arr[j] = temp;
         }
         j = (j-1)/2;
         if (j==0){
            break;
         }
      }
   }
   //displayArray(arr, n);
   // extracting elements from heap one by one
   for (int i=0; i<n; i++){
      int temp = arr[n-1-i];
      arr[n-1-i] = arr[0];
      arr[0] = temp;
      heapify(arr, n-1-i, 0);
      //displayArray(arr,n);
   }
   
}
  


  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6,56,4};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}