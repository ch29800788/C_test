#include <stdio.h>
#include <stdlib.h>

int BinarySearchRecursion(int *arr, int low, int high, int value){ 
    int mid = (low+high)/2;
    if(arr[mid] < value){
        BinarySearchRecursion(arr, mid+1, high, value);
    }
    else if(arr[mid] > value){
        BinarySearchRecursion(arr, low, mid, value);
    }
    else if(arr[mid] == value){
        return mid;
    }
    else    return -1;
}

int search(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    int arr[6] = {-1,0,3,5,9,12};
    int ans;
    ans = search(arr, 6, 9);
    printf("find %d\n", ans);
    return 0;
}