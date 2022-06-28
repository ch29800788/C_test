#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct MyHashMap{
    int key;
    int value;
    struct MyHashMap *next;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *head = malloc(sizeof(MyHashMap));
    if(!head)   return head;
    head->key = 0;
    head->value = 0;
    head->next = NULL;
    return head;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    MyHashMap *new = malloc(sizeof(MyHashMap));
    if(obj->next == NULL && obj->key == 0 && obj->value == 0){
        obj->key = key;
        obj->value = value;
        obj->next = NULL;
    }
    else if(obj->next == NULL){
        new->key = key;
        new->value = value;
        new->next = NULL;
        obj->next = new;
    }
    else{
        MyHashMap *ptr = obj;
        while(ptr->next != NULL){
            ptr = ptr->next;
            if(ptr->key == key){
                ptr->value = value;
                return;
            }
        }
        if(ptr->key == key){
            ptr->value = value;
            return;
        }        
        else{
            new->key = key;
            new->value = value;
            new->next = NULL;
        }
        ptr->next = new;
    }
}

int myHashMapGet(MyHashMap* obj, int key) {
    assert(obj);
    while(obj != NULL){
        if(obj->key == key) return obj->value;
        obj = obj->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    assert(obj);
    MyHashMap *curr = obj;
    while(curr != NULL){
        if(curr->next == NULL && curr->key == key){
            printf("debug\n");
            free(curr);
        }
        else if(curr->key == key){
            MyHashMap *temp = curr;
            curr->next = curr->next->next;
            free(temp);
            return;
        }
        curr = curr->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    assert(obj);
    while(obj != NULL){
        MyHashMap *temp = obj;
        obj = obj->next;
        free(temp);
    }
}

void Print(MyHashMap *obj){
    assert(obj);
    while(obj != NULL){
        printf("%d %d\n", obj->key, obj->value);
        obj = obj->next;
    }
}

void main(){
    MyHashMap* obj = myHashMapCreate();
    // myHashMapPut(obj, 1, 1);
    // Print(obj);
    myHashMapPut(obj, 2, 2);
    // Print(obj);
    // int param_1 = myHashMapGet(obj, 1);
    // printf("param1=%d\n", param_1);
    // int param_2 = myHashMapGet(obj, 3);
    // printf("param2=%d\n", param_2);
    // myHashMapPut(obj, 2, 1);
    // Print(obj);
    // int param_3 = myHashMapGet(obj, 2);
    // printf("param3=%d\n", param_3);
    myHashMapRemove(obj, 2);
    Print(obj);
    // int param_4 = myHashMapGet(obj, 2);
    // printf("param4=%d\n", param_4);
    myHashMapFree(obj);
    system("pause");
}
