#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int bool;
const int true=1;
const int false=0;

typedef struct node{
    int code;
    bool isDeleted;
}

typedef struct SqList{
    int *data;
    int length;
};
SqList root;

void input(node* now,int num){
    if (!num)return ;
    scanf("%d",&(now->code));
    now->isDeleted=false;
    return input(now+1,num-1);
}

void output(node* now,int num,int n){
    if (!n)return ;
    else if (now->data.isDeleted) output((now+1-root.data)%root.length+root.data,num,n);
    else if (num==0){
        printf("%d ",now-root.data+1);
        SqList* deleted=*now;
        *now=(*now)->next;
        if (n>1) output(&(deleted->next),deleted->val-1,n-1),free(deleted);
        else puts("");
    }
    else output(&((*now)->next),num-1,n);
}

int main(){
    int m;
    printf("请输入约瑟夫环人数（n）：");
    scanf("%d",&root.length);
    root.data=(int*)malloc(n*sizeof(int));
    printf("请输入每个人所持有的密码值（n个数以空格隔开）：");
	input(root.data,n);
    printf("请输入初始密码值：");
    scanf("%d",&m);
    output(pointToRoot,m-1,n);    
}