#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct link{
    int h,l,r;
};

inline bool between(int h,int x,int y){
    return h>=x&&h<=y;
}

void slove(vector<link> &x,vector<link>&y){
    int x_s=x.size(),y_s=y.size();
    vector<bitset<5000>> bits(x_s);
    for (int i=0;i<x_s;i++){
        for (int j=0;j<y_s;j++){
            if (between(x[i].h,y[j].l,y[j].r)&&between(y[j].h,x[i].l,x[i].r)){
                bits[i].set(j);
                // cout<<x[i].h<<' '<<y[j].h<<endl;
            }
        }
    }
    long long ans=0;
    for (int i=0;i<x_s;i++){
        for (int j=i+1;j<x_s;j++){
            long long temp=(bits[i]&bits[j]).count();
            // if (temp>=2){
            //     cout<<temp<<' '<<i<<' '<<j<<endl;
            // }
            ans+=temp*(temp-1)/2;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n;
    vector<link> x;
    vector<link> y;
    cin>>n;
    for (int i=1;i<=n;i++){
        int q,w,e,r;
        cin>>q>>w>>e>>r;
        if (q==e){
            link l;
            l.h=q;
            l.l=min(w,r);
            l.r=max(w,r);
            x.push_back(l);
        }
        else {
            link l;
            l.h=w;
            l.l=min(q,e);
            l.r=max(q,e);
            y.push_back(l);
        }
    }
    if (x.size()<y.size()){
        slove(x,y);
    }
    else {
        slove(y,x);
    }
}