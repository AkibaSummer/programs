#include <bits/stdc++.h>
using namespace std;

int n,m;
struct link{
    int a,b,c,d;
}links[305];
struct tlink{
    int tar,id;
};
bool del[305];

vector<tlink>flink[205];
bool colored[205];

long long sum1(0),sum2(0);
void color(int n){
    if (colored[n])return;
    colored[n]=1;
    for (auto i:flink[n]){
        if (!del[i.id]) color(i.tar);
    }
}

bool pd(int a,int b){
    memset(colored,0,sizeof(colored));
    color(a);
    return colored[b];
}
int main(){
    cin>>n>>m;
    tlink temp;
    for(int i=1;i<=n;i++){
        cin>>links[i].a>>links[i].b>>links[i].c>>links[i].d;
        temp.tar=links[i].b;temp.id=i;
        flink[links[i].a].push_back(temp);
        temp.tar=links[i].a;
        flink[links[i].b].push_back(temp);
        sum1+=links[i].c;
        sum2+=links[i].d;
    }
    long long ans=(long long)sum1*sum2;
    int tempmax,tempid;
    for (int i=m;i>=n;i--){
        tempmax=0;
        for (int j=1;j<=m;j++){
            if (!del[j]&&pd(links[j].a,links[j].b)){
                if (sum1*sum2-(sum1-links[j].c)*(sum2-links[j].d)>tempmax){
                    tempmax=sum1*sum2-(sum1-links[j].c)*(sum2-links[j].d);
                    tempid=j;
                }
            }
        }
        ans-=tempmax;
        sum1-=links[tempid].c;
        sum2-=links[tempid].d;
        del[tempid]=1;
    }
    cout<<sum1*sum2<<endl;
    
    
    
}