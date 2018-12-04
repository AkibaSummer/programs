#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for (auto&i:input)cin>>i;
    sort(input.begin(),input.end());
    int pos=0;
    int num=0;
    for (int i=1;i<=k;i++){
        while (pos<n&&input[pos]-num==0){
            pos++;
        }
        if (pos==n){
            puts("0");
        	continue;
        }
            cout<<input[pos]-num;
            puts("");
            num=input[pos];
    }
}