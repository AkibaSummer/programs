#include <bits/stdc++.h>
using namespace std;
int x[20],y[20];

int g[4010][4010];
int &gg(int a,int b){
    return g[a+2005][b+2005];
}

int gcdd[2010][2010];
int gcd(int a,int b){
    if (!a||!b)return a+b;
    if (gcdd[a][b])return gcdd[a][b];
    return gcdd[a][b]=__gcd(a,b);
}

int vis[20];
int ans,n,fans;
void dfs(int now) {
    fans=max(ans,fans);
    if (now==n){
        return;
    }
    if (vis[now]) dfs(now+1);
    else
    for (int i=now+1;i<=n;i++){
        if (vis[i]==1)continue;
        vis[i]=1;
        int xx=x[now]-x[i],yy=y[now]-y[i];
        if (xx<0){
            xx=-xx;yy=-yy;
        }
        int gc=gcd(abs(xx),abs(yy));
        xx/=gc;yy/=gc;

        if ((!xx||!yy)&&xx+yy==-1){
            xx=-xx;yy=-yy;
        }

        ans+=gg(xx,yy);
        gg(xx,yy)++;

        dfs(now+1);

        gg(xx,yy)--;
        ans-=gg(xx,yy);
        vis[i]=0;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    dfs(1);
    printf("%d\n",fans);
}