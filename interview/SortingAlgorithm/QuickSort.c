#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int FindPatition(int array[], int low, int high){
    int pivot = array[high];
    int midindex = low-1;
    for(int i = low; i < high; i++){
        if(array[i] < pivot){
            swap(&array[midindex+1], &array[i]);
            midindex++;
        }
    }
    swap(&array[midindex+1], &array[high]);
    return midindex+1;
} 

void QuickSort(int array[], int low, int high){
    if(high > low){
        int index = FindPatition(array, low, high);
        QuickSort(array, low, index-1);
        QuickSort(array, index+1, high);
        }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array\n");
    printArray(data, n);
    
    // perform quicksort on data
    QuickSort(data, 0, n - 1);
    
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}