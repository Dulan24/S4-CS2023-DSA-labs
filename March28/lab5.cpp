#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int arrays[5][100000];
int array_lengths[5] = {5000,10000,20000,40000,80000}; // 500, 2000, 7500, 12000, 20000

void quickSortNonRecurrsive(int arr[], int left, int right) {
    stack<int> stk;
    stk.push(left);
    stk.push(right);

    while (!stk.empty()) {
        right = stk.top();
        stk.pop();
        left = stk.top();
        stk.pop();

        int i = left, j = right;
        int pivot = arr[(left + right) / 2];

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) {
            stk.push(left);
            stk.push(j);
        }
        if (i < right) {
            stk.push(i);
            stk.push(right);
        }
    }
}

void quicksort(int arr[], int start, int end) {
    if (end <= start) {
        return;
    }
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;
    quicksort(arr, start, i);
    quicksort(arr, i + 2, end);
}

void print_array(int arr[], int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        cout << arr[i] << " ";
    }
    //cout << "\n";
}
	
int main() {
    int num;
    clock_t start, end;
    double time_spent;
    cout << "recurrsive times \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < array_lengths[i]; j++) {
            num = rand() % 100;
            arrays[i][j] = num;
        }
        printf("Total elements in the array: %d\n", array_lengths[i]);
        start = clock();
        //print_array(arrays[i], array_lengths[i]);
        quicksort(arrays[i], 0, array_lengths[i] - 1);
        //print_array(arrays[i], array_lengths[i]);
        end = clock();
        time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken is %.6f s\n", time_spent);
    }
    cout << "\n\n";
    cout << "non recurrsive times \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < array_lengths[i]; j++) {
            num = rand() % 100;
            arrays[i][j] = num;
        }
        printf("Total elements in the array: %d\n", array_lengths[i]);
        start = clock();
        //print_array(arrays[i], array_lengths[i]);
        quickSortNonRecurrsive(arrays[i], 0, array_lengths[i] - 1);
        //print_array(arrays[i], array_lengths[i]);
        end = clock();
        time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken is %.6f s\n", time_spent);
    }

    cout << "\n";
    
    int lengthofarray = 0;
    float median=0;
    cout << "\n";
    cout << "enter the length of numbers set : ";
    cin >> lengthofarray;
    int numbers[lengthofarray];
    cout << "enter the values to find median";
    cout << "\n";
    for(int i=0; i<lengthofarray; i++){
        cout << "type the " << i+1 << " number of the list ";
        cin >> numbers[i];
        quicksort(numbers,0,i);
        if ((i+1)%2==0){
            median = 0.5*(numbers[(i+1)/2]+numbers[(i+1)/2-1]);
        }
        else {
            median = numbers[(i+1)/2];
        }
        cout << "\n[";
        print_array(numbers,i+1);
        cout << "]";
        cout << "\nmedian is :" << median << "\n\n";

    }
    

    return 0;
}
