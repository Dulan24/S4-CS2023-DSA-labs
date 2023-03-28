#include <stdio.h>
#include <iostream>
#include <time.h>
//#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

using namespace std;

//int array1[5] = {3,2,6,1,4};
//int arrays[5][20];
//int array_lengths[5] = {3, 5, 7, 15, 20};
//int** arrays[5];

int main (){
    int arr_len = 0;
    int arr1[3] = {20,19,18};
    int arr2[5] = {20,19,18,17,16};
    int arr3[7] = {20,19,18,17,16,15,14};
    int arr4[15] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6};
    int arr5[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    double time_spent = 0.0;
    int array_lengths[5] = {3, 5, 7, 15, 20};

    cout << "Insertion Sort: \n";

    cout << "total elements in array: 3";
    cout << "\n";
    clock_t begin = clock();
    insertion_sort(arr1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "time taken is ";
    cout << time_spent;
    cout << "\n";
    cout << "total elements in array: 5";
    cout << "\n";
    clock_t begin = clock();
 
}

void insertion_sort(int arr[]){
    int array_size = sizeof(arr)/sizeof(arr[0]);
    int i, value, j;
    for (i = 1; i < array_size; i++){
        value = arr[i];
        j = i - 1;
        while (j >= 0 && arr[i] < arr[j]){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = value;
    }
}

void bubble_sort(int arr[]){
    int array_size = sizeof(arr)/sizeof(arr[0]);
    int i,j,value;
    for (i = 0; i < array_size - 1; i++){
        for (j = i; j < array_size - 1; j++){
            if(arr[j + 1] > arr[j]){
                value = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = value;
            }
        }
    }
}

void optimized_bubble_sort(int arr[]){
    int array_size = sizeof(arr)/sizeof(arr[0]);
    int i,j,value;
    bool swap = false;
    for (i = 0; i < array_size - 1; i++){
        for (j = i; j < array_size - 1; j++){
            if(arr[j + 1] > arr[j]){
                value = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = value;
                swap = true;
            }
        }
        if (!swap){
            break;
        }
    }
}

void selection_sort(int arr[]){
    int array_size = sizeof(arr)/sizeof(arr[0]);
    int i,j,value,index_value;
    bool smallest_found = false;
    for (i = 0; i < array_size; i++){
        value = arr[i];
        index_value = i;
        for (j = i + 1; j < array_size; j++){
            if (value > arr[j]){
                value = arr[j];
                index_value = j;
                smallest_found = true;
            }
        }
        if (smallest_found) {
            arr [index_value] = arr[i];
            arr[i] = value;
        }
    }
}
/*
void print_array(int arr){
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/