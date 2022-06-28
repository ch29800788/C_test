#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s){
    int *hashT = (int *)malloc(sizeof(int)*127);
    int start_number = 0; 
    int max = 0;
    int temp = 0;

    for(int i = 0; i < 127; i++){
        hashT[i] = -1;
    }    

    if(strlen(s)==1)    return 1;
    if(strlen(s)==2){
        if(s[0]==s[1])  return 1;
        else            return 2;
    }

    for(int i = 0; i < strlen(s); i++){
        if((hashT[s[i]]) >= start_number){
            start_number = hashT[s[i]]+1;
            hashT[s[i]] = i;
        }
        else{
            hashT[s[i]] = i;
            temp = i - start_number + 1;
            if(temp > max)  max = temp;
        }
        printf("start = %d, max = %d\n", start_number, max);
    }
    return max;
}

void main(){
    char Q1[10] = {'a', 'b', 'c', 'a', 'b', 'c', 'b', 'b', '\0'};
    char Q2[10] = {'b', 'b', 'b', 'b', 'b'};
    char Q3[10] = {'p', 'w', 'w', 'k', 'e', 'w'};
    char Q4[10] = {' '};
    char Q5[10] = {'d', 'v', 'd', 'f'};

    printf("max substring length = %d\n", lengthOfLongestSubstring(Q1));
    printf("==============================\n");
    printf("max substring length = %d\n", lengthOfLongestSubstring(Q2));
    printf("==============================\n");    
    printf("max substring length = %d\n", lengthOfLongestSubstring(Q3));
    printf("==============================\n");   
    printf("max substring length = %d\n", lengthOfLongestSubstring(Q4));
    printf("==============================\n");
    printf("max substring length = %d\n", lengthOfLongestSubstring(Q5));

    system("pause");
}
