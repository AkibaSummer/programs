#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    s=s+'1';
    long long num=0;
    for (int i=0;i<n;i++){
        if (s[i+1]-s[i]==1)num++;
    }
    if (!num)cout<<0<<endl;
    else if (y<=x)cout<<y*num<<endl;
    else cout<<y+(num-1)*x<<endl;
}
