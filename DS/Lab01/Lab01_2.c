#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode{
    int val;
    int pos;
    struct ListNode *next;
}ListNode;
ListNode* root;

ListNode** input(ListNode **now,int num,int pos){
    if (num==0) {
        *now=root;
        return now;
    }
    else {
        *now=(ListNode*)malloc(sizeof(ListNode));
        scanf("%d",&((*now)->val));
        (*now)->pos=pos;
        return input(&((*now)->next),num-1,pos+1);
    }
}

void output(ListNode **now,int num,int n){
    if (num==0){
        printf("%d ",(*now)->pos);
        ListNode* deleted=*now;
        *now=(*now)->next;
        if (n>1) output(&(deleted->next),deleted->val-1,n-1),free(deleted);
        else puts("");
    }
    else output(&((*now)->next),num-1,n);
}

int main(){
    int n,m;
    printf("请输入约瑟夫环人数（n）：");
    scanf("%d",&n);
    printf("请输入每个人所持有的密码值（n个数以空格隔开）：");
	ListNode** pointToRoot=input(&root,n,1);
    printf("请输入初始密码值：");
    scanf("%d",&m);
    output(pointToRoot,m-1,n);    
}