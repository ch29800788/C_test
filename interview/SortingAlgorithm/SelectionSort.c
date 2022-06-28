#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *arr, int size){
    int mini = 0;
    int index = 0;
    printf("a\n");
    for(int i = 0; i < size; i++){
        mini = arr[i];
        index = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < mini){
                printf("b\n");
                mini = arr[j];
                index = j;
            }
        }
        swap(&arr[i], &arr[index]);
    }
}

int main(){
    int arr[6] = {9,0,3,-1,9,8};

    printf("before sorting\n");
    for(int i = 0; i < 6; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    selectionsort(arr, 6);
    printf("after sorting\n");
    for(int i = 0; i < 6; i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }    
    return 0;
}