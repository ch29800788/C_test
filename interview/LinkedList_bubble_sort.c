#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct stack{
    node *head;
}stack;

typedef struct linkedlist{
    node *head;
    node *tail;
}linkedlist;

stack *NewStack(){
    stack *StackTable = (stack *)malloc(sizeof(stack));
    if(!StackTable) return StackTable;
    StackTable->head = NULL;
    return StackTable;
}

linkedlist *NewLinkedlist(){
    linkedlist *Table = (linkedlist *)malloc(sizeof(linkedlist));
    if(!Table) return Table;
    Table->head = NULL;
    Table->tail = NULL;
    return Table;
}

void DeleteStack(stack *self){
    if (!self)  return;

    node *curr = self->head;
    while (curr) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(self);
}

bool IsEmpty(const stack *self){
    assert(self);
    return self->head == NULL;
}

int Peek(const stack *self){
    assert(!IsEmpty(self));
    return self->head->data;
}

node *NewData(int data){
    node *New = (node *)malloc(sizeof(node));
    if(!New)    return New;
    New->data = data;
    New->next = NULL;
    return New;
}

void NewLinkedListTableNode(linkedlist *self, int data){
    node *new = NewData(data);
    int count = 0;
    if(self->head == NULL){
        self->head = new;
        self->tail = new;
        printf("firstNode %d\n", new->data);
        return;
    }
    else{
        self->tail->next = new;
        self->tail = self->tail->next;
        printf("addNode %d\n", new->data);
    }
    return;
}

void EnStack(stack *self, int data){
    assert(self);
    node *new = NewData(data);
    new->next = self->head;
    self->head = new;
    return;
}

int DeStack(stack *self){
    assert(!IsEmpty(self));
    node *curr = self->head;
    // while(curr->next != NULL){
    //     curr = curr->next;
    // } 實驗用, 代表self->head沒因為curr往後指而改變
    int popped = self->head->data;
    node *top = self->head;
    self->head = self->head->next;
    free(top);
    return popped;
}

void BubbleSort(linkedlist *self){
    assert(self);
    int count = 0;
    node *prev = self->head;
    node *curr = self->head;
    node *temp = self->head;
    while(curr){
        printf("beforeSorting: %d\n", curr->data);
        count++;
        curr = curr->next;
    }
    //printf("%d\n", self->head->data);
    printf("count = %d\n", count);
    curr = self->head;
    for(int i=0; i<count-1; i++){
        // printf("enter loop\n");
        prev = self->head;
        curr = self->head;
        for(int j=0; j<count-i-1 && curr->next ; j++){
            if(curr->data > curr->next->data){
                temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                // printf("exchange\n");
                if(curr == self->head){
                    self->head = temp;
                    prev = temp;
                    // printf("head exchange\n");
                }
                else{
                    prev->next = temp;
                    prev = prev->next;
                } 
            }
            else{
                // printf("no exchange\n");
                curr = curr->next;
                if(j!=0)    prev = prev->next;
            }
            
        }
    }
}

void PrintStack(stack* self){
    node *tail = self->head;
    int count = 0;
    while(tail){
        printf("%d\n", tail->data);
        count++;
        tail = tail->next;
    }
    printf("linkedlistStack Size = %d", count);
} 

void PrintLinledListTable(linkedlist* self){
    node *curr = self->head;
    // printf("%d\n", curr->data);
    // printf("%d\n", curr->next->data);
    // printf("%d\n", curr->next->next->data);
    int count = 0;
    while(curr != NULL){
        printf("%d\n", curr->data);
        count++;
        curr = curr->next;
    }
    printf("linkedlistStack Size = %d\n", count);
} 
//https://dangerlover9403.pixnet.net/blog/post/108756341-%5B%E6%95%99%E5%AD%B8%5D-linked-list---linked-list-sort
//https://hackmd.io/@jx-9TgcOR064N3oN7__dvg/BklGm1MhZ?type=view#%E4%BD%BF%E7%94%A8%E6%BC%94%E7%AE%97%E6%B3%95

void main(){
    // int a[] = {1, 3, 2, 7, 4, 5, 1, 5, 7, 3, 8, 4};
    // // printf("length = %d\n", sizeof(a)/sizeof(int));
    // int length = sizeof(a)/sizeof(int);
    // for(int i = 0; i < length-1; i++){
    //     for(int j = 0; j < length-i-1; j++){
    //         if(a[j] > a[j+1]){
    //             int temp = a[j+1];
    //             a[j+1] = a[j];
    //             a[j] = temp;
    //         }
    //     }
    // }

    // for(int k = 0; k < length; k++){
    //     printf("a[%d] = %d\n", k, a[k]);
    // }
    linkedlist *test;
    test = NewLinkedlist();
    // printf("%d\n", IsEmpty(test));
    NewLinkedListTableNode(test, 10);
    NewLinkedListTableNode(test, 2);
    NewLinkedListTableNode(test, 33);
    // PrintLinledListTable(test);
    // printf("%d\n", Peek(test));
    // printf("%d\n", DeStack(test));
    // printf("%d\n", Peek(test));
    // printf("%d\n", IsEmpty(test));
    BubbleSort(test);
    PrintLinledListTable(test);
    // PrintStack(test);
    // system("pause");
}


