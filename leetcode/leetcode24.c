#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL)  return head;
    struct ListNode *prev = head;
    struct ListNode *curr = prev->next;
    if(curr->next == NULL){
        curr->next = prev;
        prev->next = NULL;
        return curr;
    }
    struct ListNode *next = curr->next;
    if(next->next == NULL){
        curr->next = prev;
        prev->next = next;
        return curr;
    }
    int count = 0;
    struct ListNode *root = curr;
    while(prev!=NULL){
        count++;
        prev = prev->next;
    }
    prev = head;
    for(int i = 1; i < count/2; i++){
        if(count%2==1){
            if(next->next == NULL){
                curr->next = prev;
                prev->next = next;
                return root;
            }
            else{
                curr->next = prev;
                prev->next = next->next;
                curr = next->next;
                prev = next;
                next = curr->next;
            }
        }
        else{
            if(curr->next == NULL){
                curr->next = prev;
                prev->next = NULL;
                return root;
            }
            else{
                curr->next = prev;
                prev->next = next->next;
                curr = next->next;
                prev = next;
                if(curr->next != NULL)  next = curr->next;
            }
        }
    }
}

void main(){

}
