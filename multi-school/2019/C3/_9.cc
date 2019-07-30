#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// struct ret{
//     int maxnum;
//     int pos;
// };0
// void update(){

// }

// ret query(int l,int r,int ql,int qr,vector<int>&tree){
    
// }


int sgt[100060<<2],pos[100060],dp[2005],last[2005];

int mx, mxid;
void build(int p,int l,int r){
        sgt[p]=0;
    if(l==r) {
        return;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1,m+1,r);
}

void update(int p,int l,int r, int a, int x, int i) {
    if(l==r) {
        if(sgt[p]<x) {
            pos[l]=i;
            sgt[p]=x;
        }
        return;
    }
    int m=(l+r)>>1;
    if(a<=m) {
        update(p<<1,l,m,a,x,i);
    }else {
        update(p<<1|1,m+1,r,a,x,i);
    }
    sgt[p]=std::max(sgt[p<<1], sgt[p<<1|1]);
}
void query(int p, int l,int r, int a, int &ret) {
    if(l==r) {
        if(sgt[p]> mx) {
            ret =l;
            mx = sgt[p];
        }
        return;
    }
    int m=(l+r)>>1;
    if (a <= m) {
        query(p<<1,l,m,a ,ret);
        return;
    }
    if(sgt[p<<1] == sgt[p]) {
        query(p<<1,l,m,a,ret);
    } else {
        query(p<<1|1,m+1,r,a,ret);
    }
}

void slove1(vector<int> &input){
    // vector<int> tree(input.size()<<2);
    // vector<int> pos(input.size(),-1);
    // vector<int> last(1e5+5);
    if (input.empty())return ;
    int nn = input.size();
    build(1,1,100000);
    int ls;

    memset(pos,0,sizeof(pos));

    for (int i=1;i<=input.size();i++){

        dp[i]=0;
        mx=0,ls=0;
        query(1,1,100000,input[i-1],ls);
        dp[i] = mx + input[i-1];
        // up pos
        last[i]=pos[ls];
        update(1,1,100000,input[i-1],dp[i],i);
    }


    // for (int i=1;i<=input.size();i++){
    //     cout<<dp[i]<<' ';
    // }
    //     cout<<endl;
        
    // for (int i=1;i<=input.size();i++){
    //     cout<<last[i]<<' ';
    // }
    //     cout<<endl;

    // dp[n]
    int maxx=0,maxpos;
    for (int i=1;i<=nn;i++){
        if (dp[i]>maxx){
            maxx=dp[i];
            maxpos=i;
        }
    }
    // cout<<maxpos<<' '<<maxx<<endl;
    // return ;
    while(maxpos!=0){
        input[maxpos-1]=-1;
        maxpos=last[maxpos];
    }


    vector<int>ret;
    for (int i=0;i<input.size();i++){
        if (input[i]!=-1)ret.push_back(input[i]);
    }
    // for (auto i:ret)cout<<i<<' ';
    // cout<<endl;
    swap(ret,input);
}

void slove(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    int sum=0;
    for (auto &i:input){
        cin>>i;
        sum+=i;
    }
    while (k--){
        slove1(input);
        // for (auto i:input)cout<<i<<' ';
        // cout<<endl;
    }
    for (auto i:input)sum-=i;
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}
/*
1 12 2
5 6 7 8 4 5 6 7 3 4 5 6
 */