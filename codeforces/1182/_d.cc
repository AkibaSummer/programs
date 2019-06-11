#include <bits/stdc++.h>
using namespace std;
vector<int>link[100005];
int degree[100005];
int dist[100005];

int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int q,w;
        cin>>q>>w;
        link[q].push_back(w);
        link[w].push_back(q);
        degree[q]++;
        degree[w]++;
    }
    queue<int> node;
    for (int i=1;i<=n;i++){
        if (degree[i]==1){
            node.push(i);
            dist[i]=1;
        }
    }
    while (!node.empty()){
        int top=node.front();
        node.pop();
        if (node.empty()){
            cout<<top<<endl;
            return 0;
        }
        else if (degree[top]!=1){
            cout<<-1<<endl;
            return 0;
        }
        else {
            degree[top]=0;
            for (auto i:link[top]){
                if (dist[i]==dist[top]+1){
                    degree[i]--;
                }
                else if (dist[i]==0){
                    node.push(i);
                    dist[i]=dist[top]+1;
                    degree[i]--;
                    break;
                }
            }
        }
    }
    cout<<-1<<endl;
    // err();
}