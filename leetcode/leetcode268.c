#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int QuickSortPartition(int *arr, int low, int high){
    int value = arr[high];
    int ptr = low-1;
    for(int i = low; i < high; i++){
        if(arr[i]< value){
            ptr++;
            swap(&arr[i], &arr[ptr]);
        }
    }
    swap(&arr[++ptr], &arr[high]);
    return ptr;
}

void QuickSort(int *arr, int low, int high){
    if(high > low){
        int mid = QuickSortPartition(arr, low, high);\
        QuickSort(arr, low, mid-1);
        QuickSort(arr, mid+1, high);
    }
}

int missingNumber(int* nums, int numsSize){
    int low = 0;
    int high = numsSize-1;
    int ans[numsSize+1];
    memset(ans, 0, (numsSize+1)*sizeof(ans[0]));
    for(int j = 0; j < numsSize+1; j++){
        printf("ans[%d]=%d\n", j, ans[j]);
    }    
    QuickSort(nums, low, high);
    for(int i = 0; i < numsSize; i++){
        printf("nums[%d]=%d\n", i, nums[i]);
        ans[nums[i]] = 1;
    }
    for(int j = 0; j < numsSize+1; j++){
        printf("ans[%d]=%d\n", j, ans[j]);
        if(ans[j]==0)   return j;
    }
    return 0;
}

void main(){
    int A[] = {3,0,1};
    int B[] = {0,1};
    int C[] = {9,6,4,2,3,5,7,0,1};
    int size;
    size = sizeof(A)/sizeof(A[0]);
    printf("find %d\n", missingNumber(A, size));
    size = sizeof(B)/sizeof(B[0]);
    printf("find %d\n", missingNumber(B, size));
    size = sizeof(C)/sizeof(C[0]);
    printf("find %d\n", missingNumber(C, size));

}