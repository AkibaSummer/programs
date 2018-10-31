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
}LinkStack;

void InitlinkStack(LinkStack **s){
    *s=NULL;
}

Status Push(LinkStack **s,SElemType e){
    LinkStack* p=(LinkStack*)malloc(sizeof(LinkStack));
    if (!p)return OVERFLOW;
    p->next=*s;
    p->data=e;
    *s=p;
    return SUCCESS;
}

Status Pop(LinkStack **s){
    if (*s==NULL)return ERROR;
    LinkStack *e=(*s)->next;
    free(*s);
    *s=e;
    return SUCCESS;
}

void DECtoOCT(long long input){
	LinkStack *stack;
    InitlinkStack(&stack);
    while (input){
        Push(&stack,input%8);
    	input/=8;
    }
    while (stack!=NULL){
        printf("%d",stack->data);
        Pop(&stack);
    }
}

int main(){
	long long input;
	scanf("%lld",&input);
    DECtoOCT(input);
    puts("");
}
