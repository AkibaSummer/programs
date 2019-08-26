#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
// #define int long long

inline void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void slove() {
    int a, b, n;
    cin >> n;
    map<int, int> pre;
    vector<int> input(2*n);
    for (int i=0;i<n;i++) {
        cin >> input[i];
        input[i+n]=input[i];
    }
    map<int,int> nums;
    int l=0,ans=-1;
    for (int i=0;i<2*n;i++){
        nums[input[i]]++;
        while(nums[input[i]]==2){
            nums[input[l]]--;
            l++;
        }
        if ((i<n-1)||(l>n))continue;
        // cout<<l<<' '<<i<<endl;
        ans=max(ans,i-l);
    }
    cout<<n-ans-1<<endl;
}

int main() {
    // fast();
    // int tt;
    // cin>>tt;
    // tt=1;
    // while(tt--){
    slove();
    // }
}