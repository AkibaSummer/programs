#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
    string s;
    cin>>n;
    cin>>s;
    long long ans(0),l(0),r(0);
    for (int i=0;i<n;i++){
        if (s[i]==s[0])l++;
        else break;
    }
    for (int i=n-1;i>=0;i--){
        if (s[i]==s[n-1])r++;
        else break;
    }
    if (s[0]==s[n-1]){
        cout<<(l+1)*(r+1)%998244353 <<endl;
    }
    else cout<<l+r+1<<endl; 
}