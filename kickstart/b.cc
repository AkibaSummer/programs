#include <bits/stdc++.h>
using namespace std;
int maps[300][300];
int main(){
    int t;
    cin>>t;
    for (int ttt=1;ttt<=t;ttt++){
        int r,c;
        cin>>r>>c;
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                maps[i][j]=0x7fffffff;
            }
        }
        queue<pair<int,int> > que;
        for (int i=1;i<=r;i++){
            string input;
            cin>>input;
            for (int j=1;j<=c;j++){
                if (input[j-1]=='1'){
                    maps[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        while (!que.empty()){
            int i=que.front().first;
            int j=que.front().second;
            que.pop();
            if (i-1>=1&&maps[i-1][j]>maps[i][j]+1){
                maps[i-1][j]=maps[i][j]+1;
                que.push({i-1,j});
            }
            if (j-1>=1&&maps[i][j-1]>maps[i][j]+1){
                maps[i][j-1]=maps[i][j]+1;
                que.push({i,j-1});
            }
            if (i+1<=r&&maps[i+1][j]>maps[i][j]+1){
                maps[i+1][j]=maps[i][j]+1;
                que.push({i+1,j});
            }
            if (j+1<=c&&maps[i][j+1]>maps[i][j]+1){
                maps[i][j+1]=maps[i][j]+1;
                que.push({i,j+1});
            }
        }
        int maxx = 0;
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                maxx=max(maxx,maps[i][j]);
            }
        }

        vector <pair<int,int> >maxpoint;
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                if (maxx==maps[i][j]){
                    maxpoint.push_back({i,j});
                }
            }
        }

        if (maxpoint.size()==1){
            maps[maxpoint[0].first][maxpoint[0].second]=0;
            que.push({maxpoint[0].first,maxpoint[0].second});
        }
        else {
            
        }
        while (!que.empty()){
            int i=que.front().first;
            int j=que.front().second;
            que.pop();
            if (i-1>0&&maps[i-1][j]>maps[i][j]+1){
                maps[i-1][j]=maps[i][j]+1;
                que.push({i-1,j});
            }
            if (j-1>0&&maps[i][j-1]>maps[i][j]+1){
                maps[i][j-1]=maps[i][j]+1;
                que.push({i,j-1});
            }
            if (i+1<=r&&maps[i+1][j]>maps[i][j]+1){
                maps[i+1][j]=maps[i][j]+1;
                que.push({i+1,j});
            }
            if (j+1<=c&&maps[i][j+1]>maps[i][j]+1){
                maps[i][j+1]=maps[i][j]+1;
                que.push({i,j+1});
            }
        }
        maxx=0;

        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                if (maxx<maps[i][j]){
                    maxx=max(maxx,maps[i][j]);
                }
            }
        }

        cout<<"Case #"<<ttt<<": "<<maxx<<endl;
    }
}
/*
5
3 3
101
000
101
1 2
11
5 5
10001
00000
00000
00000
10001
5 9
100010001
000000000
000000000
000000000
100010001
9 9
100010001
000000000
000000000
000000000
100000001
000000000
000000100
000000000
100010001

*/
