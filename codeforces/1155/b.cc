#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k=n-11;
    int num=0;
    for (int i=0;i<=k;i++){
        if (s[i]=='8'){
            num++;
        }
    }
    if (num>k/2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}