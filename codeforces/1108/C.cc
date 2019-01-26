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
    int n;
    cin>>n;
    string input;
    cin>>input;
    const string a[]={"RGB","RBG","BRG","BGR","GRB","GBR"};
    int ans=0x7ffffff;
    int anss;
    for (int i=0;i<6;i++){
        int temp=slove(a[i],input);
        if (temp<ans){
            ans=temp;
            anss=i;
        }
    }
    cout<<ans<<endl;
    for (int i=0;i<input.size();i++){
        cout<<a[anss][i%3];
    }
}