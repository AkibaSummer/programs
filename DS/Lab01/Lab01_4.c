#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int bool;
const int true=1;
const int false=0;

typedef struct{
    int code;
    bool isDeleted;
}node;

typedef struct{
    node *data;
    int length;
}SqList;
SqList root;

void input(node* now,int num){
    if (!num){
        puts("");
        return ;
    }
    scanf("%d",&(now->code));
    now->isDeleted=false;
    return input(now+1,num-1);
}

void output(node* now,int num,int n){
    if (!n)return ;
    else if (now->isDeleted) output((now+1-root.data)%root.length+root.data,num,n);
    else if (!num){
        printf("%d ",now-root.data+1);
        now->isDeleted=true;
        output((now+1-root.data)%root.length+root.data,now->code-1,n-1);
    }
    else output((now+1-root.data)%root.length+root.data,num-1,n);
}

int main(){
    int m;
    printf("请输入约瑟夫环人数（n）：");
    scanf("%d",&root.length);
    root.data=(node*)malloc(root.length*sizeof(node));
    printf("请输入每个人所持有的密码值（n个数以空格隔开）：");
	input(root.data,root.length);
    printf("请输入初始密码值：");
    scanf("%d",&m);
    output(root.data,m-1,root.length);    
}