#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define int __int128

using namespace std;

void exgcd(int a,int b,int &g,int &x,int &y) {
    if (b == 0) {
        g = a;
        x = 1;
        y = 0;
        return;
    }
    exgcd(b,a%b,g,y,x);
    y-=(a/b)*x;
}

bool flag = false;

int a1,a2,n1,n2;

int abs(int x) {
    return x>0?x:-x;
} 

void china() {
    int d = a2 - a1;
    int g,x,y;
    exgcd(n1,n2,g,x,y);
    if (d % g == 0) {
        x = ((x*d/g)%(n2/g)+(n2/g))%(n2/g);
        a1 = x*n1 + a1;
        n1 = (n1*n2)/g;
    }
    else 
        flag = true;
}

long long as[20];

long long ns[20];

int realchina(int n) {
    a1 = as[0];
    n1 = ns[0];
    for (int i = 1;i<n;i++) {
        a2 = as[i];
        n2 = ns[i];
        china();
        if (flag)
            return -1;
    }
    return a1;
}

signed main() {
  long long pre = 2;
  long long now = 3;
  set<long long> sett;
  sett.insert(pre);
  sett.insert(now);
  while (now < 10000000000000000ll) {
    long long tmp = pre + now;
    sett.insert(tmp);
    // cout<<i<<' '<<now<<endl;
    pre=now;
    now=tmp;
  }
  // cout << sett.size() << endl;
  long long k;
  cin >> k;
  for (long long i = 0; i < k; i++) {
    cin >> ns[i] >> as[i];
  }
  long long n = realchina(k);
  // cin>>n;
  if (n==-1||flag==1) {
    cout << "Tankernb!" << endl;
  } else if (sett.find(n) == sett.end()) {
    cout << "Zgxnb!" << endl;
  } else {
    cout << "Lbnb!" << endl;
  }
  // for (auto &i:sett)cout<<i<<endl;
}