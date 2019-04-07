#include <bits/stdc++.h>
using namespace std;

void generate(int n,int l,char *a){
    int t=0,pos=0;
    while (pos!=n){
        if (pos/l%2) a[pos++]='0';
        else a[pos++]='1';
    }
    a[pos]=0;
}
string s[5];

void slove(string str,int ll,int l,int len,int now){
    if (str.length()==0){
        for (int i=0;i<len;i++){
            cout<<ll+i<<' ';
        }
    }
    else if (len==str.length()){
        return ;
    }
    else if (now==0){
        if (str[0]=='0')cout<<ll<<' ';
        else cout<<ll+1<<' ';
    }
    else if (str[str.length()-1]=='1'){
        int minn=min(1<<now,len);
        slove(s[now-1].substr(l,str.length()),ll,l,minn,now-1);
        slove("",ll+(1<<now),l+str.length(),len-minn,now-1);
    }
    else {
        for (int i=0;i<str.length();i++){
            if (str[i]=='0'){
                slove(s[now-1].substr(l,i),ll,l,1<<now,now-1);
                slove(s[now-1].substr(l+i,str.length()-i),ll+(1<<now),l+i,len-(1<<now),now-1);
                break;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,b,f;
        cin>>n>>b>>f;
        char a[1100];
        for (int k=4;k>=0;--k){
            generate(n,1<<k,a);
            cout<<a<<endl;
            fflush;
            cin>>s[k];
        }
        int pre=0;
        int t=0;
        int tot=0;
        for (int i=1;i<s[4].size();i++){
            if (s[4][i]!=s[4][i-1]){
                slove(s[3].substr(pre,i-pre),tot,pre,16,3);
                pre=i;
                tot+=16;
            }
        }
        slove (s[3].substr(pre),tot,pre,n-b-pre+(b-(tot-pre)),3);
        cout<<endl;
        fflush;
        cin>>n;
        if (n==-1)break;

    }
}
/*
3
10 2 10
11111111
11111110
11100001
10011001
01010101
1
5 2 10
111
111
110
101
011
1
32 8 10
111111111111000000000000
111100000000111111110000
000011110000111100001111
110011001100110011001100
101010101010101010101010

ans:
0 3
0 9
*/