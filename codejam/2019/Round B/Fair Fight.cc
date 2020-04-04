#include <bits/stdc++.h>
using namespace std;
#define C 1
#define N 2
int cc[100005],dd[100005];
// struct p{
//     int num,pos,type;
// };
// inline bool cmp(p a,p b){
//     return a.num<b.num;
// }
// vector<p> dl;
// int n,k;

// int getans(int l,int r,int pos){
//     if (l>r)return 0;
//     if (l==r){
//         if (abs(cc[l]-nn[l])<=k)return 1;
//         else return 0;
//     }
//     else {
//         int ret = 0;
//         while (pos<2*n||dl[pos].pos<l||dl[pos].pos>r){
//             pos++;
//         }
//         if (pos==2*n)return 0;
//         int nowpos=dl[pos].pos;
//         if (abs(cc[nowpos]-nn[nowpos])<=k){
//             ret+=(nowpos-l+1)*(r-nowpos+1);
//         }
//         ret+=getans(l,nowpos-1,pos+1)+getans(nowpos+1,r,pos+1);
//     }
// }

void slove(){
    int n,k;
    cin>>n>>k;
    // dl.clear();
    for (int i=1;i<=n;i++){
        cin>>cc[i];
        // dl.push_back({cc[i],i,C});
    }
    for (int i=1;i<=n;i++){
        cin>>dd[i];
        // dl.push_back({nn[i],i,N});
    }
    // sort(dl.begin(),dl.end(),cmp);
    // cout<<getans(1,n,0)<<endl;
    int ans=0;
    for (int i=1;i<=n;i++){
        int maxc=-1,maxd=-1;
        for (int j=i;j<=n;j++){
            maxc=max(cc[j],maxc);
            maxd=max(dd[j],maxd);
            if (abs(maxc-maxd)<=k){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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
6
4 0
1 1 1 8
8 8 8 8
3 0
0 1 1
1 1 0
1 0
3
3
5 0
0 8 0 8 0
4 0 4 0 4
3 0
1 0 0
0 1 2
5 2
1 2 3 4 5
5 5 5 5 10
*/