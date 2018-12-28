#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* data[30]={
    "chenruilong",
    "chenjinqiao",
    "chenxiao",
    "chenyushi",
    "hecai",
    "liuyifan",
    "liyanjie",
    "chensheng",
    "songyunfei",
    "yangke",
    "jiayuqi",
    "zenghaoqi",
    "caibingdi",
    "caihelin",
    "fengtianyou",
    "jiangminlang",
    "jiangxuelian",
    "liguohang",
    "lishuo",
    "liuyueming",
    "liyingrui",
    "liuze",
	"lizongyang",
    "maxiang",
    "niemoyu",
    "qiance",
    "qiying",
    "songjiuxiao",
    "wuji",
    "shuting",        
};

int hash(char* str){
	if (*str==0)return 0;
    else return (hash(str+1)+*str)%30;
}

typedef struct Node{
    char* data;
   	struct Node* next;
}Node;

Node* hashtable[30]={NULL};

int insert(Node** root,char* data){
    if (*root==NULL){
		*root=(Node*)malloc(sizeof(Node));
        (*root)->next=NULL;
        (*root)->data=data;
        return 1;
    }
    else {
        return insert(&(*root)->next,data)+1;
    }
}

int find(char* data){
    int temp=hash(data);
    int ret=1;
    Node* now=hashtable[temp];
    while (now->data!=data){
        now=now->next;
        ret++;
    }
    return ret;
}

int main(){
    float avgLength=0;
    for (int i=0;i<30;i++){
        int temp=hash(data[i]);
        //printf("%d\n",temp);
        insert(&hashtable[temp],data[i]);
    }
    for (int i=0;i<30;i++){
        avgLength+=find(data[i]);
    }
    printf("平均查找长度为%.3f\n",avgLength/30);
}