#include <bits/stdc++.h>
using namespace std;
void preKMP(char x[],int m,int kmpNext[]){
    // memset(kmpNext,0,sizeof(char)*m+10);
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j && x[i]!=x[j])j=kmpNext[j];
        if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
            else kmpNext[i]=j;
    }
}
int nextt[200010];
int dpr[200010];
int dpl[200010];
char t[200010],s[200010];
int KMP_Count(char x[],int m,char y[],int n){//x 是模式串，y 是主串
    int i,j;
    int ans=0;
    preKMP(x,m,nextt);
    i=j=0;
    while(i<n){
        while(-1!=j && y[i]!=x[j])j=nextt[j];
        i++;j++;
        if(j>=m){
            dpr[i]++;
            dpl[i-m+1]++;
            ans++;
            j=nextt[j];
        }
    }   
    return ans;
}
int main(){
    scanf("%s",t);
    int lent=strlen(t);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",s);
        int lens=strlen(s);
        KMP_Count(s,lens,t,lent);
    }
    long long ans = 0;
    for (int i=0;i<lent;i++){
        // cout<<dpl[i]<<' '<<dpr[i]<<endl;
        ans+=dpr[i]*dpl[i+1];
    }
    printf("%lld\n",ans);
}