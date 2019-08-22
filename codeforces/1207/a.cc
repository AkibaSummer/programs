#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void slove(){
    int b,p,f;
    cin>>b>>p>>f;
    int h,c;
    cin>>h>>c;
    b/=2;
    int ans=0;
    if (h>c){
        ans+=h*min(b,p);
        cerr<<ans<<endl;
        if (b>=p){
            b-=p;
            ans+=c*min(b,f);
        }
    }
    else {
        ans+=c*min(b,f);
        cerr<<ans<<endl;
        if (b>=f){
            b-=f;
            ans+=h*min(b,p);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}