#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    if(head == NULL || head->next == NULL)  return head;
    int count = 0;
    struct ListNode *start = malloc(sizeof(struct ListNode*));
    start = head;
    while(head != NULL){
        count += 1;
        head = head->next;
    }
    head = start;
    for(int i = 0; i < count/2; i++){
        head = head->next;
    }
    return head;
}

int main(){
    printf("hh");
    return 0;
}