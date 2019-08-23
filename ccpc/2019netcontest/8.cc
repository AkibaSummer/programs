#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
void slove(){
    int n,m;
    cin>>n>>m;
    vector<int>t(n);
    int minn=0x3fffffff;
    for (auto &i:t){cin>>i;minn=min(minn,i);}
    sort(t.begin(),t.end());
    long long ans=0;
    int fishs=0;
    fishs=1;ans+=m;
    priority_queue<int> timea;
    priority_queue<int,vector<int>,greater<int>> timeb;
    for (int i=n-1;i>=0;i--){
        if (t[i]>=m){
            ans+=t[i];
            fishs+=t[i]/m;
            timeb.push(m-t[i]%m);
        }
        else if (fishs<n){
            fishs++;
            ans+=m;
            timea.push(m-t[i]);
        }
        else {
            ans+=t[i];
        }
    }
    while(timea.size()&&timeb.size()&&timeb.top()<timea.top()){
        ans+=timeb.top()-timea.top();
        timea.pop();
        timeb.pop();        
    }
    // ans+=m+t[0];s
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        slove();
    }
}