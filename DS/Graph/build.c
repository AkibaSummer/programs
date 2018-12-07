#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int min(int a,int b){
    return a>b?b:a;
}

int max(int a,int b){
    return a>b?a:b;
}

typedef struct{		 	//邻接矩阵
	int **data;
    int size;
    int *Flags;
}Mutex;

Mutex newMutex(int n){	//新邻接矩阵
    Mutex ret;
    ret.Flags=(int*)malloc(n*sizeof(int));
    ret.data=(int**)malloc(n*sizeof(int*));
    for (int i=0;i<n;i++){
        ret.data[i]=(int*)malloc(n*sizeof(int));
        ret.Flags[i]=0;
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
    int *Flags;
}Table;

Table newTable(int n){	//新邻接表
    Table ret;
    ret.data=(Node**)malloc(n*sizeof(Node*));
    ret.Flags=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        ret.data[i]=NULL;
        ret.Flags[i]=0;
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

void clean(Table table){			//清空flag数组
    for (int i=0;i<table.size;i++){
        table.Flags[i]=0;
    }
}

void bfs(int k,Table table){		//广度优先搜索
    if (table.Flags[k]==1)return ;
    else {
        table.Flags[k]=1;
        int *queue=(int*)malloc(table.size*sizeof(int));
        int front=0,back=0;
        queue[back++]=k;
        while (front!=back){
			printf("%d ",queue[front]);
            Node *now=table.data[queue[front]];
            while (now!=NULL){
                if (table.Flags[now->linked]==0){
                	queue[back++]=now->linked;
                    table.Flags[now->linked]=1;
                }
                now=now->next;
            }
            front++;
        }
    }
}

void dfs(int k,Table table){		//深度优先搜索
    if (table.Flags[k]==1) return ;
    else {
        table.Flags[k]=1;
        printf("%d ",k);
        Node *now=table.data[k];
        while (now!=NULL){
            dfs(now->linked,table);
            now=now->next;
        }
    }
}

void topology(Table table){
    int *queue=(int*)malloc(table.size*sizeof(int));
    int *father=(int*)malloc(table.size*sizeof(int));
    int *vl=(int*)malloc(table.size*sizeof(int));
    int *vs=(int*)malloc(table.size*sizeof(int));
    int front=0,back=0;
    
    for (int i=0;i<table.size;i++){
        father[i]=0;
        vs[i]=0x3f3f3f3f;
        vl[i]=-vs[i];
    }
    
    for (int i=0;i<table.size;i++){
        Node *now=table.data[i];
        while (now!=NULL){
            ++father[now->linked];
            now=now->next;
        }
    }
    
    for (int i=0;i<table.size;i++)
        if (father[i]==0)queue[back++]=i;
    
    vl[0]=vs[0]=0;
    while (front!=back){
        Node *now=table.data[queue[front]];
        while (now!=NULL){
            --father[now->linked];
            vs[now->linked]=min(vs[queue[front]]+now->weight,vs[now->linked]);
            if (father[now->linked]==0){
                queue[back++]=now->linked;
            }
            now=now->next;
        }
        front++;
    }
    
    vl[table.size-1]=vs[table.size-1];
    for (int i=front-1;i--;i>=0){
        Node *now=table.data[queue[i]];
        while (now!=NULL){
            vl[queue[i]]=max(vl[now->linked]-now->weight,vl[queue[i]]);
            now=now->next;
        }
    }
    
    for (int i=0;i<front;i++){
        printf("%d ",queue[i]);
    }
    puts("");
    
    printf("     i vs[i] vl[i]\n");
    for (int i=0;i<table.size;i++){
        printf("%6d%6d%6d",i,vs[i],vl[i]);
        puts(vs[i]==vl[i]?" 关键路径经过的顶点":"");
    }
}

int main(){
    int n,m;
    printf("请输入点数：");
    scanf("%d",&n);
    printf("请输入边数：");
    scanf("%d",&m);
    
    
    puts("开始初始化图结构");
    Mutex mutex=newMutex(n);
    Table table=newTable(n);
    puts("初始化图结构完成");
    
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
    
    puts("开始dfs");
    for (int i=0;i<n;i++)
        dfs(i,table);
    puts("");
    puts("dfs完成");
    
    clean(table);
    
    puts("开始bfs");
    for (int i=0;i<n;i++)
        bfs(i,table);
    puts("");
    puts("bfs完成");
    
    puts("开始拓扑排序");
    topology(table);
    puts("拓扑排序完成");
}