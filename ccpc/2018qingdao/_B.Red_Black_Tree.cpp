#include <bits/stdc++.h>
using namespace std;
const int BufferSize=1<<16;
char buffer[BufferSize],*front_head,*front_tail;
inline char GET_CHAR(){
    if(front_head==front_tail){
        int l=fread(buffer,1,BufferSize,stdin);
        front_tail=(front_head=buffer)+l;
        if(front_head==front_tail)return EOF;
    }
    return *front_head++;
}
inline int READ(){
    int x=0,f=1;char c=GET_CHAR();
    for(;!isdigit(c);c=GET_CHAR()){
        if(c==EOF)return EOF;
        if(c=='-')f=-1;
    }
    for(;isdigit(c);c=GET_CHAR())x=(((x<<2)+x)<<1)+c-'0';
    return x*f;
}
const int N=100005,M=200005;
const int Headsize=N,Edgesize=M;
int head[Headsize+5],mal;
struct edge{
    int nx,to,w;
}e[Edgesize+5];
inline void addedge(int u,int v,int val){
    e[mal].to=v;e[mal].w=val;e[mal].nx=head[u];head[u]=mal++;
}
const int lgN=21;
int idx;
long long dis[N+5],dist[N+5];int fa[N+5][lgN],dfn[N+5],revdfn[N+5],dep[N+5];bool red[N+5],vis[N+5];
inline void init(){
    mal=1;idx=0;
    memset(head,0,sizeof(head));
    memset(fa,0,sizeof(fa));
    memset(red,0,sizeof(red));
    memset(vis,0,sizeof(vis));
}
void dfs(int u,int f){
    fa[u][0]=f;
    dfn[u]=++idx;revdfn[idx]=u;
    dep[u]=dep[f]+1;
    for(int i=1;(1<<i)<=dep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    if(red[u])dis[u]=0;
    for(int i=head[u];i;i=e[i].nx){
        int v=e[i].to;
        if(v!=f){
            dist[v]=dist[u]+e[i].w;
            dis[v]=dis[u]+e[i].w;
            dfs(v,u);
        }
    }
}
int LCA(int x, int y) {
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[x]-dep[y]>=(1<<i))
            x=fa[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(dep[x]>=(1<<i) && fa[x][i]!=fa[y][i])//要跳到最近公共祖先的孩子节点。如果fa[x][i]==fa[y][i]的话那么肯定就跳过了！
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];//最后把父亲节点返回即可
}
int im[200000],siz[200000];
bool used[200000];
int main(){
    int T,n,m,q,u,v,w,k,nk;long long res=0,tmpres;
    T=READ();
    while(T--){
        init();
        n=READ();m=READ();q=READ();
        for(int i=1;i<=m;i++){
            u=READ();
            red[u]=1;
        }
        for(int i=1;i<n;i++){
            u=READ();v=READ();w=READ();
            addedge(u,v,w);addedge(v,u,w);
        }
        dist[0]=0;dis[0]=0;//dis to red // dist to root
        dfs(1,0);
        while(q--){
            res=0;
            long long ans=1ll<<60;
            k=READ();
            priority_queue<int> que;
            for(int i=1;i<=k;i++){
                im[i]=READ();siz[im[i]]=1;
                res+=dis[im[i]];
                que.push(dfn[im[i]]);
                used[im[i]]=1;
            }
            int q1,q2,q3,q4(0);
            while(!que.empty()){
                q1=revdfn[que.top()];//读取
                que.pop();
                ans=min(ans,res-siz[q1]*dis[q1]);//更新答案
                if (que.empty()){
                    break;
                }
                q2=revdfn[que.top()];
                
                q3=LCA(q1,q2);
                if (dist[q1]-dist[q3]>dis[q1]) siz[q3]+=siz[q1];
                if (dist[q2]-dist[q3]>dis[q2]) siz[q3]+=siz[q2];
                
                siz[q1]=0;//删点;
                used[q1]=0;
                if (!used[q3]){
                    used[q3]=1;
                    que.push(dfn[q3]);
                }
            }
            printf("%lld\n",ans);
        }
    }
}