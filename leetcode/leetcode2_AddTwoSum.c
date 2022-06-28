#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}node;

node *ArraytoNode(int *array, int size){
    node *current, *tail, *root;
    current = (node*)malloc(sizeof(node));
    root = current;
    
    for(int i = 0 ; i < size; i++){     //why can't use sizeof(array) in here???
        tail = (node*)malloc(sizeof(node));
        tail->val = array[i];
        current->next = tail;
        current = current->next;
    }
    tail->next = NULL;
    current = root->next;
    free(root);
    return current;
}

node *addTwoNumbers(node *l1, node *l2){
    if(!l1)     return l2;
    if(!l2)     return l1;
    node *root, *current, *Nnode;
    current = (node*)malloc(sizeof(node));
    root = current;
    int v1, v2, temp, carry = 0;
    while(l1||l2){
        v1 = l1? l1->val:0;
        v2 = l2? l2->val:0;
        temp = v1+v2+carry;
        if(temp > 9){
            temp %= 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        Nnode = (node*)malloc(sizeof(node));
        Nnode->val = temp;
        current->next = Nnode;
        current = current->next;
        if(l1)  l1 = l1->next;
        if(l2)  l2 = l2->next;
    } 
    if(carry == 1){
        Nnode = (node*)malloc(sizeof(node));
        Nnode -> val = 1;
        Nnode -> next = NULL;
        current->next = Nnode;
    }
    Nnode->next = NULL;
    current = root->next;
    free(root);
    return current;
}

void main(){
    int input11[3] = {2, 4, 3};
    int input12[3] = {5, 6, 4};    
    int input21[1] = {0};
    int input22[1] = {0};
    int input31[7] = {9, 9, 9, 9, 9, 9, 9};
    int input32[4] = {9, 9, 9, 9};
    int i = 0;
    node *answer1, *answer2, *answer3;

    answer1 = addTwoNumbers(ArraytoNode(input11, 3), ArraytoNode(input12, 3));
    answer2 = addTwoNumbers(ArraytoNode(input21, 1), ArraytoNode(input22, 1));
    answer3 = addTwoNumbers(ArraytoNode(input31, 7), ArraytoNode(input32, 4));

    while(answer1){
        printf("answer1 val = %d\n", answer1->val);
        answer1 = answer1->next;
    }
    printf("=========================================\n");
    while(answer2){
        printf("answer2 val = %d\n", answer2->val);
        answer2 = answer2->next;
    }
    printf("=========================================\n");
    while(answer3){
        printf("answer3 val = %d\n", answer3->val);
        answer3 = answer3->next;
    }
   
    system("pause");
}