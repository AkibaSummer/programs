#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for (auto &i:input)cin>>i;
    sort(input.begin(),input.end());
    int a=input[n-1];
    for (int i=n-1;i>0;i--){
        if (a%input[i]!=0||input[i]==input[i-1]){
            cout<<input[n-1]<<' '<<input[i]<<endl;
            return 0;
        }
    }
}