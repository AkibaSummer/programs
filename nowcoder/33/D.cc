#include <bits/stdc++.h>
using namespace std;
int bit[100005];
int a[100005],n;
#define lowbit(_x) ((_x)&-(_x))
void calc(int x){
    while(x<=n){
        bit[x]++;
        x+=lowbit(x);
    }
}
int sum(int x){
    int res=0;
    while(x>0){
        res+=bit[x];
        x-=lowbit(x);
    }
    return res;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res;
    for(int i=n;i>=1;i--){
        res+=sum(a[i]);
        calc(a[i]);
        res&=1;
    }
    int m;
    cin>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        res^=(c&1)&((b-a)&1);
        cout<<res<<endl;
    }
}