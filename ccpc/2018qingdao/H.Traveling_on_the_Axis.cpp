#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        long long j(0),o(0),ans(0);
        cin>>s;
        for (int i=0;i<s.size();i++){
            o++;
            if (s[i]=='0'){
                ans+=(j+o*2)*(s.size()-i);
                o+=j;
                j=0;
            }
            else {
                ans+=(o+j*2)*(s.size()-i);
                j+=o;
                o=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}