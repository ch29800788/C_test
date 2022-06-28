#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct {
    node *head;
    node *tail;
} MyHashSet;

node *AddtoNode(int key){
    node *new = malloc(sizeof(node));
    new->data = key;
    new->next = NULL;
    return new;
}

MyHashSet* myHashSetCreate() {
    MyHashSet *set = malloc(sizeof(MyHashSet));
    set->head = NULL;
    set->tail = NULL;
    return set;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    node *ptr = obj->head;
    while(ptr != NULL){
        if(ptr->data == key)    return true;
        ptr = ptr->next;
    }
    return false;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if(myHashSetContains(obj, key) == true) return;
    node *add = AddtoNode(key);
    if(obj->head == NULL){
        obj->head = add;
        obj->tail = add;
    }
    else{
        obj->tail->next = add;
        obj->tail = obj->tail->next;
        printf("add_new\n");
    }
    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    node *curr = obj->head;
    node *prev = NULL;
    while(curr != NULL){
        if(curr->data == key){
            if(curr->next == NULL){
                prev->next = NULL;
                obj->tail = prev;
                free(curr);
                return;
            }
            else if(curr == obj->head){
                prev = obj->head;
                obj->head = obj->head->next;
                curr = obj->head;
                free(prev);
                return;
            }            
            else{
                prev->next = curr->next;
                free(curr);
                return;
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}

void myHashSetFree(MyHashSet* obj) {
    while(obj->head != NULL){
        node *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    free(obj);
}

void Print(MyHashSet *obj){
    node *ptr = obj->head;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void main(){
    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, 1);
    myHashSetAdd(obj, 2);
    Print(obj);
    bool param_1 = myHashSetContains(obj, 1);
    printf("bool %d\n", param_1);
    bool param_2 = myHashSetContains(obj, 3);
    printf("bool %d\n", param_2);
    myHashSetAdd(obj, 2);
    Print(obj);
    bool param_3 = myHashSetContains(obj, 2);
    printf("bool %d\n", param_3);
    myHashSetRemove(obj, 2);
    Print(obj);
    bool param_4 = myHashSetContains(obj, 2);
    printf("bool %d\n", param_4);
    myHashSetAdd(obj, 1000000);
    Print(obj);
    bool param_5 = myHashSetContains(obj, 1000000);
    printf("bool %d\n", param_5);
    
    myHashSetFree(obj);
    system("pause");
}
