#include <stdio.h>
#include <stdlib.h>

typedef union{
    long p;
    char a[4];
}endian;

void main(){
    endian test;
    test.p = 0x12345678;
    for(int i = 0; i < 4; i++){
        printf("%2x\t", test.a[i]);
    }
    if(test.a[0] == 0x78)   printf("little\n");
    else                    printf("big\n");
    system("pause");
}