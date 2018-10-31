#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char SElemType;
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

typedef int bool;
const int true = 1;
const int false = 0;

bool isMatch(char* s){
    LinkStack *stack;
    InitlinkStack(&stack);
    for (int i=0;s[i]!=0;i++){
        if (stack==NULL)Push(&stack,s[i]);
        else {
            if (stack->data=='['&&s[i]==']'||stack->data=='('&&s[i]==')')Pop(&stack);
            else if (s[i]==')'||s[i]==']'){
                while (stack)Pop(&stack);
                return false;                
            }
            else Push(&stack,s[i]);
        }
    }
    if (stack!=NULL){
        while (stack)Pop(&stack);
        return false;
    }
    else return true;
}

int main(){
    char input[1000];
    scanf("%s",input);
    printf(isMatch(input)?"匹配\n":"此串括号匹配不合法\n");
}