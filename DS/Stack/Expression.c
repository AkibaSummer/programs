#include <stdio.h>
#include <string.h>
#define EXPRESSION_SIZE 100
char infix[EXPRESSION_SIZE],postfix[EXPRESSION_SIZE];

void infixToPostfix(char* infix,char* postfix){
	int postfixPos=0,top=-1;
    char stack[EXPRESSION_SIZE];
    for (int i=0;infix[i]!=0;i++){
        if (infix[i]>='0'&&infix[i]<='9') postfix[postfixPos++]=infix[i];
        else {
           	if (top==-1)stack[++top]=infix[i];
            else {
                if (infix[i]=='*'||infix[i]=='/'){
                    while (stack[top]>=0&&(stack[top]=='*'||stack[top]=='/')){
                        postfix[postfixPos++]=stack[top--];
                    }
                    stack[++top]=infix[i];
                }
                else if (infix[i]=='+'||infix[i]=='-'){
                    while (stack[top]>=0&&(stack[top]=='*'||stack[top]=='/'||stack[top]=='+'||stack[top]=='-')){
                        postfix[postfixPos++]=stack[top--];
                    }
                    stack[++top]=infix[i];
                }
                else if (infix[i]=='('){
                    stack[++top]=infix[i];
                }
                else if (infix[i]==')'){
                    while (stack[top]>=0&&(stack[top]!='(')){
                        postfix[postfixPos++]=stack[top--];
                    }
                    top--;
                }
            }
        }
    }
    while (stack[top]>=0){
        postfix[postfixPos++]=stack[top--];
    }
    postfix[postfixPos]=0;
}

double postfixToAns(char* postfix){
    double stack[EXPRESSION_SIZE];
    int top=-1;
    for (int i=0;postfix[i]!=0;i++){
        if (postfix[i]>='0'&&postfix[i]<='9') stack[++top]=postfix[i]-'0';
        else if (postfix[i]=='+')stack[top]=stack[top]+stack[--top];
        else if (postfix[i]=='-')stack[top]=stack[top]-stack[--top];
        else if (postfix[i]=='*')stack[top]=stack[top]*stack[--top];
        else if (postfix[i]=='/')stack[top]=stack[top]/stack[--top];
    }
    return stack[0];
}

int main(){
    printf("请输入一个中缀表达式：");
	scanf("%s",infix);
	infixToPostfix(infix,postfix);
    printf("%s 转换成的后缀表达式为 %s\n",infix,postfix);
    printf("%s 计算出的结果为： %lf\n",postfix,postfixToAns(postfix));
}