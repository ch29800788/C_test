#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//宣告queue for array型態
typedef struct queue_t{
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
    int *element;
}ArrayQueue;

//建立queue: 一個是佇列當下的大小 size，一個是佇列的最大容量 capacity。
ArrayQueue *queue_new(void){
    ArrayQueue *que = malloc(sizeof(ArrayQueue));
    if(!que)    return que;
    que->size = 0;
    que-> capacity = 2;
    que->head = 0;
    que->tail = 0;
    que->element = malloc(que->capacity*sizeof(int));
    if(!que->element)   return que;
    return que;
}

//刪除queue: 要先釋放佇列內部的陣列後，再釋放佇列物件本身。
void queue_delete(ArrayQueue *self){
    if(!self)   return;
    int *temp = self->element;
    if(temp)    free(self->element);
    free(self);    
}

//檢查queue是否為空: 直接檢查 size 屬性是否為零即可。
bool queue_is_empty(const ArrayQueue *self){
    assert(self);
    return self->size == 0;
}

//檢視queue頂端的資料但不取出: 用 head 取代指標，指向佇列的頭端所在的位置。
int queue_peek(const ArrayQueue *self){
    assert(!queue_is_empty(self));
    int temp = self->element[self->head];
    return temp;
}

//要擴展佇列時，會先建立一個新的陣列，再將原陣列的資料逐一拷貝到新陣列上
static bool queue_expand(ArrayQueue *self){
    if(self->size < self->capacity) return true;
    int *oldarr = self->element;
    self->capacity = self->size*2;
    int *newarr = malloc(sizeof(int)*self->capacity);
    if(!newarr) return false;

    size_t sz = 0;
    size_t oldindex = self->head;
    size_t newindex = self->head;
    while(sz < self->size){
        newarr[newindex] = oldarr[oldindex];
        newindex = (newindex+1) % self->capacity;
        oldindex = (oldindex+1) % self->size;
        sz++;
    }
    self->element = newarr;
    self->size = sz;
    self->tail = (self->head+sz-1)%self->capacity;
    free(oldarr);
    return true;
}

//將資料放入queue: 一開始要先視需求擴展容量。
bool queue_enqueue(ArrayQueue *self, int data){
    if(!queue_expand(self)) return false;
    if(self->size == 0){
        self->element[self->tail] = data;
        self->size += 1;
        return true;   
    }
    
    self->tail = (self->tail + 1) % (self->capacity);
    self->element[self->tail] = data;
    self->size += 1;
    
    return true;
}

//將資料移出queue: 要將資料移出佇列時，先移動 head
int queue_dequeue(ArrayQueue *self){
    assert(!queue_is_empty(self));
    int pop = self->element[self->head];
    self->head = (self->head +1)%self->capacity;
    self->size -=1;
    return pop;
}

void main(){
    ArrayQueue *test;
    bool empty;
    printf("size of test before= %d\n", sizeof(test));
    test = queue_new();                             //new queue, queue capacity == 2
    printf("size of test after= %d\n", sizeof(test));
    printf("queue capacity = %d\n", test->capacity);
    empty = queue_is_empty(test);           
    printf("1: emepty == %d\n", empty);                            //queue is empty
    queue_enqueue(test, 10);                        //queue[head] == 10
    printf("peek = %d\n", queue_peek(test));  
    queue_enqueue(test, 20);                        //queue[1] == 20
    queue_expand(test);                             //queue capacity == 4
    printf("queue capacity = %d\n", test->capacity);      
    queue_enqueue(test, 30);                        //queue[2] == 30
    queue_enqueue(test, 40);                        //queue[3] == 40
    queue_dequeue(test);                            //queue[head] == 20
    printf("peek = %d\n", queue_peek(test));
    queue_delete(test);                             //delete queue
    printf("size of test = %d\n", sizeof(test));
    system("pause");
}