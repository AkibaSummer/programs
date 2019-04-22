#include <bits/stdc++.h>
using namespace std;
int orz[200][200];
int main(){
    int n,m,h;
    cin>>n>>m>>h;
    vector<int>a(m),b(n);
    for (auto &i:a)cin>>i;
    for (auto &i:b)cin>>i;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int temp;
            cin>>temp;
            if (temp){
                cout<<min(b[i],a[j])<<' ';
            }
            else cout<<0<<' ';
        }
        cout<<endl;
    }
}