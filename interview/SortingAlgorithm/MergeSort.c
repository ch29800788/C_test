#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int low, int mid, int high){
    int leftindex = low;
    int rightindex = mid+1;
    int templength = high-low+1;
    int temp[templength];
    int tempindex = 0;

    while(leftindex <= mid && rightindex <= high){
        if(arr[leftindex] < arr[rightindex]){
            temp[tempindex] = arr[leftindex];
            leftindex++;
        }
        else{
            temp[tempindex] = arr[rightindex];
            rightindex++;
        }
        tempindex++;
    }
    if(leftindex > mid){
        while(rightindex <= high){
            temp[tempindex] = arr[rightindex];
            tempindex++;
            rightindex++;
        }
    }
    else{
        while(leftindex <= mid){
            temp[tempindex] = arr[leftindex];
            tempindex++;
            leftindex++;
        }
    }
    leftindex = low;
    for(tempindex = 0; tempindex < templength ; tempindex++){
        arr[leftindex] = temp[tempindex];
        leftindex++;
    }
}
    
void mergesort(int *arr, int low, int high){
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main(){
    int arr[8] = {4, 6, 1, 9, 5, 3, 0, 2};
    int dataNum = 8;
    int i;
    printf("%d\n", 1/2);
    printf("before sorting: ");
    for (i=0; i<dataNum; i++)
        printf("%d " , arr[i]);
    printf("\n");
    mergesort(arr, 0, dataNum - 1);
    printf("after sorting: ");
    for (i=0; i<dataNum; i++)
        printf("%d " , arr[i]);
    printf("\n");
}