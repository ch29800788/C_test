#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void main(){
    int year, month, day, gap;
    int Y[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("enter year->(enter)->month->(enter)->day\n");
    scanf("%d%d%d", &year, &month, &day);
    printf("you enter: %d/%d/%d\n", year, month, day);

    printf("enter gap day\n");
    scanf("%d", &gap);
    day = day+gap;
    while(day > 0){
        if(year%4 == 0 || year%400 == 0)    Y[1] = 29;
        else    Y[1] = 28;
        printf("debug: year=%d, month=%d, day=%d\n", year, month, day);
        if(day-Y[month-1]>0){
            day -= Y[month-1];
            if(month == 12){
                month = 1;
                year += 1;
            }
            else    month += 1;
        }
        else    break;
    }
    printf("ans: year=%d, month=%d, day=%d\n", year, month, day);
}