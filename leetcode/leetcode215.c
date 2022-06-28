#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

void SelectionSort(int *arr, int size){
    for(int i = 0; i < size; i++){
        int mini = i;
        for(int j = i+1; j<size; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(&arr[i], &arr[mini]);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    SelectionSort(nums, numsSize);
    return nums[numsSize-k];
}

void main(){
    int nums[] = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int size;
    int ans;
    size = sizeof(nums)/sizeof(nums[0]);
    ans = findKthLargest(nums, size, k);
    printf("find %dth large: %d", k, ans);
    // for(int i = 0; i < size; i++){
    //     printf("%d ", nums[i]);
    // }
}