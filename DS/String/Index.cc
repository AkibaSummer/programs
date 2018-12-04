#include <stdio.h>

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];
int next[MAXSTRLEN+1];

void Input(SString S){
    scanf("%s",S+1);
    S[0]=0;
    while (S[++S[0]]);
    --S[0];
}

void Get_next(SString T,int next[]){
    int j,k;
    j=1;k=0;
    next[1]=0;
    while(j<=T[0]){
        if (k==0||T[j]==T[k]){
            ++j;++k;
            next[j]=k;
        }
        else k=next[k];
    }
}

int Index3(SString S,SString T,int pos){
    int i=pos,j=1;
    while (i<=S[0]&&j<=T[0]){
        if (j==0||S[i]==T[j]){
            ++i;++j;
        }
        else j=next[j];
    }
    if (j>T[0])return i-T[0];
    else return 0;
}

int Index1(SString S,SString T,int pos){
    for (int i=pos;i<=S[0]-T[0]+1;i++){
        for (int j=1;j<=T[0];j++){
            if (T[j]!=S[i+j-1])
                break;
            else if (j==T[0])
                return i;
        }
    }
    return 0;
}

int Index2(SString S,SString T,int pos){
    int i=pos,j=1;
    while (i<=S[0]-T[0]+j&&j<=T[0]){
        if (S[i]==T[j]){++i;++j;}
        else {i=i-j+2;j=1;}
    }
    if (j>T[0])return i-T[0];
    else return 0;
}

int main(){
    SString S,T;
    printf("请输入主串：");
    Input(S);
    printf("请输入模式串：");
    Input(T);
    printf("请输入主串开始查找的位置：");
    int pos;
    scanf("%d",&pos);
    puts("以下是模式匹配的暴力算法的结果：");
    (pos=Index1(S,T,pos))?printf("模式串在主串中的位置为：%d\n",pos):printf("主串中不包含模式串字串。\n");
    
    puts("以下是改进后的暴力算法的结果：");
    (pos=Index2(S,T,pos))?printf("模式串在主串中的位置为：%d\n",pos):printf("主串中不包含模式串字串。\n");
    
    Get_next(T,next);
    puts("以下是改进后的暴力算法的结果：");
    (pos=Index3(S,T,pos))?printf("模式串在主串中的位置为：%d\n",pos):printf("主串中不包含模式串字串。\n");
}