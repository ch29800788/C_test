#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int B = 2;
void func1(int *p)
{
    *p = 10;
    printf("%d\n", *p);
    p = &B;
    printf("%d\n", *p);
}
void func2(int **p)
{ 
    *p = &B;
}

union StateMachine {
    char character;
    int number;
    char *str;     //32-bits: 4     64-bits: 8
};

int main(void) {
    // 金字塔
    // int start = 9;
    // int loop = start/2 + 1;       
    
    // for(int i = 0; i < loop; i++){
    //     for(int k = 0; k < i; k++){
    //         printf(" ");
    //     }
    //     for(int j = start; j > 0; j--){
    //         printf("%d", start);
    //     }
    //     printf("\n");
    //     start -= 2;
    // }
    // 金字塔
    
    //給兩個array塞數字，取差距最近的pair，答出來後，會問有沒有更快的方法
    // int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int b[10] = {12, 2, 3, 66, 7, 8, 99, 4 ,0 ,4};
    // int miniIndex; 
    // int mini = abs(a[0]-b[0]);
    // for(int i = 1; i < 10; i++){
    //     if(mini > abs(a[i]-b[i])){
    //         mini = abs(a[i]-b[i]);
    //         miniIndex = i;
    //     }
    // }
    // printf("index = %d", miniIndex);
    //給兩個array塞數字，取差距最近的pair，答出來後，會問有沒有更快的方法

    //string severse
    // char A[10] = "helloworld";
    // int i, j;
    // printf("%s\n", A);
    // for(i = 0, j = 8; i<j; i++, j--){
    //     char temp = A[i];
    //     A[i] = A[j];
    //     A[j] = temp;
    // }
    // printf("\n%s\n", A);    
    //string reverse
    union StateMachine machine;
    machine.number = 1;
    printf("sizeof: %lu\n", sizeof(machine));
    printf("number: %d\n", machine.number);
    return 0;
}
