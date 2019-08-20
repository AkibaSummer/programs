#include <bits/stdc++.h>
using namespace std;

const int inf = 100000;
int dist[105][105];
int good[105];

void getmindist(int n,vector<vector<int>> &links){
    queue<int> point;
    point.push(n);
    while(point.size()){
        int now=point.front();
        point.pop();
        for (auto &i:links[now]){
            if (dist[n][i]>dist[n][now]+1){
                dist[n][i]=dist[n][now]+1;
                point.push(i);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dist[i][j]=inf;
            if (i==j)dist[i][j]=0;
        }
    }
    vector<vector<int>> links(n+1,vector<int>(n+1));
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int j=0;j<n;j++){
            if (s[j]=='1')links[i].push_back(j+1);
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout<<i<<':';
    //     for (auto &j:links[i])cout<<j<<' ';
    //     cout<<endl;
    // }
    for (int i=1;i<=n;i++){
        getmindist(i,links);
    }
    int m;
    cin>>m;
    vector<int>input(m);
    vector<int>output;
    for (auto &i:input)cin>>i;
    output.push_back(input[0]);
    int pre=input[0],dis=0;
    for(int i=1;i<m;i++){
        dis++;
        // puts("233");
        if (dist[pre][input[i]]!=dis){
            dis=0;
            output.push_back(input[i-1]);
            pre=input[i-1];
            i--;
        }
    }
    output.push_back(input[input.size()-1]);
    cout<<output.size()<<endl;
    for (auto i:output){
        cout<<i<<' ';
    }
    cout<<endl;
}