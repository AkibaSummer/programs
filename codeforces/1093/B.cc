#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        vector<int> orz(26);
        int cnt=0;
        for (auto i:s){
            orz[i-'a']++;
        	if (orz[i-'a']==1)cnt++;
        }
        if (cnt ==1 ){
            cout<<-1<<endl;
        }
        else {
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
    }
}