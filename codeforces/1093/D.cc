#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <long long> ee(300005);
    ee[0]=1;
    for (int i=1;i<=300005;i++){
        ee[i]=ee[i-1]<<1;
        ee[i]%=998244353;
    }
    int t;
    cin>>t;
    while (t--){
        int n;
        int m;
        cin>>n>>m;
        if(n==1){
            cout<<3<<endl;
            continue;
        }
        vector<vector<int>> link(n+1);
        for (int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        vector<int> ef(n+1);
        int flag = 0;
            long long ans = 1;
        for(int i=1;i<=n;i++){
            if (ef[i])continue;
            queue<int> que;
            que.push(i);
            ef[i]=1;
            int odd=0,even=0;
            odd=1;
            while (!que.empty()){
                int now=que.front();
                que.pop();
                for (auto i:link[now]){
                    if (ef[i]==0){
                        ef[i]=3-ef[now];
                        if (ef[i]==1)odd++;
                        else even++;
                        que.push(i);
                    }
                    else if (ef[i]+ef[now]!=3){
                        flag=1;
                        cout<<0<<endl;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            ans*=ee[odd]+ee[even];
            ans%=998244353;
        }
        if (flag)continue;
        cout<< (ans%998244353) <<endl;        
    }
}