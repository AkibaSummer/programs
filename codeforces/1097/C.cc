#include <bits/stdc++.h>
using namespace std;
int slove(string &s){
    int flagz=true,flagf=true;
    int sum(0);
    for (auto i:s){
        if (i=='(')sum++;
        else sum--;
        if (sum<0)flagz=false;
    }
    if (flagz) return sum;
    sum=0;
    for (int i=s.length()-1;i>=0;i--){
        if (s[i]==')')sum++;
        else sum--;
        if (sum<0)flagf=false;
    }
    if (flagf) return -sum;
    return 1<<30;
}
int main(){
    int n;
    cin>>n;
    vector<int> orz;
    for (int i=1;i<=n;i++){
        string a;
        cin>>a;
        orz.push_back(slove(a));
    }
    int l=0,r=n-1,ans=0;
    sort(orz.begin(),orz.end());
    while (r>l){
        if (orz[r]>-orz[l])r--;
        else if (orz[r]<-orz[l])l++;
        else ans++,r--,l++;
    }
    cout<<ans<<endl;
}