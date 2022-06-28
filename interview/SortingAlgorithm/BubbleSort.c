#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *arr, int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[6] = {9,0,3,-1,9,8};

    printf("before sorting\n");
    for(int i = 0; i < 6; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    bubblesort(arr, 6);
    printf("after sorting\n");
    for(int i = 0; i < 6; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }    
    return 0;
}