#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;

int main(){
    int n;
	cin>>n;    
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0){
            ans.push_back((long long)(1+n-i+1)*n/i/2);
            ans.push_back((long long)(1+n-n/i+1)*i/2);
        }
    }
    
    sort(ans.begin(),ans.end());
    ans.push_back(-1);
    for (int i=0;i<ans.size()-1;i++){
        if (ans[i]!=ans[i+1])
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}