#include<bits/stdc++.h>
using namespace std;
struct team{
    int p,t;
    char name[20];
    bool operator<(const team&a)const{
        if(p==a.p)return t<=a.t;
        return p>=a.p;
    }
}tt[100005];
int main()
{
    int T,i,j,k,n,d;
    char name[100];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&d);
        for(i=1;i<=n;i++){
            scanf("%s%d%d",tt[i].name,&tt[i].p,&tt[i].t);
        }
        sort(tt+1,tt+1+n);
        double pm=n*d*0.1;
        if(pm-(int)pm==0.5){
            int t1=(int)pm+1;
            //cout<<t1<<endl;
            printf("%s\n",tt[t1].name);
        }
        else puts("Quailty is very great");
    }

    return 0;
}