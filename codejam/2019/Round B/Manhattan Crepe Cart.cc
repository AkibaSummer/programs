#include <bits/stdc++.h>
using namespace std;
struct p{
    int x,y;
    char c;
};
p in[505];
int linen[100005],linee[100005],linew[100005],lines[100005],sumx[100005],sumy[100005];
void slove(){
    int p,q;
    cin>>p>>q;
    int minx=0,miny=0;
    memset(linen,0,sizeof(linen));
    memset(linee,0,sizeof(linee));
    memset(lines,0,sizeof(lines));
    memset(linew,0,sizeof(linew));
    memset(sumx,0,sizeof(sumx));
    memset(sumy,0,sizeof(sumy));
    for (int i=1;i<=p;i++){
        int x,y;
        char c;
        cin>>x>>y>>c;
        switch (c){
            case 'N':
                linen[y]++;
                break;
            case 'S':
                lines[y]++;
                break;
            case 'E':
                linee[x]++;
                break;
            case 'W':
                linew[x]++;
                break;
            default:
                break;
        }
    }
    int toty=0,totx=0;
    for (int i=0;i<=q;i++){
        sumy[i]+=toty;
        toty+=linen[i];
        sumx[i]+=totx;
        totx+=linee[i];
    }
    totx=toty=0;
    for (int i=q;i>=0;i--){
        sumy[i]+=toty;
        toty+=lines[i];
        sumx[i]+=totx;
        totx+=linew[i];
    }
    totx=toty=0;
    for (int i=0;i<=q;i++){
        if (sumx[i]>totx){
            totx=sumx[i];
            minx=i;
        }
        if (sumy[i]>toty){
            toty=sumy[i];
            miny=i;
        }
    }
    
    cout<<minx<<' '<<miny<<endl;
}
int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        slove();
    }
}

/*
3
1 10
5 5 N
4 10
2 4 N
2 6 S
1 5 E
3 5 W
8 10
0 2 S
0 3 N
0 3 N
0 4 N
0 5 S
0 5 S
0 8 S
1 5 W
*/