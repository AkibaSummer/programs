#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

vector<int>links [maxn];
vector<int>links2[maxn];
int link_num[maxn];
int deled[maxn];
int n,m;
    

void del(int n){
    deled[n]=1;
    for (auto i:links[n]){
        if (!deled[i]){
            link_num[i]--;
            if (link_num[i]==1){
                del(i);
            }
        }
    }
}

void del2(int n){
    deled[n]=1;
    int q=0,w=0;
    for (auto i:links[n]){
        if (!deled[i]){
            if (q){
                w=i;
                break;
            }
            else {
                q=i;
            }
        }
    }
    // cout<<n<<' '<<q<<' '<<w<<' '<<endl;
    for (auto &i:links[w]){
        if (n==i){
            i=q;break;
        }
    }
    for (auto &i:links[q]){
        if (n==i){
            i=w;break;
        }
    }
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int q,w;
        cin>>q>>w;
        links[q].push_back(w);
        links[w].push_back(q);
        link_num[q]++;
        link_num[w]++;
    }
    for (int i=1;i<=n;i++){
        if (link_num[i]==1) del(i);
    }
    for (int i=1;i<=n;i++){
        if (link_num[i]==2) del2(i);
    }
    for (int i=1;i<=n;i++){
        if (!deled[i]){
            for (auto j:links[i]){
                if (!deled[j]){
                    links2[i].push_back(j);
                }
            }
        }
    }
    puts("");
    // for (int i=1;i<=n;i++){
    //     cout<<i<<":"<<link_num[i]<<endl;
    // }
    for (int i=1;i<=n;i++){
        for (auto j:links2[i]){
            cout<<i<<' '<<j<<endl;
        }
    }
    
}
/*
4 5
1 2
1 3
1 4
2 3
3 4

7 9
1 2
1 3
2 4
2 5
3 6
3 7
2 3
4 5
6 7

 */