#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int num[1000005];
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        ++a[temp];
    }
    for (int i=1;i<=n;i++){
        if (a[i]){
            for (int j=i;j<=k;j+=i)num[j]+=a[i];
        }
    }
    int max=0;
    int maxnum=0;
    for (int i=1;i<=k;i++){
        if (num[i]>max){
            max=num[i];
            maxnum=1;
        }
        else if (num[i]==max)maxnum++;
    }
    cout<<max<<' '<<maxnum<<"\n";
}