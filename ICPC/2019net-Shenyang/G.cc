#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define int long long

const int maxn = 10000000;
long double r[maxn];

signed main() {
  // fast;
  int t;
  long double a = 2;
  r[1] = 2;
  // ra[1]=2*a;
  for (int i = 2; i < maxn; i++) {
    r[i]=1/(1/r[i-1]+1)+1;
    // ra[i]=1/(1/ra[i-1]+1/a)+a;
    // cout<<r[i]<<' '<<ra[i]/a<<endl;
  }
  cin >> t;
  while (t--) {
    string s;
    cin>>s>>a;
    if (s.length()<=7){
    // if (n<maxn/2){
      int n=stoi(s);
      cout<<fixed<<setprecision(10)<<r[n*2]*a<<endl;
    }
    else {
      cout<<fixed<<setprecision(10)<<r[maxn-1]*a<<endl;
    }
  }
}