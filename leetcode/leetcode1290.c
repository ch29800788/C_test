#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *Reverse(struct ListNode *self){
    if(self == NULL && self->next == NULL)  return self;
    struct ListNode *prev = NULL;
    struct ListNode *curr = self;
    struct ListNode *next = self->next;
    
    while(next != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    return curr;
}

int getDecimalValue(struct ListNode* head){
    if(head == NULL)    return 0;
    int count = 0;
    int ans = 0;
    struct ListNode *reverse = Reverse(head);
    while(reverse != NULL){
        ans += reverse->val*pow(2, count);
        count +=1;
        reverse = reverse->next;
    }
    return ans;
}

int main(){
    printf("hh");
    return 0;
}