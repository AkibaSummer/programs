#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100005;

int ans[maxn];
int input[maxn];
int isused[maxn];

int slove(){
    int n;
    scanf("%lld",&n);
    memset(ans,0,sizeof(int)*2*n+10);
    memset(input,0,sizeof(int)*2*n+10);
    memset(isused,0,sizeof(int)*2*n+10);
    for (int i=1;i<=n;i++){
        scanf("%lld",input+i);
    }
    int maxmin=1,minmax=2*n,now,l=1,r=n,neededminmax = n+1;
    for (int i=1;i<=n;i++){
        if (input[i]<0){
            now = -input[i];
            // if (now>neededminmax)return 1;
            while(ans[l])l++;
            if (now<maxmin){
                ans[r]=now;
            }
            else {
                maxmin=now;
                ans[l]=now;
            }
        }
        else {
            now = input[i];
            ans[r] = now;
            minmax=min(minmax,now);
        }
        r++;
        isused[now]=1;
        // if (now>=neededminmax){
        //     neededminmax--;
        //     while(isused[neededminmax])neededminmax--;
        // }
    }
    l=maxmin;
    for (int i=1;i<=r-1;i++){
        if (!ans[i]){
            while(isused[l])l++;
            ans[i]=l;
            isused[l]=1;
            // printf("%d ",ans[i]);
        }
    }
    if (l>minmax)return 1;
    l = 1;
    for (int i=r;i<=2*n;i++){
        if (!ans[i]){
            while(isused[l])l++;
            ans[i]=l;
            isused[l]=1;
            // printf("%d ",ans[i]);
        }
    }
    for (int i=1;i<=2*n;i++){
        printf("%lld%c",ans[i]," \n"[i==2*n]);
    }
    return 0;
}

signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        if (slove())puts("-1");
    }
}