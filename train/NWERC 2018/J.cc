#include<bits/stdc++.h>
using namespace std;
#define int long long
int getnum(int k){
    int ret=0;
    while(k){ret++;k>>=1;}
    return ret;
}
signed main(){
    long long n;
    cin>>n;
    vector<long long> input(n-1);
    long long maxx;
    cin>>maxx;
    for (auto &i:input)cin>>i;
    sort(input.begin(),input.end(),greater<long long>());
    // cout<<input[0];
    int now=input[0],addnum=0;
    for (int i=1;i<n;i++){
        if (now==input[i])continue;
        else {
            if ((now-input[i])*getnum(i)+addnum+input[i]<=maxx){
                addnum+=(now-input[i])*getnum(i);
                now=input[i];
            }
            else {
                int cha=maxx-(addnum+now);
                int tmp=cha/(getnum(i)-1)*getnum(i)+cha%(getnum(i)-1);
                cout<<(long long)(addnum+tmp)<<endl;
                return 0;
            }
        }
    }
    int cha=maxx-(addnum+now);
    int tmp=cha/(getnum(n-1)-1)*getnum(n-1)+cha%(getnum(n-1)-1);
    cout<<(long long)(addnum+tmp)<<endl;
}