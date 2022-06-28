#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//宣告stack型態
typedef struct stack {
    size_t size;
    size_t capacity;
    size_t top;
    int *elements;
}stack_t;

//建立一個stack, malloc() 呼叫實際上是有可能失敗的，故需撰寫錯誤處理相關的程式碼。這裡在 malloc() 呼叫失敗時，回傳空的指標。
stack_t * stack_new(void)
{
    stack_t *s = malloc(sizeof(stack_t));
    if (!s)
        return s;

    s->size = 0;
    s->capacity = 2;
    s->top = 0;
    s->elements = malloc(s->capacity * sizeof(int));
    if (!(s->elements)) {
        s = NULL;
        return s;
    }

    return s;
}

//刪除一個stack, 1. 讓temp指向curr的記憶體(也等同top), 2. 讓curr指向下一個指標; 3. free(temp)==free(top); 4. 最後再把傳進來的stack free掉
void stack_delete(void *self)
{
    if (!self) {
        return;
    }

    int *elements = ((stack_t *) self)->elements;
    if (elements)
        free(elements);
    
    free(self);
}

//檢查堆疊是否為空
bool stack_is_empty(const stack_t *self)
{
    assert(self);
    return self->size == 0;
}

//檢視堆疊頂端的資料但不取出
int stack_peek(const stack_t *self)
{
    assert(!stack_is_empty(self));

    return self->elements[self->top];
}

//擴增element
static bool stack_expand(stack_t *self)
{
    if (self->size < self->capacity) {
        return true;
    }

    int *old_arr = self->elements;
    self->capacity = self->size * 2;
    int *new_arr = malloc(self->capacity * sizeof(int));
    if (!new_arr) {
        return false;
    }

    size_t sz = 0;
    int i = self->top;
    int j = self->top;
    while (sz < self->capacity) {
        new_arr[i] = old_arr[j];

        i = i == 0 ? self->capacity - 1 : i - 1;
        j = j == 0 ? self->size - 1 : j - 1;
        sz++;
    }

    self->elements = new_arr;
    free(old_arr);

    return true;
}

//將資料推入堆疊
bool stack_push(stack_t *self, int data)
{
    if (!stack_expand(self))
        return false;

    if(self->size == 0) self->top = 0;
    if(self->size > 0)
        self->top = (self->top + 1) % self->capacity;

    self->elements[self->top] = data;
    self->size++;

    return true;
}

//將資料從stack取出
int stack_pop(stack_t *self)
{
    assert(!stack_is_empty(self));

    int popped = self->elements[self->top];

    self->top = self->top == 0 ? self->capacity - 1 : self->top - 1;
    self->size--;

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