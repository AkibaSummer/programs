#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
vector <int> links[1010];
int linknum[1010];
pair<double,double> ans[1010];
int visited[1010];
int num[1010];

void getans(double l,double r,int n,pair<double,double> now={1,0}){
    // cout<<n<<' '<<l<<' '<<r<<endl;
    ans[n]={now.first+cos((r-l)/2+l),now.second+sin((r-l)/2+l)};
    visited[n]=1;
    for (int i=0;i<links[n].size();i++){
        if (visited[links[n][i]]){
            links[n].erase(links[n].begin()+i);
        }
    }
    int sum=0;
    for (int i=0;i<links[n].size();i++){
        if (!visited[links[n][i]]){
            getans((r-l)/num[n]*sum+l,(r-l)/num[n]*(sum+num[links[n][i]])+l,links[n][i],ans[n]);
            sum+=num[links[n][i]];
        }
    }
}

int dfs(int n,int pre){
    if (links[n].size()==1){
        num[n]=1;
        return 1;
    }
    else {
        int sum=0;
        for (auto &i:links[n]){
            if (i!=pre)sum+=dfs(i,n);
        }
        return num[n]=sum;
    }
}

int main(){
    int n;
    cin>>n;
    int maxx=0;
    int maxpoint=1;
    for (int i=1;i<n;i++){
        int q,w;
        cin>>q>>w;
        links[q].push_back(w);
        links[w].push_back(q);
        linknum[q]++;
        linknum[w]++;
        if (linknum[q]>maxx){
            maxx=linknum[q];
            maxpoint=q;
        }
        if (linknum[w]>maxx){
            maxx=linknum[w];
            maxpoint=w;
        }
    }



    dfs(maxpoint,-1);
    // cout<<maxpoint<<endl;
    // for (int i=1;i<=n;i++)cout<<num[i]<<' ';
    // cout<<endl;
    getans(0,2*pi,maxpoint);
    for (int i =1;i<=n;i++){
        cout<<fixed<<setprecision(10)<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}