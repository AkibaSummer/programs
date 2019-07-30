#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void slove(){
    int n;
    cin>>n;
    vector<int> input(n);
    for (auto &i:input)cin>>i;
    sort(input.begin(),input.end());
    cout<<min((min(input[n-1],input[n-2])-1),n-2)<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}