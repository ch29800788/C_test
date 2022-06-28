#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//宣告node型態
typedef struct node {
    int data;
    struct node *next;
}node_t;

//宣告stack型態
typedef struct stack {
    node_t *top;
}stack_t;

//建立一個stack, malloc() 呼叫實際上是有可能失敗的，故需撰寫錯誤處理相關的程式碼。這裡在 malloc() 呼叫失敗時，回傳空的指標。
stack_t *stack_new(){
    stack_t *s = malloc(sizeof(stack_t));
    if (!s)
        return s;
    s->top = NULL;
    return s;
}

//刪除一個stack, 1. 讓temp指向curr的記憶體(也等同top), 2. 讓curr指向下一個指標; 3. free(temp)==free(top); 4. 最後再把傳進來的stack free掉
void stack_delete(void *self){
    if (!self)  return;

    node_t *curr = ((stack_t *)self)->top;
    while (curr) {
        node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(self);
}

//檢查堆疊是否為空
bool stack_is_empty(const stack_t *self){
    assert(self);
    return !(self->top) ? true : false;
}

//檢視堆疊頂端的資料但不取出
int stack_peek(const stack_t *self){
    assert(!stack_is_empty(self));
    return self->top->data;
}

//將資料建立起node
static node_t * node_new(const int data){
    node_t *n = malloc(sizeof(node_t));
    if (!n) {
        return n;
    }

    n->data = data;
    n->next = NULL;

    return n;
}

//將資料推入堆疊
bool stack_push(stack_t *self, int data){
    node_t *n = node_new(data);
    if (!n) {
        return false;
    }

    n->next = self->top;
    self->top = n;
    
    return true;
}

//將資料從stack取出
int stack_pop(stack_t *self){
    assert(!stack_is_empty(self));
    node_t *temp = self->top;
    int popped = temp->data;
    self->top = temp->next;
    free(temp);
    return popped;
}

void main(){
    stack_t *S;
    S = stack_new();
    if(stack_is_empty(S) == true)   printf("stack is empty\n");
    printf("data = %d", stack_peek(S));
    stack_delete(S);
    system("pause");
}