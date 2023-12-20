#include "magic.h"
#include <stdio.h>
#define SIZE 10
static int isFull(stack_t *s){
    if(s->top >= sizeof(s->elements))
        return 1;
    return 0;
}

static int isEmpty(stack_t *s){
    if(s->top == -1) 
        return 1;
    return 0;
}


void push(stack_t *s, coo_t element){  // element是欲填入口袋的座標
    if( !isFull(s) )
        printf("失敗\n");
    else{
        s->top++;
        s->elements[ s->top ] = element;
        return;
    }
    
}

//從口袋取一個元素
coo_t pop(stack_t *s){
    coo_t temp = {-1,-1};
    if( isEmpty(s) ) 
        return temp;
    return s->elements[ s->top-- ];   // 回傳elements[top]後將top減一
}


