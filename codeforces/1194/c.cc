#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool isInclude(string s,string t){
    int pos=0;
    for (auto i:t){
        if (i==s[pos])pos++;
        if (pos==s.length())return true;
    }
    if (pos==s.length())return true;
    else return false;
}

void slove(){
    string s,t,p;
    cin>>s>>t>>p;
    if (isInclude(s,t)){
        vector<int> sn(26);
        vector<int> tn(26);
        vector<int> pn(26);
        for (auto i:s){
            sn[i-'a']++;
        }
        for (auto i:t){
            tn[i-'a']++;
        }
        for (auto i:p){
            pn[i-'a']++;
        }
        for (int i=0;i<26;i++){
            if (tn[i]>sn[i]+pn[i]) {
                cout<<"NO"<<endl;
                return ;
            }
        }
        cout<<"YES"<<endl;
        return ;
    }
    else {
        cout<<"NO"<<endl;
        return ;
    }

}


int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}