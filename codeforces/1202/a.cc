#include <bits/stdc++.h>
using namespace std;
void slove(){
    string s1,s2;
    cin>>s1>>s2;
    int pos1,pos2;
    for (int i=0;i<s2.size();i++){
        if (s2[i]=='1'){
            pos2=i;
        }
    }
    pos2=s2.size()-pos2;
    for (int i=s1.size()-pos2;i>=0;i--){
        if (s1[i]=='1'){
            pos1=i;
            // cout<<pos2<<' '<<pos1<<endl;
            break;
        }
    }
    pos1=s1.size()-pos1;
    cout<<pos1-pos2<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}