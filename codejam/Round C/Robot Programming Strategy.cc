#include <bits/stdc++.h>
using namespace std;
string slove(){
    int n;
    cin>>n;
    vector<string> in(n);
    vector<bool> flag(n,true);
    for (int i=0;i<n;i++){
        cin>>in[i];
    }
    string ret;
    for (int pos=0;pos<500;pos++){
        int r=0,p=0,s=0;
        for (int i=0;i<n;i++){
            if (flag[i]){
                if (in[i][pos%in[i].length()]=='R') r++;
                if (in[i][pos%in[i].length()]=='S') s++;
                if (in[i][pos%in[i].length()]=='P') p++;
            }
        }
        char temp,tempp;
        if (r+s+p==0)return ret;
        if (r&&s&&p)return "IMPOSSIBLE";
        if (r){
            if (s+p==0) return ret+'P';
            else if (s) temp='R';
            else if (p) temp='P';
        }
        else if (s){
            if (r+p==0) return ret+'R';
            else if (r) temp='R';
            else if (p) temp='S';
        }
        else if (p){
            if (s+r==0) return ret+'S';
            else if (s) temp='S';
            else if (r) temp='P';
        }
        ret=ret+temp;
        if (temp=='S')tempp='P';
        else if (temp=='P')tempp='R';
        else if (temp=='R')tempp='S';
        for (int i=0;i<n;i++){
            if (flag[i]&&in[i][pos%in[i].length()]==tempp)flag[i]=0;
        }
    }
    return "IMPOSSIBLE";
}
int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": "<<slove()<<endl;
    }
}
/*
3
1
RS
3
R
P
S
7
R
PR
PPR
PPPR
PPPPR
PPPPPR
P
*/