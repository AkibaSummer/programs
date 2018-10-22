#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int SElemType;
typedef int Status;
const unsigned int STACK_INIT_SIZE=1000;
const unsigned int STACK_INCREMENT=1000;
const int SUCCESS = 0;
const int ERROR = -1;
const int OVERFLOW = -2;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack *S){
    S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return SUCCESS;
}

Status Push(SqStack *S,SElemType e){
    if (S->top-S->base>=S->stacksize){
        S->base=(SElemType*)realloc(S->base,(S->stacksize+STACK_INCREMENT)*sizeof(SElemType));
        if (!S->base)exit(OVERFLOW);
        S->top=S->base+S->stacksize;
        S->stacksize+=STACK_INCREMENT;
    }
    *S->top++=e;
    return SUCCESS;
}

Status Pop(SqStack *S,SElemType *e){
    if (S->top==S->base)return ERROR;
    e=--S->top;
    return SUCCESS;
}

int main(){
}