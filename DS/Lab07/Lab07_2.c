#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define true 1
#define false 0
#define maxnum 100
typedef struct{
    char name[4];
    int score[maxnum];
    int sum;
}stu;
stu students[maxnum];
int stuindex[maxnum];

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

void SelectSort(int A[],int n){
    int i,j,min;
    for (i=0;i<n-1;i++){
        min=i;
        for (j=i+1;j<n;j++)
            if (students[A[j]].sum>students[A[min]].sum)min=j;
        if (min!=i)swap(A+i,A+min);
    }
}

int main(){
    int n,m;
    printf("请输入n，m：");
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        stuindex[i]=i;
        students[i].name[0]=rand()%26+'a';
        students[i].name[1]=rand()%26+'a';
        students[i].name[2]=rand()%26+'a';
        for (int j=1;j<=m;j++){
            students[i].score[j]=rand()%21+80;
            students[i].sum+=students[i].score[j];
        }
    }
    SelectSort(stuindex+1,n);
    printf("%6s%6s%6s%6s","rank","id","name","sum");
    for (int i=1;i<=m;i++){
        printf("%6d",i);
    }
    puts("");
    for(int i=1;i<=n;i++){
        printf("%6d%6d%6s%6d",i,stuindex[i],students[stuindex[i]].name,students[stuindex[i]].sum);
       	for (int j=1;j<=m;j++){
            printf("%6d",students[stuindex[i]].score[j]);
        }
        puts("");
    }
}