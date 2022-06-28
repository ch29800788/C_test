#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 10

//Q1: 給一個int a[20]已排序的陣列，請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素，請用最少的時間和空間複雜度完成。
void phison1(int array[], int size){
    int index = 0;
    int printcount = 0;
    for(int i = 0; i < 501; i++){
        if(array[index] == i){
            index++;
            continue;
        }
        printf("%d, ", i);
        printcount++;
        if(printcount%10 == 0)  printf("\n");
    }
}

//Q2: 給一個int a[20]已排序的陣列，請寫一個function(a, size, b)能依照參數b(b = 0~4)別印出該區間的數字，且不包含a陣列內的元素
//0: 0~99, 1: 100~199, ...
void phison2(int array[], int size, int B){
    int index = 0;
    int printcount = 0;
    while(array[index]< B*100){
        index++;
    }
    for(int i = B*100; i < (B+1)*100; i++){
        if(array[index] == i){
            index++;
            continue;
        }
        printf("%d, ", i);
        printcount++;
        if(printcount%10 == 0)  printf("\n");
    }
}

/* Q3:
條件一  ListArray[Entry1].NextPtr = ListArray[Entry2]
條件二  ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL > ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL
請寫一個function(unsigned int DATA_A, unsigned int DATA_B)，
能在ListArray中找到符合ListArray[Entry].DataH == Data_A 且 ListArray[Entry].DataL == Data_B
並印出其結果。如果沒有找到的話，印出”no found.”。
*/

struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;

void phison3(unsigned int DATA_A, unsigned int DATA_B){
    int found = ListHead;
    int pre = NULL;
    int next = NULL;
    while(ListArray[found].NextPtr != NULL){
        if(ListArray[found].DataH == DATA_A && ListArray[found].DataL == DATA_B){
            printf("found array[%d]", found);
        }
        next = ListArray[found].NextPtr;
        if(ListArray[next].DataH << 16 + ListArray[next].DataL > ListArray[found].DataH << 16 + ListArray[found].DataL){
            break;
        }

        pre = found;
        found = ListArray[found].NextPtr;
    }
}

//swap
void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

//find partition
int FindPartition(int *array, int low, int high){
    int pivot = array[high];
    int j = low-1;
    for(int i = low; i < high; i++){
        if(array[i]< pivot){
            j++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[j+1], &array[high]);
    return (j+1);
}

//quick sort
void QuickSort(int *array, int low, int high){
    if(high > low){
        int index = FindPartition(array, low, high);
        QuickSort(array, low, index-1);
        QuickSort(array, index+1, high);  
    }
}

void PrintArray(int *array, int size){
    for(int i=0; i<size; i++){
        printf("array[%d]=%d\n", i, array[i]);
    }
}

int main(){
    int a[length] = {11, 3, 66, 23, 5, 88, 30, 1, 2, 55};
    // PrintArray(a, length);
    // printf("=====================================\n");
    QuickSort(a, 0, length-1);
    // printf("=====================================\n");    
    // PrintArray(a, length);
    phison2(a, length, 0);
    return 0;
}