#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
long long a[maxn],b[maxn],q[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        q[1]=0;
        long long minn=1ll<<60;
        for (int i=1;i<=n;i++){
            cin>>b[i];
            q[i+1]=q[i]+a[i]-b[i];
            minn=min(minn,q[i+1]);
        }
        q[1]=q[n+1];
        b[n+1]=b[1];
        //cout<<endl<<minn<<endl;;
        int ans(0);
        for(int i=2;i<=n+1;i++){
            //cout<<q[i]<<' ';
            if (b[i]+minn>=c){
                ans=i;
                break;
            }
        }
        cout<<(ans==n+1?1:(ans?ans:-1))<<endl;
    }
}