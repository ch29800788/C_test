#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void leetcodetest1(void){
    int nums1[] = {2,7,11,15} ;
    int nums2[] = {3,2,4} ;
    int nums3[] = {3,3} ;
    int target1 = 9;
    int target2 = 6;
    int target3 = 6;    
    int *ans1, *ans2, *ans3;
    int *size;
    
    ans1 = twoSum(nums1, 4, target1, size);
    ans2 = twoSum(nums2, 3, target2, size);
    ans3 = twoSum(nums3, 2, target3, size);

    for(int i = 0; i < 2; i++){
        printf("ans1[%d] = %d\n", i, ans1[i]);
    }
    for(int i = 0; i < 2; i++){
        printf("ans2[%d] = %d\n", i, ans2[i]);
    }
    for(int i = 0; i < 2; i++){
        printf("ans3[%d] = %d\n", i, ans3[i]);
    }    
}

int test1(void){
    printf("testfunction");
    return 20;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int diff;
    int *two = malloc(2*sizeof(int));
    for(int i = 0; i < numsSize; i++){
        diff = target - nums[i];
        for(int j = i+1; j < numsSize; j++){
            if(nums[j] == diff){
                two[0] = i;
                two[1] = j;
                *returnSize = 2;
                return two;
            }
            else{
                continue;
            }
        }        
    }
    free(two);
}

void test(){
    int A = 10;
    printf("%d", A);
}