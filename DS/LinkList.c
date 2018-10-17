#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

void insertNode(int pos,int val,ListNode *root){
    if (pos<0) return ;
    if (pos==0){
        ListNode *temp=(ListNode*)malloc(sizeof(ListNode));
        temp->val=root->val;
        temp->next=root->next;
        root->next=temp;
        root->val=val;
        return ;
    }
    if (root->next==NULL){
        root->next=(ListNode*)malloc(sizeof(ListNode));
        root->next->val=0;
        root->next->next=NULL;
    }
    insertNode(pos-1,val,root->next);
    return ;
}

int getNode(int pos,ListNode *root){
    if (root==NULL)return -1;
    else if (pos<0)return -1;
    else if (pos==0)return root->val;
    else return getNode(pos-1,root->next);
}

void deleteNode(int pos,ListNode *root){
    if (root==NULL)return ;
    else if (pos==0){
        root->val=root->next->val;
        free(root->next);
        root->next=root->next->next;
    }
    else deleteNode(pos-1,root->next);
}

int main(){
    ListNode *root=(ListNode*)malloc(sizeof(ListNode));
    root->val=0;
    root->next=NULL;
    insertNode(0,1,root);
    insertNode(1,2,root);
    insertNode(3,3,root);
    deleteNode(2,root);
    printf("%d %d %d\n",getNode(0,root),getNode(1,root),getNode(2,root));
}