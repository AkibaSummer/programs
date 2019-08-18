#include <bits/stdc++.h>
using namespace std;

#define int long long

int maps[55][55];

int getans(int x1,int y1,int x2,int y2){
    cout.flush();fflush(stdout);
    cout<<"?"<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    cout.flush();fflush(stdout);
    int ret;
    cin>>ret;
    return ret;
}

int output(int type,int n){
    cout<<"!"<<endl;
    if (type==0){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (maps[i][j]==3)maps[i][j]=0;
                else if (maps[i][j]==4)maps[i][j]=1;
            }
        }
    }
    else {
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (maps[i][j]==3)maps[i][j]=1;
                else if (maps[i][j]==4)maps[i][j]=0;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<maps[i][j];
        }
        cout<<endl;
    }
    exit(0);
}

signed main(){
    int n;
    cin>>n;
    maps[1][1]=1;
    maps[n][n]=0;
    maps[1][2]=3;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (abs(j-i)%2==0){
                if (i==j&&i==n)break;
                if (i==1){
                    if (j==1)continue;
                    maps[i][j]=getans(i,j-2,i,j)?maps[i][j-2]:1-maps[i][j-2];
                }
                else if (j==1){
                    maps[i][j]=getans(i-2,j,i,j)?maps[i-2][j]:1-maps[i-2][j];
                }
                else {
                    maps[i][j]=getans(i-1,j-1,i,j)?maps[i-1][j-1]:1-maps[i-1][j-1];
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=2;j<=n;j++){
            if (abs(j-i)%2==1){
                if (i==1&&j==2)continue;
                else {
                    if (i==1){
                        maps[i][j]=getans(i,j-2,i,j)?maps[i][j-2]:7-maps[i][j-2];
                    }
                    else if (i==2)
                    {
                        maps[i][j]=getans(i-1,j-1,i,j)?maps[i-1][j-1]:7-maps[i-1][j-1];
                    }
                    else {
                        maps[i][j]=getans(i-2,j,i,j)?maps[i-2][j]:7-maps[i-2][j];
                    }
                }
            }
        }
    }
    for (int i=2;i<=n;i+=2){
        maps[i][1]=getans(i,1,i,3)?maps[i][3]:7-maps[i][3];
    }
    int flag = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (maps[i][j]==4) {flag = 1;break;}
        }
        if (flag)break;
    }
    int flagg=0,type=0;//type0 3->0
    if (flag==0){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i<=n-3&&abs(j-i)%2==0){
                    if (maps[i][j]==maps[i+2][j]){
                        flagg=1;
                        if (getans(i,j,i+3,j)){
                            if (maps[i][j]==0)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i][j]==1)output(0,n);
                            else output(1,n);
                        }
                    }
                }
                if (j<=n-3&&abs(j-i)%2==0){
                    if (maps[i][j]==maps[i][j+2]){
                        flagg=1;
                        if (getans(i,j,i,j+3)){
                            if (maps[i][j]==0)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i][j]==1)output(0,n);
                            else output(1,n);
                        }
                    }
                }
                if (i<n&&j<n&&abs(j-i)%2==0&&maps[i][j]==maps[i+1][j+1]){
                    if (i==n-1){
                        if (getans(i-1,j,i+1,j+1)){
                            if (maps[i][j]==0)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i][j]==1)output(0,n);
                            else output(1,n);
                        }
                    }
                    else {
                        if (getans(i,j,i+2,j+1)){
                            if (maps[i][j]==0)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i][j]==1)output(0,n);
                            else output(1,n);
                        }
                    }
                }
                if (i<n&&j<n&&abs(j-i)%2==1&&maps[i+1][j]==maps[i][j+1]){
                    if (i==n-1){
                        if (getans(i-1,j,i+1,j+1)){
                            if (maps[i-1][j]==0)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i-1][j]==1)output(0,n);
                            else output(1,n);
                        }
                    }
                    else {
                        if (getans(i,j,i+2,j+1)){
                            if (maps[i-1][j]==0)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i-1][j]==1)output(0,n);
                            else output(1,n);
                        }
                    }
                }
            }
        }
    }
    else {
        for (int i=1;i<n;i++){
            for (int j=1;j<n;j++){
                if (abs(j-i)%2==0&&maps[i+1][j]!=maps[i][j+1]){
                    if (i==n-1){
                        if (getans(i-1,j,i+1,j+1)){
                            if (maps[i-1][j]-3==maps[i+1][j+1])output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i-1][j]-3!=maps[i+1][j+1])output(0,n);
                            else output(1,n);
                        }
                    }
                    else {
                        if (getans(i,j,i+2,j+1)){
                            if (maps[i][j]==maps[i+2][j+1]-3)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i][j]!=maps[i+2][j+1]-3)output(0,n);
                            else output(1,n);
                        }
                    }
                }
                else if (abs(j-i)%2==1&&maps[i][j]!=maps[i+1][j+1]){
                    if (i==n-1){
                        if (getans(i-1,j,i+1,j+1)){
                            if (maps[i-1][j]==maps[i+1][j+1]-3)output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i-1][j]!=maps[i+1][j+1]-3)output(0,n);
                            else output(1,n);
                        }
                    }
                    else {
                        if (getans(i,j,i+2,j+1)){
                            if (maps[i][j]-3==maps[i+2][j+1])output(0,n);
                            else output(1,n);
                        }
                        else {
                            if (maps[i][j]-3!=maps[i+2][j+1])output(0,n);
                            else output(1,n);
                        }
                    }
                }
            }
        }
    }
}

/*
5
0
1
1
1
1
0
1
0
0
1
0
1
1
1
0
0
0
0
1
0
1
1
1

*/