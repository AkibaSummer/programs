#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType; //数据类型
typedef int bool;
const bool true=1;
const bool false=0;


typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree; 

/*
插入节点
*/
void insertNode(ElemType i,BiTree *root){
    if (*root==NULL) {
        *root=(BiTree)malloc(sizeof(BiTNode));
        (*root)->data=i;
        (*root)->lchild=(*root)->rchild=NULL;
    }
    else if((*root)->data>i){
        insertNode(i,&(*root)->lchild);
    }
    else insertNode(i,&(*root)->rchild);
}

/*
建树
*/
void buildBiTree(ElemType input[],int length,BiTree *root){
    for (int i=0;i<length;i++){
        insertNode(input[i],root);
    }
}

/*
查找节点	未找到返回-1，找到返回深度
*/
int findNode(ElemType data,BiTree root){
    int temp;
    if (root==NULL)return -1;
    else if (root->data==data)return 1;
    else if (root->data>data)return (temp=findNode(data,root->lchild))==-1?-1:temp+1;
    else return (temp=findNode(data,root->rchild))==-1?-1:temp+1;    
}

/*
中序遍历
*/
void printInorder(BiTree root){
	if (root==NULL) return;
    printInorder(root->lchild);
    printf("%d ",root->data);
    printInorder(root->rchild);
}

/*
格式化打印
*/
void printStructure(BiTree root,int depth){
    if (root==NULL)return;
    printStructure(root->rchild,depth+1);
    for (int i=1;i<=depth;i++) printf("   ");
    printf("%d\n",root->data);    
    printStructure(root->lchild,depth+1);
}

/*
删除节点
*/
bool deleteNode(BiTree *root,ElemType x){
    if((*root)==NULL){
        return false;
    }
    if((*root)->data>x){
        return deleteNode(&(*root)->lchild,x);
    }else if((*root)->data<x){
        return deleteNode(&(*root)->rchild,x);
    }else{
        if((*root)->lchild == NULL){ 
            BiTree tempNode = *root;
            *root = (*root)->rchild;
            free(tempNode);
            return true;
        }else if((*root)->rchild == NULL){ 
            BiTree tempNode = *root;
            *root = (*root)->lchild;
            free(tempNode);
            return true;
        }else{ 
            BiTree tempNode = (*root)->lchild;
            if(tempNode->rchild!=NULL){
                tempNode = tempNode->rchild;
            }
            (*root)->data = tempNode->data;
            return deleteNode(&(*root)->lchild,tempNode->data);
        }
    }
}
void cls(){
    #ifdef linux
        system("clear");
    #endif
    #ifdef __WINDOWS_ 
        system("cls");
    #endif    
}

int main(){
    puts("开始建树");
    int n;
    printf("请输入数据数量：");
    scanf("%d",&n);
    ElemType *input=(ElemType*)malloc(sizeof(ElemType)*n);
    puts("请依次输入数据，以空格隔开：");
    for (int i=0;i<n;i++){
        scanf("%d",input+i);
    }
    BiTree root=NULL;
    buildBiTree(input,n,&root);
    for (;;){
        puts("请输入操作：");
        puts("1、插入节点");
        puts("2、打印中序遍历");
        puts("3、格式化打印");
        puts("4、查找节点");
        puts("5、删除节点");
        puts("6、退出程序");
        int temp;
        scanf("%d",&temp);
        if (temp==1){
            cls();
            ElemType input;
            printf("请输入要插入的节点：");
            scanf("%d",&input);
            insertNode(input,&root);
            puts("插入成功");
            puts("");
        }
        else if (temp==2){
            cls();
            puts("中序遍历如下：");
            printInorder(root);
            puts("");
        }
        else if (temp==3){            
            cls();
            puts("格式化打印如下：");
            printStructure(root,0);
            puts("");
        }
        else if (temp==4){            
            cls();
            ElemType input;
            printf("请输入要查找的节点：");
            scanf("%d",&input);
            int temp=findNode(input,root);
            if(temp==-1){
                puts("未找到输入的节点");
            }
            else {
                printf("输入节点的深度为：%d\n",temp);
            }
            puts("");
        }
        else if (temp==5){            
            cls();
            ElemType input;
            printf("请输入要删除的节点：");
            scanf("%d",&input);
            int temp=deleteNode(&root,input);
            if(temp){
                puts("已成功删除节点");
            }
            else {
                puts("未找到要删除的节点");
            }
            puts("");            
        }
        else if (temp==6){
            return 0;
        }
    }
}