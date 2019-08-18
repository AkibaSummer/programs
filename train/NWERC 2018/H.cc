#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c,b;
    cin>>n>>c>>b;
    vector<int> orz(n+1,-1);
    for (int i=1;i<=b;i++){
        int k;
        cin>>k;
        orz[k]=0;
    }
    if (c%2){orz[1]=1;c--;}
    else orz[1]=0;
    for (int i=2;i<=n;i++){
        if (c==0)orz[i]=0;
        else if (orz[i]==-1) {
            if (orz[i-1]==1)orz[i]=0;
            else {
                orz[i]=1;
                c-=2;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<orz[i];
    }
}