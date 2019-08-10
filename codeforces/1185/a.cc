#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long minn=min(a,min(b,c));
    long long maxx=max(a,max(b,c));
    long long midd=a+b+c-maxx-minn;
    long long ans=0;
    ans+=(midd-minn)>d?0:abs(midd-minn-d);
    ans+=(maxx-midd)>d?0:abs(maxx-midd-d);
    cout<<ans<<endl;
}