#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
const int MOD=100000037ll;
int tot;
int hashs[maxn];
int hashs2[maxn];
int di[maxn];
const int seed=237;

inline void init_hash(int hashs[],const string&a) {
    hashs[0]=a[0];
    for(int i=1; i<(int)a.size(); i++) {
        hashs[i]=(hashs[i-1]*seed+a[i])%MOD;
    }
};

inline int get_hash(int HA[],int l,int r){
    int R=HA[r];
    int L=(l==0?0:HA[l-1]);
    L=L*di[r-l+1]%MOD;
    int ret=((R-L)%MOD+MOD)%MOD;
    return ret;
};

inline bool gao(int len) {
    if(len==0)return true;
    int R1=tot-1;
    int L1=tot-len;
    int L2=0;
    int R2=len-1;
    return get_hash(hashs,L1,R1)==get_hash(hashs2,L2,R2);
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	di[0]=1;
	for(int i=1; i<maxn; i++) di[i]=di[i-1]*seed%MOD;
    int q;
    string a;
	cin>>q>>a;
	init_hash(hashs,a);
	tot=a.size();
	cout<<a;
	q--;
	while(q--) {
		cin>>a;
		init_hash(hashs2,a);
		int L=0,R=min(tot,(int)a.size()),ans=0;
		for(int i=L; i<=R; i++) {
			if(gao(i))ans=i;
		}
		cout<<a.substr(ans);
		for(int i=ans; i<(int)a.size(); i++) {
			hashs[tot]=(hashs[tot-1]*seed+a[i])%MOD;
			tot++;
		}
	}
	return 0;
}