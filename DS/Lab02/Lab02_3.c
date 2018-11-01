#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_CAR_NUM 100

typedef int bool;
const int true=1;
const int false=0;
typedef int Status;
const int OK = 0;
const int ERROR = -1;
const int OVERFLOW = -2;

typedef struct QElemType{
    int license;
    int arrivetime;
}QElemType;

QElemType newQElemType(int a,int b){
    QElemType ret={a,b};
    return ret;
}

typedef struct ParkingCar{
    int license;
    int arriveTime;
    int precost;
}ParkingCar;

ParkingCar newParkingCar(int a,int b,int c){
    ParkingCar temp={a,b,c};
    return temp;
}

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue{
    QueuePtr front;
   	QueuePtr rear;
    int num;
}LinkQueue;

ParkingCar parking[MAX_CAR_NUM];
int ltop,rtop,parkingnum;
LinkQueue sidewalk;

Status InitQueue(LinkQueue *Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)exit(OVERFLOW);
    Q->front->next=NULL;
    Q->num=0;
    return OK;
}

Status DestoryQueue(LinkQueue *Q){
    while (Q->front){
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if (!p)exit(OVERFLOW);
    p->data=e;p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    Q->num++;
    return OK;    
}

Status DeQueue(LinkQueue *Q,QElemType *e){
    if (Q->front==Q->rear)return ERROR;
    QueuePtr p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if (Q->rear==p)Q->rear=Q->front;
    free(p);
	Q->num--;
    return OK;
}

bool findCarInParking(int license){
    for (int i=0;i<=ltop;i++){
        if (license==parking[i].license)return true;
    }
    return false;
}

bool findCarInSideWalk(int license){
    for (int i=0;i<=ltop;i++){
        if (license==parking[i].license)return true;
    }
    return false;
}

void input(){
    printf("请输入停车场所可以停放的车的数量：");
    scanf("%d",&parkingnum);
    char type;
    int license,time;
    while (type!='E'){
        scanf("%c %d %d",&type,&license,&time);
        if (type=='A'){
            if (parkingnum==ltop+1) {
                EnQueue(&sidewalk,newQElemType(license,time));
                printf("编号为 %d 的车停在便道的第 %d 个位置\n",license,sidewalk.num);
            }
            else {
                parking[++ltop]=newParkingCar(license,time,0);
                printf("编号为 %d 的车停在便道的第 %d 个位置\n",license,ltop+1);                
            }
        }
        else if (type=='D'){
            
        }
    }
}
void init(){
    InitQueue(&sidewalk);
    ltop=-1;
    rtop=MAX_CAR_NUM;
}


int main(){
    input();
}