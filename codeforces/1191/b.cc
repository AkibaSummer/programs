#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


bool orz[3][10]={0};
void addd(string a){
    if (a[1]=='s'){
        orz[0][a[0]-'0']=1;
    }
    if (a[1]=='m'){
        orz[1][a[0]-'0']=1;
    }
    if (a[1]=='p'){
        orz[2][a[0]-'0']=1;
    }
}


int main(){
    string a,b,c;
    cin>>a>>b>>c;
    if (a==b&&a==c){
        cout<<0<<endl;
        return 0;
    }
    else {
        addd(a);
        addd(b);
        addd(c);
    }
    int maxx=0;
    for (int i=0;i<3;i++){
        int now=orz[i][1]+orz[i][2]+orz[i][3];
        maxx=max(maxx,now);
        for (int j=4;j<=9;j++){
            now-=orz[i][j-3];
            now+=orz[i][j];
            maxx=max(maxx,now);
        }
    }
    if (maxx!=3){        
        if (a==b||a==c||b==c){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<3-maxx<<endl;
}