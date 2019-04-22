#include <bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005];
inline void slove(){
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    int flag=0,flag2=0;
    int l1=0,l2=0,l3=0;
    for (int i=0;i<n;i++){
        if (a[i]!=b[i]){
            if (flag == 0){
                l1++;
            }
            else {
                l2++;
                if (flag2)flag2=2;
            }
        }
        else {
            if (l1)flag = 1;
            if (l2&&flag2!=2)flag2=1;
        }
    }
    if (flag2==2){
        puts("0");
    }
    else if (l1==0){
        printf("%lld\n",(long long)n*(n+1)/2);
    }
    else if (l2==0){
        printf("%d\n",2*n-2);
    }
    else {
        puts("6");
    }

}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        slove();
    }
    return 0;
}
/*
3
1
1
0
2
00
11
5
01010
00111

*/