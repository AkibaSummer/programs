#include <bits/stdc++.h>
using namespace std;
struct fact{
    int t,l,r;
};
bool cmp(const fact q,const fact w){
    if (q.t>w.t)return true;
    else if (q.l<w.l)return true;
    else if (q.r<q.r)return true;
    else return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<fact> facts(m);
    for (auto &i:facts){
        cin>>i.t>>i.l>>i.r;
    }
    sort(facts.begin(),facts.end(),cmp);

    for (auto i:facts){
        cout<<i.t<<' '<<i.l<<' '<<i.r<<endl;
    }
    // cout<<facts[0].t<<endl;
    vector<int> ans(n+1,1);
    int minr=0,minrr=0;
    for (int i=0;i<m;i++){
        if (facts[i].t){
            for (int j=max(minr,facts[i].l+1);j<=facts[i].r;j++){
                ans[j]=0;
            }
            minr=max(minr,facts[i].r+1);
        }
        else {
            int flag = 0;
            for (int j=max(minrr,facts[i].l+1);j<=facts[i].r;j++){
                if (ans[j]==1){
                    ans[j]=-1;
                }
                if (ans[j]==-1){
                    flag=1;
                }
            }
            if (!flag){
                cout<<"NO"<<endl;
                return 0;
            }
            minrr=max(minr,facts[i].r+1);
        }
    }
    ans[0]=2000;
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++){
        cout<<(ans[i]+=ans[i-1])<<' ';
    }
}