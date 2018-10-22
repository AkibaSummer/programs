#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode{
    int val,index;
    struct ListNode *next;
}ListNode;

void insertNode(int pos,int val,int index,ListNode *root){
    if (pos<0) return ;
    if (pos==0){
        ListNode *temp=(ListNode*)malloc(sizeof(ListNode));
        temp->val=root->val;
        temp->index=root->index;
        temp->next=root->next;
        root->next=temp;
        root->val=val;
        root->index=index;
        return ;
    }
    if (root->next==NULL){
        root->next=(ListNode*)malloc(sizeof(ListNode));
        root->next->val=0;
        root->next->index=0;
        root->next->next=NULL;
    }
    insertNode(pos-1,val,index,root->next);
    return ;
}

int getNodeVal(int pos,ListNode *root){
    if (root==NULL)return -1;
    else if (pos<0)return -1;
    else if (pos==0)return root->val;
    else return getNodeVal(pos-1,root->next);
}
int getNodeIndex(int pos,ListNode *root){
    if (root==NULL)return -1;
    else if (pos<0)return -1;
    else if (pos==0)return root->index;
    else return getNodeIndex(pos-1,root->next);
}

void deleteNode(int pos,ListNode *root){
    if (root==NULL)return ;
    else if (pos==0){
        root->val=root->next->val;
        root->index=root->next->index;
        ListNode *temp=root->next->next;
        free(root->next);
        root->next=temp;
    }
    else deleteNode(pos-1,root->next);
}


ListNode *addTwoPoly(ListNode *poly1,ListNode *poly2){
	ListNode *ret=(ListNode*)malloc(sizeof(ListNode));
    ret->val=0;
    ret->index=0;
    ret->next=NULL;
    int size=0;
    while(!(poly1==NULL&&poly2==NULL)){
        if (poly1==NULL){
            insertNode(++size,poly2->val,poly2->index,ret);
            poly2=poly2->next;
        }
        else if (poly2==NULL){
            insertNode(++size,poly1->val,poly1->index,ret);
            poly1=poly1->next;
        }
        else if (poly1->index<poly2->index){
            insertNode(++size,poly1->val,poly1->index,ret);
            poly1=poly1->next;
        }
        else if (poly1->index>poly2->index){
            insertNode(++size,poly2->val,poly2->index,ret);
            poly2=poly2->next;
        }
        else if (poly1->index==poly2->index){
            insertNode(++size,poly1->val+poly2->val,poly1->index,ret);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    for (ListNode *now=ret;now!=NULL;now=now->next){
        while ((now!=NULL)&&(now->next!=NULL)&&(now->val==0)){
            deleteNode(0,now);
        }
    }
    return ret;
}

ListNode *multTwoPoly(ListNode *poly1,ListNode *poly2){
    if (poly2==NULL)return NULL;
	ListNode *ret=(ListNode*)malloc(sizeof(ListNode));
    ret->val=0;
    ret->index=0;
    ret->next=NULL;
    int size=0;
    for (ListNode *temp=poly1;temp!=NULL;temp=temp->next){
        insertNode(++size,temp->val*poly2->val,temp->index+poly2->index,ret);
    }    
    return addTwoPoly(multTwoPoly(poly1,poly2->next),ret);
}

int main(){
    ListNode *root=(ListNode*)malloc(sizeof(ListNode));
    root->val=0;
    root->index=0;
    root->next=NULL;
    insertNode(0,1,1,root);
    insertNode(1,2,2,root);
    insertNode(2,3,3,root);
    
    ListNode *root1=(ListNode*)malloc(sizeof(ListNode));
    root1->val=0;
    root1->index=0;
    root1->next=NULL;
    insertNode(0,1,1,root1);
    insertNode(1,-2,2,root1);
    insertNode(2,3,3,root1);
    printf("root:%d %d %d\n",getNodeVal(0,root),getNodeVal(1,root),getNodeVal(2,root));
    printf("root1:%d %d %d\n",getNodeVal(0,root1),getNodeVal(1,root1),getNodeVal(2,root1));
    
    ListNode *added=addTwoPoly(root,root1);
    printf("root+root1:%d %d\n",getNodeVal(0,added),getNodeVal(1,added));
    
	ListNode *multed=multTwoPoly(root,root);
    printf("root*root:\n");
    printf("%d %d\n",getNodeVal(0,multed),getNodeIndex(0,multed));
    printf("%d %d\n",getNodeVal(1,multed),getNodeIndex(1,multed));
    printf("%d %d\n",getNodeVal(2,multed),getNodeIndex(2,multed));
    printf("%d %d\n",getNodeVal(3,multed),getNodeIndex(3,multed));
    printf("%d %d\n",getNodeVal(4,multed),getNodeIndex(4,multed));
    
	multed=multTwoPoly(root,root1);
    printf("root*root1:\n");
    printf("%d %d\n",getNodeVal(0,multed),getNodeIndex(0,multed));
    printf("%d %d\n",getNodeVal(1,multed),getNodeIndex(1,multed));
    printf("%d %d\n",getNodeVal(2,multed),getNodeIndex(2,multed));
}	