#include <bits/stdc++.h>
using namespace std;

#define int long long


int gcd(int a,int b){
    if (b==0)return a;
    else return gcd(b,a%b);
}

signed main(){
    int n,m,q;
    cin>>n>>m>>q;
    int kuai=gcd(n,m);
    while(q--){
        int s1,s2,e1,e2;
        cin>>s1>>s2>>e1>>e2;
        s2--;e2--;
        int q,w;
        if (s1==1)q=s2/(n/kuai);
        else if (s1==2)q=s2/(m/kuai);
        if (e1==1)w=e2/(n/kuai);
        else if (e1==2)w=e2/(m/kuai);
        if (q==w)puts("YES");
        else puts("NO");
        // cout<<q<<' '<<w<<endl;
    }
}