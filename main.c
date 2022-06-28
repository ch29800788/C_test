#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main(void) {

    int nums1[] = {2,7,11,15} ;
    int nums2[] = {3,2,4} ;
    int nums3[] = {3,3} ;
    int target1 = 9;
    int target2 = 6;
    int target3 = 6;    
    int *ans1, *ans2, *ans3;
    int *size;

    ans1 = twosum(nums1, 4, target1, size);
    printf("leetcode test:\n");
    ans2 = twosum(nums2, 3, target2, size);
    printf("leetcode test:\n");
    ans3 = twosum(nums3, 2, target3, size);
    printf("leetcode test:\n");

    for(int i = 0; i < 2; i++){
        printf("leetcode test1:\n");
        printf("ans1[%d] = %d\n", i, ans1[i]);
    }
    for(int i = 0; i < 2; i++){
        printf("leetcode test2:\n");
        printf("ans2[%d] = %d\n", i, ans2[i]);
    }
    for(int i = 0; i < 2; i++){
        printf("leetcode test3:\n");
        printf("ans3[%d] = %d\n", i, ans3[i]);
    }    
    printf("hi rbee:\n");
    system("PAUSE");
    return 0;
}


