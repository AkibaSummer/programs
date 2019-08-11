#include <bits/stdc++.h>
using namespace std;

long long getans(string &s,long long pos,char c){
    // cout<<s<<' '<<pos<<' '<<c<<endl;
    long long top=0,down=0,left=0,right=0,nowx=0,nowy=0;
    // long long flag = 1;
    for (long long i=0;i<s.size();i++){
        if (i==pos){
            // flag=0;
            if (c=='W'){
                nowy++;
                if (nowy>top){
                    top=nowy;
                }
            }
            if (c=='S'){
                nowy--;
                if (nowy<down){
                    down=nowy;
                }
            }
            if (c=='A'){
                nowx--;
                if (nowx<left){
                    left=nowx;
                }
            }
            if (c=='D'){
                nowx++;
                if (nowx>right){
                    right=nowx;
                }
            }
        }
        if (s[i]=='W'){
            nowy++;
            if (nowy>top){
                top=nowy;
            }
        }
        if (s[i]=='S'){
            nowy--;
            if (nowy<down){
                down=nowy;
            }
        }
        if (s[i]=='A'){
            nowx--;
            if (nowx<left){
                left=nowx;
            }
        }
        if (s[i]=='D'){
            nowx++;
            if (nowx>right){
                right=nowx;
            }
        }
    }
    return (top-down+1)*(right-left+1);    
}

void slove(){
    string s;
    cin>>s;
    long long top=0,down=0,left=0,right=0,nowx=0,nowy=0;
    long long topt=0,downt=0,leftt=0,rightt=0;
    for (long long i=0;i<s.size();i++){
        if (s[i]=='W'){
            nowy++;
            if (nowy>top){
                top=nowy;
                topt=i;
            }
        }
        if (s[i]=='S'){
            nowy--;
            if (nowy<down){
                down=nowy;
                downt=i;
            }
        }
        if (s[i]=='A'){
            nowx--;
            if (nowx<left){
                left=nowx;
                leftt=i;
            }
        }
        if (s[i]=='D'){
            nowx++;
            if (nowx>right){
                right=nowx;
                rightt=i;
            }
        }
    }
    long long ans=(top-down+1)*(right-left+1);
    if (top!=0)ans=min(ans,(getans(s,topt,'S')));
    if (down!=0)ans=min(ans,(getans(s,downt,'W')));
    if (left!=0)ans=min(ans,(getans(s,leftt,'D')));
    if (right!=0)ans=min(ans,(getans(s,rightt,'A')));
    cout<<ans<<endl;
}

signed main(){
    long long t;
    cin>>t;
    while(t--){
        slove();
    }
}