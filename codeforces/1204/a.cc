#include <bits/stdc++.h>
using namespace std;

void slove(){

}

int main(){
    string s;
    cin>>s;
    // reverse(s.begin(),s.end());
    // cout<<s<<endl;
    long long ans=0;
    for(int i=0;i<s.size();i++){
        if (s[i]=='1')ans++;
    }
    cout<<(s.size()+(ans>1))/2<<endl;
}