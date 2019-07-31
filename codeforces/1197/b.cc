#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for (auto &i:input)cin>>i;
    int flag=0;
    for (int i=1;i<n;i++){
        if (flag&&input[i]>input[i-1]){
            cout<<"NO"<<endl;
            return 0;
        }
        if (!flag&&input[i]<input[i-1]){
            flag=1;
        }
    }
    cout<<"YES"<<endl;
    
}