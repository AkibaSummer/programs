#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int slove(string a,string &b){
    int ret=0;
    for (int i=0;i<b.size();i++){
        if (a[i%3]!=b[i])ret++;
    }
    return ret;
}
int main(){
    int orz='R'+'G'+'B';
    int n;
    cin>>n;
    string input;
    cin>>input;
    input=input+'B';
    int ans=0;
    for (int i=1;i<n;i++){
        if (input[i]==input[i-1]){
            ans++;
            if (input[i]==input[i+1]){
                if (input[i]=='R')input[i]='B';
                else input[i]='R';
            }
            else {
                input[i]=orz-input[i-1]-input[i+1];
            }
        }
    }
    input[n]='\n';
    cout<<ans<<endl<<input;
}