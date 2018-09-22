#include <bits/stdc++.h>
using namespace std;
int n,m;
char inmap[105][105];
int mincost[105][105][6];
void find(int x,int y,int pnum,int cost){
    if (x<1||y<1||x>n||y>n)return;
    if (mincost[x][y][pnum]<=cost)return;
    if (inmap[x][y]=='#')pnum--;
    if (inmap[x][y]=='B')pnum++;
    if (pnum>5||pnum<0)return;
    mincost[x][y][pnum]=cost;
    if (inmap[x][y]=='T')return;
    if (inmap[x][y]=='P')cost--;
    find(x+1,y,pnum,cost+1);
    find(x,y+1,pnum,cost+1);
    find(x-1,y,pnum,cost+1);
    find(x,y-1,pnum,cost+1);
}
int main(){
    while(cin>>n>>m){
        memset(mincost,0x3f,sizeof(mincost));
        for (int i=1;i<=n;i++){
            scanf("%s",inmap[i]+1);
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (inmap[i][j]=='S'){
                    mincost[i][j][0]=-1;
                    find(i,j,0,0);
                    break;
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (inmap[i][j]=='T'){
                    cout<<(mincost[i][j][0]!=0x3f3f3f3f?mincost[i][j][0]:0)<<endl;
                    break;
                }
            }
        }
        
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                for (int k=0;k<=5;k++){
                    cout<<mincost[i][j][k];
                }
                cout<<' ';
            }
            cout<<endl;
        }
    }
}