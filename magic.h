#ifndef __MAGIC_H__
#define __MAGIC_H__

#define SIZE 10

typedef struct coordinate{
    int x;
    int y;
}coo_t;

typedef struct stack{
    coo_t elements[SIZE*SIZE];
    int top;
}stack_t;

void push(stack_t *s, coo_t element);
coo_t pop(stack_t *s);

#endif