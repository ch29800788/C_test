#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef int (*MathMethod)(int, int); 
int Mul(int a, int b){return a*b;}
int Divide(int a, int b){return a/b;}
int Minus(int a, int b){return a-b;}
int Add(int a, int b){return a+b;}
int Calc(int x, int y, MathMethod Opt){
    return Opt(x, y);
} 
    
int main(){
    // printf("short: %d\n", sizeof(short));
    // printf("long: %d\n", sizeof(long));
    // printf("long long: %d\n", sizeof(long long));
    // printf("size_t: %d\n", sizeof(size_t));
    // printf("double: %d\n", sizeof(double));
    // printf("long double: %d\n", sizeof(long double));
    // printf("float: %d\n", sizeof(float));
    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int *p = &(a + 1)[3];
    int a = 2;
    char b = '0';
    char c = a+b;
    printf("%d\n", a+b);
    printf("%c\n", a+b);

    // printf("%d\n", *p);
    return 0;
}

// 64bit
// sizeof(string)       = 8
// sizeof(char)         = 1
// sizeof(p)            = 8  //實測是4
// sizeof(short)        = 2
// sizeof(int)          = 4
// sizeof(long)         = 8
// sizeof(long long)    = 8
// sizeof(size_t)       = 8
// sizeof(double)       = 8
// sizeof(long double)  = 16