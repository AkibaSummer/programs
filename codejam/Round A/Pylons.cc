#include <bits/stdc++.h>
using namespace std;

void slove(){
    int n,m;
    cin>>n>>m;
    if (max(n,m)<=3){
        printf("IMPOSSIBLE\n");
        return ;
    }
    if (max(n,m)==4&&min(n,m)==2){
        printf("IMPOSSIBLE\n");
        return ;
    }
    printf("POSSIBLE\n");
    if (max(n,m)>=5){
        if (n>m){
            if (m%2){
                for (int i=1;i<=n;i++){
                    cout<<i<<' '<<1<<endl;
                    cout<<(i+1)%n+1<<' '<<2<<endl;
                    cout<<i<<' '<<3<<endl;
                }
                for (int i=4;i<=m;i+=2){
                    for (int j=1;j<=n;j++){
                        cout<<j<<' '<<i<<endl;
                        cout<<(j+2)%n+1<<' '<<i+1<<endl;
                    }
                }
            }
            else {
                for (int i=1;i<=m;i+=2){
                    for (int j=1;j<=n;j++){
                        cout<<j<<' '<<i<<endl;
                        cout<<(j+2)%n+1<<' '<<i+1<<endl;
                    }
                }
            }
        }
        else {
            if (n%2){
                for (int i=1;i<=m;i++){
                    cout<<1<<' '<<i<<endl;
                    cout<<2<<' '<<(i+1)%m+1<<endl;
                    cout<<3<<' '<<i<<endl;
                }
                for (int i=4;i<=n;i+=2){
                    for (int j=1;j<=m;j++){
                        cout<<i<<' '<<j<<endl;
                        cout<<i+1<<' '<<(j+2)%m+1<<endl;
                    }
                }
            }
            else {
                for (int i=1;i<=n;i+=2){
                    for (int j=1;j<=m;j++){
                        cout<<i<<' '<<j<<endl;
                        cout<<i+1<<' '<<(j+2)%m+1<<endl;
                    }
                }
            }
        }
    }
    else{
        if (min(n,m)==3){
            if (n>m){
                for (int i=1;i<=n;i++){
                    cout<<i<<' '<<1<<endl;
                    cout<<(i+1)%n+1<<' '<<2<<endl;
                    cout<<i<<' '<<3<<endl;
                }         
            }
            else {
                for (int i=1;i<=m;i++){
                    cout<<1<<' '<<i<<endl;
                    cout<<2<<' '<<(i+1)%m+1<<endl;
                    cout<<3<<' '<<i<<endl;
                }
            }
        }
        else {
            printf("1 1\n");
            printf("2 3\n");
            printf("3 1\n");
            printf("4 3\n");
            printf("2 2\n");
            printf("4 1\n");
            printf("3 3\n");
            printf("1 2\n");
            printf("2 4\n");
            printf("3 2\n");
            printf("1 3\n");
            printf("3 4\n");
            printf("4 2\n");
            printf("1 4\n");
            printf("2 1\n");
            printf("4 4\n");
        }
    }
}

int main(){
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        printf("Case #%d: ",tt);
        slove();
    }
}