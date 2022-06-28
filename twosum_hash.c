#include <stdio.h>
#include <stdlib.h>
#define HASHTABLESIZE 1000

typedef struct _listNode {
    int index;
    int value;
    struct _listNode *next;
} ListNode;

typedef struct _linkedlist {
    int size;
    ListNode *head;
} HashTableNode;

typedef struct _hashTable{
    int hSize;
    HashTableNode *Table;
} HashTable;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int hash(int);

void insertHash(HashTable *, int, int);

int hashSearch(HashTable, int, int *);

int* twosum(int* nums, int numsSize, int target, int* returnSize){

    HashTable pos_hashTable;
    HashTable neg_hashTable;
    
    pos_hashTable.Table = (HashTableNode *) malloc (sizeof(HashTableNode) * HASHTABLESIZE);
    neg_hashTable.Table = (HashTableNode *) malloc (sizeof(HashTableNode) * HASHTABLESIZE);

    for(int i = 0; i < HASHTABLESIZE; i ++){
        pos_hashTable.Table[i].head = NULL;
        neg_hashTable.Table[i].head = NULL;
        pos_hashTable.Table[i].size = 0;
        neg_hashTable.Table[i].size = 0;
    }

    int *arr;
    
    *returnSize = 2;
    arr = malloc((*returnSize) * sizeof(int));
    arr[0] = -1;
    arr[1] = -1;
    int num = 0;
    
    for(int i = 0; i < numsSize; i++){
        num = target - nums[i];
        // hashTable[0][i] for negative, hashTable[1][i] for positive
        if(num < 0){ 
            num = 0 - num;
            if(hashSearch(neg_hashTable,num, &arr[0]) == 0){
                if(nums[i] < 0){
                    num = 0 - nums[i];
                    insertHash(&neg_hashTable,num,i);
                } else {
                    insertHash(&pos_hashTable,nums[i],i);
                }
                //printf("%i\n",i);
            } else {
                arr[1] = i;
                break;
            }
        } else if (num >= 0){
            if(hashSearch(pos_hashTable,num, &arr[0]) == 0){
                if(nums[i] < 0){
                    num = 0 - nums[i];
                    insertHash(&neg_hashTable,num,i);
                } else {
                    insertHash(&pos_hashTable,nums[i],i);
                }
                //printf("%i\n",i);
            } else {
                arr[1] = i;
                break;
            }
        } 
            
    }
    
    return arr;
}

int hash (int key){
    
    return key % HASHTABLESIZE;
    
}

void insertHash(HashTable *hashTable, int num, int ind ){
    
    
    int val = hash(num);
    ListNode *temp;
    ListNode *curr = hashTable->Table[val].head;
    
    
    temp = (ListNode *) malloc(sizeof(ListNode));
    temp->index = ind;
    temp->value = num;
    temp->next = curr;
    hashTable->Table[val].head = temp;
    hashTable->Table[val].size++;
    
}

int hashSearch(HashTable hashTable, int num, int *arr0){
    
    if(hashTable.Table[hash(num)].head != NULL){
        
        ListNode *temp = hashTable.Table[hash(num)].head;
        while(temp != NULL){
            if(temp->value == num){
                
                *arr0 = temp->index;
                return 1;
            }
            temp = temp->next;
        }
    }
    
    return 0;
}