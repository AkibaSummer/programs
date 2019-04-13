#include <bits/stdc++.h>
using namespace std;

struct node{
    int tot;
    int pos[26];
    void clear(){
        memset(pos,0,sizeof(pos));
        tot=0;
    }
};
node tree[50005];
int ed;

void insert(string & s,int pos,node &root){
    if (pos==-1)return;
    int id=s[pos]-'A';
    root.tot++;
    if (root.pos[id]){
        insert(s,pos-1,tree[root.pos[id]]);
    }
    else {
        root.pos[id]=++ed;
        tree[ed].clear();
        insert(s,pos-1,tree[root.pos[id]]);
    }
}

int ans;

int getans(node &root){
    if (root.tot<=1){
        return root.tot;
    }
    else if (root.tot==2){
        ans++;
        return 0;
    }
    else {
        int ret=0;
        for (int i=0;i<26;i++){
            ret+=getans(tree[root.pos[i]]);
        }
        if (ret>=2){
            ret-=2;
            ans++;
        }
        return ret;

    }
}

int slove(){
    int n;
    cin>>n;
    ed=0;
    for (int i=1;i<=n;i++){
        string in;
        cin>>in;
        insert(in,in.size(),tree[0]);
    }
    ans=0;
    getans(tree[0]);
    return ans*2;
}

int main(){
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        printf("Case #%d: %d\n",tt,slove());
    }
}