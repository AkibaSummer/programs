#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int tot[200005][26];

    int n;
int slove(){
    string s;
    cin>>s;
    int l=0,r=n-1;
        int num[26];
        memset(num,0,sizeof(num));
        for (auto i:s){
            num[i-'a']++;
        }
    while (l<r){
        int mid=(r+l)/2;
        bool judge=false;
        for (int i=0;i<26;i++){
            if (num[i]>tot[mid][i]){
                judge=true;
                break;
            }
        }
        if (judge){
            l=mid+1;
        }
        else {
            r=mid;
        }
        // cout<<mid<<' ';
    }
    if (l==r)
        cout<<l+1<<endl;
}

int main(){
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++){
        tot[i][s[i]-'a']++;
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<26;j++){
            tot[i][j]+=tot[i-1][j];
        }
    }
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}