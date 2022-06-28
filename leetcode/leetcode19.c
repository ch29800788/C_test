#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *ptr = head;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    // printf("count=%d\n", count);
    ptr = head;
    if(n == 0)  return head;
    else if(n >count)   return head;
    else if(n == count){
        head = head->next;
        free(ptr);
        return head;
    }
    for(int i= 0; i < count-n-1; i++){
        ptr = ptr->next;
    }
    if(ptr->next->next != NULL){
        struct ListNode *temp;
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    else if(ptr->next != NULL && ptr->next->next == NULL){
        struct ListNode *temp;
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }
    else{
        free(ptr);
    }
    return head;
}

void main(){

}
