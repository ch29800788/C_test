#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0
#define SET_BIT(x,n) ((x) |= (1<< n))
#define CLEAR_BIT(x,n) ((x) &= (~(1 << n)))
#define CHECK_BIT(x,n) (((x) & (1 << (n))) != 0)
#define FILP_BIT(x,n) ((x) ^= (1<<(n)))
#define SQUARE(x) ((x)*(x))

//自定義: 二進制的顯示
void PrintBinary(unsigned int number){
    int length = sizeof(int)*8;
    int i;
    if(number == 0){
        printf("0");
        return;
    }
    for(i = length-1; i >=0; i--){
        if(number & (1<<i)) break;
    }
    for(; i >= 0; i--){
        printf("%d", (number & (1<<i)) != 0);
    }
    printf("\n");
    return; 
}

//找最高位元
int gethighestbit(unsigned int input){
    int n = 31;
    PrintBinary(input);
    if(input == 0){
        printf("have no input\n");
        return -1;
    }        
    if((input >> 16) == 0){
        n -= 16;
        input = input << 16;
        PrintBinary(input);
        printf("n = %d\n", n);
    }
    if((input >> 24) == 0){
        n -= 8;
        input = input << 8;
        PrintBinary(input);
        printf("n = %d\n", n);
    }
    if((input >> 28) == 0){
        n -= 4;
        input = input << 4;
        PrintBinary(input);
        printf("n = %d\n", n);
    }
    if((input >> 30) == 0){
        n -= 2;
        input = input << 2;
        PrintBinary(input);
        printf("n = %d\n", n);
    }
    if((input >> 31) == 0){
        n -= 1;
        PrintBinary(input);
        printf("n = %d\n", n);
    }    
    return n;
}

//找最低位元: 公式: 自己與"二補數"做"&", 就能得到只剩最低位元的值. ex: 0000 0100 ---------> result

int getlowestbit(unsigned int input){
    input = input & (~input+1);
    return gethighestbit(input);
}

//計數"1", 透過 x &= (x-1), 可把倒數的"1"漸漸消除
int numbers_of_1_in_int(unsigned int x){
    static int count;
    while(x != 0){
        x &= (x-1);
        count ++;
    }
    return count;
}

int main(){
    int a = 100;
    printf("highestbit = %d\n", gethighestbit(a));
    printf("lowestbit = %d\n", getlowestbit(a));
    printf("1 count = %d\n", numbers_of_1_in_int(a));
    // SET_BIT(a,1);
    // printf("%x\n",a);
    // CLEAR_BIT(a,1);
    // printf("%x\n",a);
    // FILP_BIT(a,1);
    // printf("%x\n",a);
    // printf("%d\n",CHECK_BIT(a,1));
    system("pause");
    return 0;
}