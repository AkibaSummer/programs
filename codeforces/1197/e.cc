#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

struct nmd{
    int in,out;
    long long num=0;
};

map<int,int> mapp[1000005];
long long dp[1000005];
long long mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<nmd> input(n);
    map<int,int>order;
    for (auto &i:input){
        cin>>i.out>>i.in;
        order.insert({i.out,0});
        order.insert({i.in,0});
    }
    int now = 1;
    for (auto &i:order){
        i.second=now++;
    }
    int minn = 1e9+10,maxx=-1;
    for (auto &i:input){
        i.in=order[i.in];
        i.out=order[i.out];
        maxx=max(maxx,i.in);
        minn=min(minn,i.out);
        mapp[i.in][i.out]+=1;
    }

    cout<<endl;
    for (auto &i:input){
        cout<<i.in<<' '<<i.out<<endl;
    }
    
    for (int i=0;i<=1000001;i++){
        if (i<minn){
            if (mapp[i].size()){
                for (auto &j:mapp[i]){
                    dp[j.first]+=0ll+j.second; 
                    // cout<<i<<' '<<j.first<<' '<<j.second<<endl;                  
                }
            }
        }
        else if (!mapp[i].size()&&i<=maxx) {
            // dp[i+1]+=dp[i];
            dp[i]=0;
        }
        else if (mapp[i].size()){
            for (auto &j:mapp[i]){
                dp[j.first]+=1ll*dp[i]*j.second;
                dp[j.first]%=mod;
                // cout<<i<<' '<<j.first<<' '<<j.second<<endl;
            }
            // cout<<i<<"  "<<dp[i]<<endl;
            dp[i]=0;
        }
    }
    // cout<<dp[1000001]<<endl;
    long long ans=0;
    for (int i=0;i<=100001;i++){
        ans+=dp[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}