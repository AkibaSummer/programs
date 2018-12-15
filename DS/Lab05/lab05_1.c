#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

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
    int *Father;
}Table;

Table newTable(int n){	//新邻接表
    Table ret;
    ret.data=(Node**)malloc(n*sizeof(Node*));
    ret.Flags=(int*)malloc(n*sizeof(int));
    ret.Father=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        ret.data[i]=NULL;
        ret.Flags[i]=0;
        ret.Father[i]=-1;
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

/**************************/

void clean(Table table){			//清空flag数组
    for (int i=0;i<table.size;i++){
        table.Flags[i]=0;
        table.Father[i]=-1;
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
                    table.Father[now->linked]=queue[front];
                }
                now=now->next;
            }
            front++;
        }
    }
}

int dfs(int k,Table table){		//深度优先搜索
    if (table.Flags[k]==1) return 1;
    else {
        table.Flags[k]=1;
        printf("%d ",k);
        Node *now=table.data[k];
        while (now!=NULL){
            if (dfs(now->linked,table)==0)
            	table.Father[now->linked]=k;
            now=now->next;
        }
        return 0;
    }
}

/******************************/

void dfs_unrecursion(int root,Table table){	//非递归深度优先搜索
    Node **stack=(Node**)malloc(table.size*sizeof(Node*));
    int *fatherstack=(int*)malloc(table.size*sizeof(int));
    int top=0;

    stack[top]=table.data[root];
    fatherstack[top++]=root;

    printf("%d ",root);	
    table.Flags[root]=1;

    while (top){
        --top;
        int father=fatherstack[top];
        Node* now=stack[top];
        if (now==NULL) continue;
        if (table.Flags[now->linked]==1){
            fatherstack[top]=father;
            stack[top++]=now->next;
        }
        else {
            table.Father[now->linked]=father;
            table.Flags[now->linked]=1;
            printf("%d ",now->linked);
            fatherstack[top]=father;
            stack[top++]=now->next;
            fatherstack[top]=now->linked;
            stack[top++]=table.data[now->linked];
        }
    }
}

/******************************/

int main(){
    int n,m,type;
    printf("请输入点数：");
    scanf("%d",&n);
    printf("请输入边数：");
    scanf("%d",&m);
    printf("请选择图的类型<有向图：1|无向图：2>：");
    scanf("%d",&type);
    puts("");
    
    Table table=newTable(n);
    
    printf("请依次输入连接的两点及其权值：\n");
    for (int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        insertTableLink(table,a,b,c);
        if (type==2) {
        	insertTableLink(table,b,a,c);
        }
    }
    puts("");

    printf("生成的邻接表为：\n");
    printfTable(table);
    puts("");

    printf("请输入遍历起始节点：");
    int root;
    scanf("%d",&root);
    puts("");

    puts("开始dfs");
    printf("遍历顺序为：");
    dfs(root,table);
    puts("");
    puts("生成树边集为:");
    for (int i=0;i<table.size;i++){
        if (table.Father[i]!=-1){
            printf("%d->%d\n",table.Father[i],i);
        }
    }
    puts("");

    clean(table);

    puts("开始bfs");
    printf("遍历顺序为：");
    bfs(root,table);
    puts("");
    puts("生成树边集为:");
    for (int i=0;i<table.size;i++){
        if (table.Father[i]!=-1){
            printf("%d->%d\n",table.Father[i],i);
        }
    }
    puts("");

    clean(table);

    puts("开始非递归dfs");
    printf("遍历顺序为：");
    dfs_unrecursion(root,table);
    puts("");
    puts("生成树边集为:");
    for (int i=0;i<table.size;i++){
        if (table.Father[i]!=-1){
            printf("%d->%d\n",table.Father[i],i);
        }
    }
}
/*
4
4
2
0 1 1
1 2 1
2 3 1
3 0 1
0 
*/