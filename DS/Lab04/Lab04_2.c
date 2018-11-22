#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 110
char input[MAX_LENGTH];

typedef struct Node{
    char data;
    struct Node *l,*r;
}Node;

int buildTree(char *input,Node **root){
    if (input[0]==' ') {
        *root=NULL;
        return 1;
    }
    *root=(Node*)malloc(sizeof(Node));
    (*root)->data=input[0];
    int lnum=buildTree(input+1,&(*root)->l);
    int rnum=buildTree(input+1+lnum,&(*root)->r);
    return lnum+rnum+1;
}

void printPreorder(Node *root){
    Node *Stack[MAX_LENGTH];
    int top=0;
    Stack[top++]=root;
    while(top--){
        if (Stack[top]==NULL) continue;
        printf("%c",Stack[top]->data);
        Stack[top+1]=Stack[top]->l;
        Stack[top]=Stack[top]->r;
        top+=2;
    }
}

void printInorder(Node *root){
    Node *Stack[MAX_LENGTH];
    int top=0;
    while(root!=NULL||top){
        while(root!=NULL){
            Stack[top++]=root;
            root=root->l;
        }
        if (top){
            root=Stack[--top];
            printf("%c",root->data);
            root=root->r;
        }
    }
}

void printPostorder(Node *root){
    Node *Stackr[MAX_LENGTH];
    Node *Stackl[MAX_LENGTH];
    int topr=0,topl=0;
    while(root!=NULL||topl){
        while (root!=NULL){
            Stackr[topr++]=root;
            if (root->l!=NULL)
                Stackl[topl++]=root->l;
            root=root->r;
        }
        if (topl)
            root=Stackl[--topl];
    }
    for (int i=topr-1;i>=0;i--)
        printf("%c",Stackr[i]->data);
}

int main(){
    gets(input);
    Node* root;
    buildTree(input,&root);
    printf("先序遍历顺序：");
    printPreorder(root);
    printf("\n中序遍历顺序：");
    printInorder(root);
    printf("\n后序遍历顺序：");
    printPostorder(root);
    printf("\n");
}