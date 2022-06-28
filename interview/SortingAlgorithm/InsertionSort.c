#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *arr, int size){
    int j;
    int value;
    int mini;
    for(int i = 1; i < size; i++){
        j = i-1;
        value = arr[i];
        while(j >= 0 && arr[j] > value){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}

int main(){
    int arr[6] = {9,0,3,-1,9,8};

    printf("before sorting\n");
    for(int i = 0; i < 6; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    insertionsort(arr, 6);
    printf("after sorting\n");
    for(int i = 0; i < 6; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }    
    return 0;
}