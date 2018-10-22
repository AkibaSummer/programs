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

typedef struct LinkStack{
    SElemType data;
    struct LinkStack *next;
}Snode,LinkStack;

void InitlinkStack(LinkStack *s){
    s=NULL;
}

Status Push(LinkStack *s,SElemType e){
    LinkStack* p=(LinkStack*)malloc(sizeof(LinkStack));
    if (!p)return OVERFLOW;
    p->next=s;
    p->data=e;
    s=p;
    return SUCCESS;
}

Status Pop(LinkStack *s,LinkStack *e){
    if (s==NULL)return ERROR;
    e=s->next;
    free(s);
    return SUCCESS;
    
}

int main(){
}