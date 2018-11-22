#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> input(n);
        for (auto &i:input)cin>>i;
        sort(input.begin(),input.end());
        if (n==3){
            cout<<max(input[2]-input[1],input[1]-input[0])-n+2<<endl;
        }
        else {
            cout<<max(input[n-1]-input[1],input[n-2]-input[0])-n+2<<endl;
        }
    }
}