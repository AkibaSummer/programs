#include <bits/stdc++.h>
using namespace std;
bool slove(int n,int k,vector<int>& input){
    if (k==input.size())return (n+180*100)%360==0;
    return slove(n+input[k],k+1,input)||slove(n-input[k],k+1,input);
}
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for (auto&i:input)cin>>i;
    if (slove(0,0,input)){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;        
    }
}