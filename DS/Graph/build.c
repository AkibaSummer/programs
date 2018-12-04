#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct{		 	//邻接矩阵
	int **data;
    int size;
}Mutex;

Mutex newMutex(int n){	//新邻接矩阵
    Mutex ret;
    ret.data=(int**)malloc(n*sizeof(int*));
    for (int i=0;i<n;i++){
        ret.data[i]=(int*)malloc(n*sizeof(int));
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ret.data[i][j]=0;
        }
    }
    ret.size=n;
    return ret;
}

void insertMutexLink(Mutex mutex,int a,int b,int c){	//插入邻接矩阵链接
    mutex.data[a][b]=c;
}

void printfMutex(Mutex mutex){	//打印邻接矩阵
	for (int i=0;i<mutex.size;i++){
        for (int j=0;j<mutex.size;j++){
            printf("%d ",mutex.data[i][j]);
        }
        puts("");
    }
}

/**********************************/

typedef struct Node{	//邻接表节点
    int linked;
    int weight;
    struct Node *next;
}Node;

typedef struct{			//邻接表
    Node **data;
    int size;
}Table;

Table newTable(int n){	//新邻接表
    Table ret;
    ret.data=(Node**)malloc(n*sizeof(Node*));
    for (int i=0;i<n;i++){
        ret.data[i]=NULL;
    }
    ret.size=n;
    return ret;
}

void insertTableLink(Table table,int a,int b,int c){	//插入邻接表链接
    Node **now=&table.data[a];
    while (*now!=NULL){
        now=&((*now)->next);
    }
    *now=(Node*)malloc(sizeof(Node));
    (*now)->next=NULL;
    (*now)->linked=b;
    (*now)->weight=c;
}

void printfTable(Table table){		//打印邻接表
    for (int i=0;i<table.size;i++){
        printf("%d : ",i);
    	Node *now=table.data[i];
        while (now!=NULL){
            printf(now->next==NULL?"%d %d":"%d %d|",now->linked,now->weight);
            now=now->next;
        }
        puts("");
    }
}

int main(){
    int n,m;
    printf("请输入点数：");
    scanf("%d",&n);
    printf("请输入边数：");
    scanf("%d",&m);
    
    Mutex mutex=newMutex(n);
    Table table=newTable(n);
    
    printf("请依次输入连接的两点及其权值：\n");
    for (int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        insertMutexLink(mutex,a,b,c);
        insertTableLink(table,a,b,c);
    }
    
    printf("邻接矩阵为：\n");
    printfMutex(mutex);
    printf("邻接表为：\n");
    printfTable(table);
    
}