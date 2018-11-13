#include <stdio.h>

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];

void Input(SString S){
    scanf("%s",S+1);
    S[0]=0;
    while (S[++S[0]]);
    --S[0];
}

int Index(SString S,SString T,int pos){
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
    (pos=Index(S,T,pos))?printf("模式串在主串中的位置为：%d\n",pos):printf("主串中不包含模式串字串。\n");
}