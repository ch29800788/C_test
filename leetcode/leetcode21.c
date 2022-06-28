#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head = malloc(sizeof(struct ListNode));    //要善用dummy指標
    struct ListNode *ptr = head;

    if(!list1 && !list2) return NULL;
    while(list1 && list2){
        if(list1->val < list2->val){
            ptr->next = list1;  //第一次的ptr的動作會等同head的動作
            list1 = list1->next;
        }
        else{
            ptr->next = list2;  //第一次的ptr的動作會等同head的動作
            list2 = list2->next;
        }
        ptr = ptr->next;    //ptr指到自己下個ptr, 與head劃清界線
    }
    if(list1)   ptr->next = list1;
    if(list2)   ptr->next = list2;
    return head->next;
}

int main(){
    ListNode *A = (ListNode *)malloc(sizeof(ListNode));
    ListNode *A1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *A2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *B = (ListNode *)malloc(sizeof(ListNode));
    ListNode *B1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *B2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *C = (ListNode *)malloc(sizeof(ListNode));
    A->val = 1;
    A->next = A1;
    A1->val = 2;
    A1->next = A2;
    A2->val = 4;
    A2->next = NULL;
    B->val= 1;
    B->next = B1;
    B1->val = 3;
    B1->next = B2;
    B2->val = 4;
    B2->next = NULL;
    C = mergeTwoLists(A, B);
    while(C){
        printf("%d\t", C->val);
        C = C->next;
    }
    if(C==NULL) printf("\nheaal");
    return 0;
}