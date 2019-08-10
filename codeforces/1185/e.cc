#include <bits/stdc++.h>
using namespace std;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie();
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<string> input(n);
        for (auto &i:input)cin>>i;
        vector<pair<int,int>>minn(26,{-1,-1}),maxx(26,{-1,-1});
        int maxnum=-1;
        pair<int,int>maxpos;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (input[i][j]!='.'){
                    if (minn[input[i][j]-'a'].first==-1){
                        minn[input[i][j]-'a']={i,j};
                    }
                    maxx[input[i][j]-'a']={i,j};
                    if (input[i][j]-'a'>maxnum){
                        maxnum=input[i][j]-'a';
                        maxpos=maxx[maxnum];
                    }
                }
            }
        }
        vector<string> output(n,string(m,'.'));
        // for (int i=0;i<26;i++){
        //     cout<<minn[i].first<<' '<<minn[i].second<<' '<<maxx[i].first<<' '<<maxx[i].second<<endl;            
        // }
        int flag = 0;
        for (int i=0;i<26;i++){
            if (minn[i].first==-1)continue;
            if (minn[i].first==maxx[i].first){
                for (int j=minn[i].second;j<=maxx[i].second;j++){
                    // cout<<minn[i].first<<' '<<j<<' '<<char(i+'a')<<endl;
                    output[minn[i].first][j]=i+'a';
                }
            }
            else if (minn[i].second==maxx[i].second){
                for (int j=minn[i].first;j<=maxx[i].first;j++){
                    // cout<<j<<' '<<minn[i].second<<' '<<char(i+'a')<<endl;
                    output[j][minn[i].second]=i+'a';
                }
            }
            else {
                puts("NO");
                flag=1;
                break;
            }
        }
        // for (auto &i:output)cout<<i<<endl;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (input[i]!=output[i]){
                    flag=1;
                    break;
                }
            }
            if (flag)break;
        }
        if (flag)puts("NO");
        else {
            puts("YES");
            cout<<maxnum+1<<endl;
            for (int i=0;i<=maxnum;i++){
                if (minn[i].first==-1){
                    cout<<maxpos.first+1<<' '<<maxpos.second+1<<' '<<maxpos.first+1<<' '<<maxpos.second+1<<endl;
                }
                else {
                    cout<<minn[i].first+1<<' '<<minn[i].second+1<<' '<<maxx[i].first+1<<' '<<maxx[i].second+1<<endl;
                }
            }
        }
    }
}