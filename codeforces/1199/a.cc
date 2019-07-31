#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> input(n);
    for (auto &i:input)cin>>i;
    for (int i=0;i<n;i++){
        int flag = 1;
        for (int j=max(0,i-x);j<=min(i+y,n-1);j++){
            if (j!=i){
                if (input[j]<=input[i])flag = 0;
            }
        }
        if (flag){cout<<i+1<<endl;return 0;}
    }
}