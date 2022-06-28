#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void FS(int size){
    int FS[size];
    FS[0] = 0;
    FS[1] = 1;
    for(int i = 2; i < size; i++){
        FS[i] = FS[i-1] + FS[i-2];
    }
    for(int j = 0; j < size; j++){
        printf("%d  ", FS[j]);
    }
}

void main(){
    FS(20);
    printf("\n");
}