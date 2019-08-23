#include <bits/stdc++.h>
using namespace std;
int flag[100005];
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> input(n);
    for (auto &i:input)cin>>i;
    vector<int> inputm(m);
    for (auto &i:inputm)cin>>i;
    for (int i=m-1;i>=0;i--){
        if (flag[inputm[i]]==0){
            cout<<inputm[i]<<' ';
            flag[inputm[i]]=1;
        }
    }
    for (auto &i:input){
        if (flag[i]==0){
            cout<<i<<' ';
            flag[i]=1;
        }
    }
}