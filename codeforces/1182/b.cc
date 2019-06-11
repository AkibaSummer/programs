#include <bits/stdc++.h>
using namespace std;
string a[505];
int flag = 1;
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=1;i<n-1;i++){
        for (int j=1;j<m-1;j++){
            if (a[i][j-1]=='*'&&a[i][j+1]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j]=='*'){
                int k=j;
                while (--k>=0&&a[i][k]=='*'){
                    a[i][k]='.';
                }
                k=j;
                while (++k<m&&a[i][k]=='*'){
                    a[i][k]='.';
                }
                k=j;
                while (--k>=0&&a[k][j]=='*'){
                    a[k][j]='.';
                }
                k=j;
                while (++k<n&&a[k][j]=='*'){
                    a[k][j]='.';
                }
                a[i][j]='.';
                flag = 0;
                break;
            }
        }
        if (!flag)break;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]=='*'){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if (flag){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}