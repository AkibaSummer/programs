#include <bits/stdc++.h>
using namespace std;

struct query{
    int type;
    int q,w;
};

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for (auto &i:input) cin>>i;
    int q;
    cin>>q;
    vector<query> querys(q);
    for (auto &i:querys){
        cin>>i.type;
        if (i.type==1) cin>>i.q>>i.w;
        else cin>>i.q;
    }
    int maxx=-1;
    vector<int> ans(n,-1);
    for (int i=q-1;i>=0;i--){
        if (querys[i].type==1){
            if (ans[querys[i].q-1]==-1){
                if (querys[i].w>maxx){
                    ans[querys[i].q-1]=querys[i].w;
                }
                else {
                    ans[querys[i].q-1]=maxx;
                }
            }
        }
        else {
            maxx=max(maxx,querys[i].q);
        }
    }
    for (int i=0;i<n;i++){
        if (ans[i]==-1){
            ans[i]=max(input[i],maxx);
        }
    }
    for (auto i:ans){
        cout<<i<<' ';
    }
    // cout<<endl<<maxx<<endl;
}