#include <bits/stdc++.h>
using namespace std;
int score[100000][10];
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> sc(m);
    string s;
    for (int i=1;i<=n;i++){
        cin>>s;
        for (int j=0;j<s.size();j++){
            score[j][s[j]-'A']++;
        }
    }
    for (auto &i:sc){
        cin>>i;
    }
    int ans = 0;
    for (int j=0;j<m;j++){
        int maxx=0;
        for (int i=0;i<=4;i++){
            maxx=max(maxx,score[j][i]);
        }
        ans+=maxx*sc[j];
    }
    cout<<ans<<endl;

}