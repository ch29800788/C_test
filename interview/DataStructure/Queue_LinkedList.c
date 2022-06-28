#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define min(x, y)   x<y? x:y
#define pow(a)  (a)*(a)
//https://opensourcedoc.com/data-structures-in-c/queue-in-list/

//node
typedef struct listnode{
    int data;
    struct listnode *next;
    struct listnode *prev;
}listnode;

//queue
typedef struct QueueTable{
    listnode *head;
    listnode *tail;    
}QueueTable;

//1.建立queue
QueueTable *NewQueue(void){
    QueueTable *Q = malloc(sizeof(QueueTable));
    if(!Q)  return Q;
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

//2.刪除queue
void DeleteQueue(QueueTable *self){   
    if(!self)   return;
    listnode *curr = self->head;
    while(curr){
        listnode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(self);
}

//3.檢查queue是否空
bool IsEmpty(const QueueTable *self){
    assert(self);
    return !(self->head)? true: false;    
}

//4.檢查queue頭資料
int PeekHead(const QueueTable *self){
    assert(!IsEmpty(self));
    return self->head->data;
}

//5.建立新資料的node(給6.使用的)
listnode *NewNode(int data){
    listnode *node = malloc(sizeof(listnode));
    if(!node)   return node;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

//6.建立新資料的node以及推進queue
bool enqueue(QueueTable *self, int data){
    assert(self);
    listnode *node = NewNode(data);
    if(!node)   return false;
    if(self->head == NULL){
        self->head = node;
        self->tail = node;
        return true;
    }
    self->tail->next = node;
    node->prev = self->tail;
    self->tail = node;
    return true;
}

//7.把資料從queue拿出來
int dequeue(QueueTable *self){
    assert(!IsEmpty(self));
    int popped = self->head->data;
    if(self->head == self->tail){
        free(self->head);
        self->head = NULL;
        self->tail = NULL;
    }
    else{
        listnode *curr = self->head;
        self->head = self->head->next;
        free(curr);
    }
    return popped;
}

//8.反轉queue
void reverseQueue(QueueTable *self){
    if(self->head == self->tail)    return;
    listnode *prev = NULL, *curr = self->head, *next = self->head->next;
    while(next != NULL){
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    curr->prev = NULL;
    self->head = curr;
    return;
}

//9.印queue
void printQueue(QueueTable *self){
    assert(!IsEmpty(self));
    listnode *print = self->head;
    int count = 0;
    while(1){
        if(count != 0)  printf("previous node[%d]=%d\n", count-1, print->prev->data);
        printf("current node[%d]=%d\n", count, print->data);
        printf("next node[%d]=%d\n", count+1, print->next->data);
        printf("\n");
        count++;        
        print = print->next;
        if(print->next == NULL)   break;
    }
    return;
}

int main(void) {
    QueueTable *new = NewQueue();
    bool empty = IsEmpty(new);
    int a = 10;
    printf("empty? %d\n", empty);
    enqueue(new, 10);
    enqueue(new, 15);
    enqueue(new, 30);
    enqueue(new, 40);
    enqueue(new, 600);
    printQueue(new);
    printf("reverse!!!\n");
    reverseQueue(new);
    printQueue(new);
    // printf("min = %d\n", min(20, 10));
    // printf("pow = %d\n", pow(a+2));
    // printf("peek head = %d\n", PeekHead(new));
    // printf("pop %d\n", dequeue(new));
    // printf("pop %d\n", dequeue(new));
    // printf("pop %d\n", dequeue(new));
    system("pause");
    return 0;
}