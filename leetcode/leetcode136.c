#include <stdio.h>
#include <stdlib.h>

// int singleNumber(int* nums, int numsSize){
//     int curr = 0;
//     int search = 0;
//     int count = 0;
//     int loop = 0;
//     if(numsSize == 0)   return 0;
//     else if(numsSize == 1)  return nums[0];
//     else{
//         while(1){
//             count = 0;
//             printf("curr=%d, search=%d, count=%d\n", curr, search, count);
//             if(curr != search){
//                 if(nums[curr] == nums[search]){
//                     curr++;
//                     count++;
//                     search = -1;
//                     loop = 0;
                    
//                 }
//             }
//             search++;
//             if(count == 0 && search == numsSize)  return nums[curr];
//             else if(curr >= numsSize)    return 0;
//         }
//     }
// }

int singleNumber(int* nums, int numsSize){
    if(numsSize == 0)   return 0;
    else if(numsSize == 1)  return nums[0];
    else{
        while(numsSize != 1){
            nums[0] ^= nums[numsSize-1];
            numsSize--;
        }
        return nums[0];
    }
}

void main(){
    int A[]={2, 2, 1};
    int B[]={4, 1, 2, 1, 2};
    int C[]={1};
    int ans;
    ans = singleNumber(A, 3);
    printf("%d\n", ans);
    ans = singleNumber(B, 5);
    printf("%d\n", ans);
    ans = singleNumber(C, 1);
    printf("%d\n", ans);        
}