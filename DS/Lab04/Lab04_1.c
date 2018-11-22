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
	if (root==NULL) return;
    printf("%c",root->data);
    printPreorder(root->l);
    printPreorder(root->r);        
}

void printInorder(Node *root){
	if (root==NULL) return;
    printInorder(root->l);
    printf("%c",root->data);
    printInorder(root->r);
}

void printPostorder(Node *root){
	if (root==NULL) return;
    printPostorder(root->l);
    printPostorder(root->r);
    printf("%c",root->data);
}

void printStructure(Node *root,int depth){
    if (root==NULL)return;
    printStructure(root->r,depth+1);
    for (int i=1;i<=depth;i++) printf("  ");
    printf("%c\n",root->data);    
    printStructure(root->l,depth+1);
    
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
    printf("\n二叉树结构为：\n");
    printStructure(root,0);
}