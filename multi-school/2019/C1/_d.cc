#include <bits/stdc++.h>

using namespace std ;

#define endl "\n"

const int maxn=100005;

int n;

double s[maxn];
double v[maxn];
double l[maxn];

void slove(){
    for (int i=0;i<=n;i++) scanf("%lf",l+i);
    for (int i=0;i<=n;i++) scanf("%lf",s+i);
    for (int i=0;i<=n;i++) scanf("%lf",v+i);
    // double ans = 0;
    int now=0,pos=0;
    while (1) {
        if ((s[i-1]+l[i-1])/v[i-1]<s[i]/v[i]){
            v[i-1]=v[i];
        }
    }
    // cout<<s[0]<< ' '<<v[0]<<endl;
    // cout<<fixed<<setprecision(10)<<s[0]/v[0]<<endl;   
    printf("%.10lf\n",s[0]/v[0]); 
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    while (scanf("%d",&n)!=EOF){
        slove();
    }
}
