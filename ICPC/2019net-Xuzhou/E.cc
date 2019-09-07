#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)


int main(){
  fast;
  int n,m;
  cin>>n>>m;
  vector<int> input(n);
  vector<pair<int,int>> loc(n);
  vector<int> nxtpos(n);
  for (int i=0;i<n;i++){
    cin>>input[i];
    loc[i]={input[i],i};
  }
  sort(loc.begin(),loc.end());
  stack<pair<int,int>> que;
  for (auto&i:loc)que.push(i);
  // cout<<que.top().first<<' '<<m<<endl;
  int maxx=-1;
  for (int i=n-1;i>=0;i--){
    // cout<<que.top().first<<endl;
    while(que.size()&&que.top().first>=loc[i].first+m){
      maxx=max(que.top().second,maxx);
      que.pop();
    }
    if (maxx<loc[i].second){
      nxtpos[loc[i].second]=-1;
    }
    else {
      nxtpos[loc[i].second]=maxx-loc[i].second-1;
    }
    // cout<<maxx<<' '<<loc[i].second<<endl;;
  }
  for (int i=0;i<n;i++){
    cout<<nxtpos[i]<<" \n"[i==n-1];
  }

}