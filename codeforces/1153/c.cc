#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n&1){
        cout<<":(";
        return 0;
    }
    string s;
    cin>>s;
    int a=0;
    for (auto i:s){
        if (i=='(')a++;
    }
    for (auto &i:s){
        if (i=='?'){
            if (a<n/2){
                i='(';
                a++;
            }
            else {
                i=')';
            }
        }
    }
    int orz=0;
    for (int i=0;i<n;i++){
        if (s[i]=='(')orz++;
        else orz--;
        if (orz<=0&&i!=n-1){
            cout<<":("<<endl;
            return 0;
        }
    }
    if (orz==0)
    cout<<s<<endl;
    else cout<<":(";
}