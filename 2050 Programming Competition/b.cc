#include <bits/stdc++.h>
using namespace std;

void slove(){
    int q,w,e,r,t,y;
    scanf("%d-%d-%d %d:%d:%d",&q,&w,&e,&r,&t,&y);
    printf("%d\n",(3600-t*60-y)%100);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}