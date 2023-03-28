#include <stdio.h>
#include <iostream>
#include <time.h>
//#include <bits/stdc++.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


int arrays[5][30000];
int array_lengths[5] = {2,3,6,7,8};//500, 2000, 7500, 12000, 20000};


void merge (int arr[], int left, int mid, int right){

    int sorted_array[right-left+1];
    int leftArray[mid-left+1];
    int rightArray[right-mid];
    
    for (int i=0; i<mid+1; i++){
        leftArray[i] = arr[i];
    }
    for (int j=0; j<right-mid; j++){
        rightArray[j] = arr[j+mid+1];
    }
    
    int a=0;
    int b=0;
    int k=0;
    while (a<=mid-left+1 && b<=right-mid){
        if (leftArray[a]>=rightArray[b]){
            sorted_array[k]=rightArray[b];
            b++;
            k++;
        }
        else if (leftArray[a]<rightArray[b]){
            sorted_array[k]=leftArray[a];
            a++;
            k++;
        }
        else {
            cout << "Error in code";
        }
    }
    if (a<=mid-left+1){
        for(a;a<=mid-left+1;a++){
            sorted_array[k]=leftArray[a];
            k++;
        }
    }
    else if (b<=right-mid){
        for(b;b<=mid-left+1;b++){
            sorted_array[k]=rightArray[b];
            k++;
        }
    }
    else {
        cout << "Error in code";
    }
    
}


void mergeSort (int arr[],int left,int right){
    if (left>=right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}


void mergeSort_nonrecurrsive(int arr[], int left, int mid, int right){
    int available_amount_of_arrays = sizeof(arr)/sizeof(arr[0]); // size of sorted array
    int size_of_sorted_array = 1;
    while (available_amount_of_arrays>1){
        if (available_amount_of_arrays%2==0){
            // even amount 
            for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i=i+(size_of_sorted_array*2)){
                merge(arr,i,i+size_of_sorted_array,i+size_of_sorted_array*2-1);
            }
            available_amount_of_arrays = available_amount_of_arrays/2;
            size_of_sorted_array = size_of_sorted_array*2;
        }
        else if (available_amount_of_arrays%2==1){
            // odd amount 

            for (int i=0; i<sizeof(arr)/sizeof(arr[0])-1; i=i+(size_of_sorted_array*2)){
                merge(arr,i,(i+size_of_sorted_array)/2,i+size_of_sorted_array);
            }
            available_amount_of_arrays = available_amount_of_arrays/2+1;
            size_of_sorted_array = size_of_sorted_array*2;
        }
    }    
}

void print_array(int arr[] , int arr_len){
    for (int i=0; i<arr_len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
	
int main() {

    int num;
    clock_t start, end;
    double time_spent;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < array_lengths[i]; j++) {
            num = rand() % 100;
            arrays[i][j] = num;
        }
        printf("Total elements in the array: %d\n", array_lengths[i]);
        start = clock();
        print_array(arrays[i], array_lengths[i]);
        mergeSort(arrays[i], 0,array_lengths[i]-1);
        print_array(arrays[i], array_lengths[i]);
        end = clock();
        time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken is %.6f s\n", time_spent);
    }

    return 0;
}
    





