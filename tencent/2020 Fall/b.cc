#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  node* next;
};
int main() {
  int n,m;
  cin>>n>>m;
  map<int,int> known;
  map<int,vector<int>> tuanDui;
  map<int,vector<int>> ren;
  for (int i=0;i<m;i++){
    int x;
    cin>>x;
    for (int j=0;j<x;j++){
      int tmp;
      cin>>tmp;
      tuanDui[i].push_back(tmp);
      ren[tmp].push_back(i);
    }
  }
  queue<int> que;
  que.push(0);
  known[0]=1;
  while(!que.empty()){
    int now = que.front();
    que.pop();
    for (auto i:ren[now]){
      for (auto j:tuanDui[i]){
        if (known[j]==0){
          known[j]=1;
          que.push(j);
          // cout<<j<<' ';
        }
      }
    }
  }
  int ans = 0;
  for (auto &i:known){
    // cout<<i<<' ';
    ans+=i.second;
  }
  cout<<ans<<endl;
}