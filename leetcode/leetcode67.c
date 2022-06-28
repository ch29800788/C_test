#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* addBinary(char* a, char* b)
{
    int i, j, k, c = 0;
    char *res;
    
    i = strlen(a);
    j = strlen(b);
    k = i > j ? i : j;
    k += 2;

    res = malloc(k * sizeof(char));
    
    i--;
    j--;
    res[--k] = '\0';
    
    while (--k >= 0) {
        c += i >= 0 ? a[i--] - '0': 0;
        printf("%d, %c\n", c, a[i]);
        c += j >= 0 ? b[j--] - '0': 0;
        printf("%d, %c\n", c, b[j]);
        res[k] = c % 2 + '0';
        c /= 2;
    }
    
    if (res[0] == '0')
       memmove(res, res + 1, strlen(res) * sizeof(char));
    
    return res;
}

void main(){
    char *a = "11";
    char *a1 = "1";
    char *b = "1010";
    char *b1 = "1011";
    char *ans;
    int length;

    ans = addBinary(a, a1);
    length = strlen(ans);
    for(int i = 0; i < length; i++){
        printf("%c", ans[i]);
    }
    printf("\n");

    // ans = addBinary(b, b1);
    // length = strlen(ans);
    // for(int j = 0; j < strlen(ans); j++){
    //     printf("%c", ans[j]);
    // }
    // printf("\n");
}
/*
Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"
*/