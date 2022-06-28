#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int *returnSize){
    int *arr = malloc(sizeof(int)*(n+1));
    int last;

    if(n == 0){
        arr[0] = 0;
        *returnSize = 1;
        return arr;
    }    
    if(n == 1){
        arr[0] = 0;
        arr[1] = 1;
        *returnSize = 2;
        return arr;
    }
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!(i&(i-1))){
            arr[i] = 1;
            last = i;
        }
        else{
            arr[i] = 1+arr[i-last];
        }
    }

    *returnSize = n+1;
    return arr;
}

void main(){
    int *arr;
    int *returnSize = malloc(sizeof(int));
    arr = countBits(5, returnSize);
}