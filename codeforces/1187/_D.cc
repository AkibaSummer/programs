#include <bits/stdc++.h>
using namespace std;
#define endk "\n"
void slove(){
    int n;
    cin>>n;
    vector<int>source(n);
    vector<int>target(n);
    for (auto &i:source){
        cin>>i;
    }
    for (auto &i:target){
        cin>>i;
    }
    int r=0;
    priority_queue<int,vector<int>,greater<int> > que;
    for (int l=0;l<n;l++){
        while ((que.empty()||que.top()>target[l])&&r<n){
            que.push(source[r++]);
        }
        if (que.top()==target[l]){
            que.pop();
        }
        else if (que.top()<target[l]){
            cout<<"NO"<<endl;
            return ;
        }
    }
    if (que.empty())
        cout<<"YES"<<endl;
    else {
        cout<<"NO"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}