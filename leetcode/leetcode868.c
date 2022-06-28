#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binaryGap(int n){
    int size = 32;
    int longest = 0;
    int start=0;
    bool flag = false;
    if((n & (n-1)) == 0){
        return 0;
    }
    for(int i = 0; i < size; i++){
        if((n & 1) != 0){
            if(flag == true)    longest = i-start > longest? i-start: longest;
            start = i;
            flag = true;
        }
        n = n >> 1;
    }
    return longest;
}

void main(){
    int A = 12;
    // printf("%d, %d, %d\n", A&1, A, A>>1);
    printf("ans=%d", binaryGap(A));
}