#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

struct dir{
    int w,s,a,d;
};

void update(int x,int y,double k,vector<vector<double>>&maps,queue<pair<int,int>> &que){
    if (x<0||y<0||x>maps.size()||y>maps[0].size()) return;
    if (maps[x][y]-k>eps){
        maps[x][y]=k;
        que.push({x,y});
    }
}

void slove(){
    int n;
    cin>>n;
    vector<int> x1(n),x2(n),y1(n),y2(n);
    vector<int> unix,uniy;
    unix.reserve(2*n+2);uniy.reserve(2*n+2);
    for (int i=0;i<n;i++){
        cin>>x1[i]>>x2[i]>>y1[i]>>y2[i];
        unix.push_back(x1[i]);
        unix.push_back(x2[i]);
        uniy.push_back(y1[i]);
        uniy.push_back(y2[i]);
    }
    int xa,xb,ya,yb;
    cin>>xa>>xb>>ya>>yb;
    unix.push_back(xa);
    unix.push_back(xb);
    uniy.push_back(ya);
    uniy.push_back(yb);
    sort(unix.begin(),unix.end());
    unix.erase(unique(unix.begin(),unix.end()),unix.end());
    sort(uniy.begin(),uniy.end());
    uniy.erase(unique(uniy.begin(),uniy.end()),uniy.end());
    for (auto &i:x1)i=lower_bound(unix.begin(),unix.end(),i)-unix.begin();
    for (auto &i:x2)i=lower_bound(unix.begin(),unix.end(),i)-unix.begin();
    for (auto &i:y1)i=lower_bound(uniy.begin(),uniy.end(),i)-uniy.begin();
    for (auto &i:y2)i=lower_bound(uniy.begin(),uniy.end(),i)-uniy.begin();
    xa=lower_bound(unix.begin(),unix.end(),xa)-unix.begin();
    xb=lower_bound(unix.begin(),unix.end(),xb)-unix.begin();
    ya=lower_bound(uniy.begin(),uniy.end(),ya)-uniy.begin();
    yb=lower_bound(uniy.begin(),uniy.end(),yb)-uniy.begin();
    vector<vector<double>> maps(unix.size(),vector<double>(uniy.size(),100000000000.0));
    vector<vector<dir>> speed(unix.size()+1,vector<dir>(uniy.size()+1));
    for (int i=0;i<n;i++){ 
        speed[x1[i]+1][y1[i]].w++;
        speed[x1[i]+1][y2[i]+1].w--;
        speed[x2[i]+1][y1[i]].w--;
        speed[x2[i]+1][y2[i]+1].w++;
        
        speed[x1[i]][y1[i]].s++;
        speed[x1[i]][y2[i]+1].s--;
        speed[x2[i]][y1[i]].s--;
        speed[x2[i]][y2[i]+1].s++;
        
        speed[x1[i]][y1[i]+1].a++;
        speed[x1[i]][y2[i]+1].a--;
        speed[x2[i]+1][y1[i]+1].a--;
        speed[x2[i]+1][y2[i]+1].a++;
        
        speed[x1[i]][y1[i]].d++;
        speed[x1[i]][y2[i]].d--;
        speed[x2[i]+1][y1[i]].d--;
        speed[x2[i]+1][y2[i]].d++;
    }
    for (int i=1;i<unix.size();i++){
        for (int j=0;j<uniy.size();j++){
            speed[i][j].w+=speed[i-1][j].w;
            speed[i][j].s+=speed[i-1][j].s;
            speed[i][j].a+=speed[i-1][j].a;
            speed[i][j].d+=speed[i-1][j].d;
        }
    }
    for (int i=0;i<unix.size();i++){
        for (int j=1;j<uniy.size();j++){
            speed[i][j].w+=speed[i][j-1].w;
            speed[i][j].s+=speed[i][j-1].s;
            speed[i][j].a+=speed[i][j-1].a;
            speed[i][j].d+=speed[i][j-1].d;
        }
    }
    maps[xa][ya]=0;
    queue<pair<int,int>> que;
    que.push({xa,ya});
    while(!que.empty()){
        int x=que.front().first,y=que.front().second;
        que.pop();
        if (x>0) update(x-1,y,(unix[x]-unix[x-1])/speed[x][y].w,maps,que);
        if (x<unix.size()-1) update(x+1,y,(unix[x+1]-unix[x])/speed[x][y].s,maps,que);
        if (y>0) update(x,y-1,(uniy[y]-uniy[y-1])/speed[x][y].a,maps,que);
        if (y<uniy.size()-1) update(x,y+1,(uniy[y+1]-uniy[y])/speed[x][y].d,maps,que);
    }
    cout<<fixed<<setprecision(5)<<maps[xb][yb]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
}