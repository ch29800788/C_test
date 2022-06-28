#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MIN(a, b)   (a) < (b)? a:b
#define ADD(a, b)   (a)+(b)

void main(){   
    int a = 1;
    int b = 2;
    int ans[15] = {};
    int answer = 0;
    int count = 1;
    int i=0;
    //set bit
    i = i | 1<<3;
    printf("%d\n", i);
    i = i | 1<<2;
    printf("%d\n", i);    
    i = i & (~(1<<3));
    printf("%d\n", i);
    // int *ptr;
    // ptr = (int *)0x67a9;
    // *ptr = 0x6874;
    // printf("address = %p, value = %p\n", ptr, *ptr);
    // printf("%d\n", MIN(a, b));
    // printf("%d\n", ADD(a, b));
    // ans[0] = 1;
    // while(1){
    //     ans[i] = ans[i-1]+i;
    //     if(ans[i]==106) break;
    //     i++;
    // }

    // for(j = 0; j <= i ; j++){
    //     printf("ans[%d] = %d\n", j, ans[j]);
    //     answer += ans[j];
    // }
    // printf("answer = %d\n", answer);
    return;
}


