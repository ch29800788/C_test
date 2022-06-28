#include <stdio.h>
#include <stdlib.h>

typedef int (*Func)(int, int);

int ADD(int a, int b){
    return a+b;
}

int MINUS(int a, int b){
    return a-b;
}

int f(int a, int b, Func opt){
    return opt(a, b);
}

Func opt[4] = {
    ADD, 
    MINUS,
    ADD,
    MINUS
};

int (*FF[2])(int, int) = {
    ADD,
    MINUS
};

int (*FFF)(int, int);

int main(void) {
    printf("%d\n", f(3, 2, ADD));
    printf("%d\n", f(3, 2, MINUS));
    printf("%d\n", f(3, 2, opt[0]));
    printf("%d\n", f(3, 2, opt[1]));
    printf("%d\n", f(3, 2, FF[0]));
    printf("%d\n", f(3, 2, FF[1]));
    FFF = ADD;
    printf("%d\n", f(3, 2, FFF));
    FFF = MINUS;
    printf("%d\n", f(3, 2, FFF));        
    return 0;
}


