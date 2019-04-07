#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int ttt=1;ttt<=t;ttt++){
        int n,p;
        cin >> n>>p;
        vector <int> input(n);
        for(auto &i:input) cin>>i;
        sort(input.begin(),input.end());
        int sum = 0,num=1;
        for (int i=1;i<p;i++){
            sum+=num*(input[i]-input[i-1]);
            num++;
        }
        int ans = sum;
        for (int i=0;i+p<n;i++){
            sum-=input[i+p-1]-input[i];
            sum+=(p-1)*(input[i+p]-input[i+p-1]);
            ans = min(ans,sum);
        }
        cout<<"Case #"<<ttt<<": "<<ans<<endl;
    }
}