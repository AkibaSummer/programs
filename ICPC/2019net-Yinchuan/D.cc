#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int visited[15];

double getans(int now, int n) {
  if (now==n+1)return 0;
  if (now==n&&visited[now]==1)return 1;
  else if (now==n&&visited[now]==0)return 0;
  if (visited[now]==0){
    visited[now]=1;
    getans(now+1,n);
    visited[now]=0;
  }
  else {
    double ret=0;
    for (int i=1;i<=n;i++){
      if (!visited[now]==0){
        visited[now]=1;
        ret+=getans(now+1,n);
        visited[now]=0;
      }
    }
    ret/=n-now+1;
    return ret;
  }
}
double gett(int n){
  double ret=0;
  for (int i=1;i<=n;i++){
    visited[i]=1;
    ret+=getans(2,n);
    visited[i]=0;
  }
  ret/=n;
  return ret;
}
int main() {
  // for (int i = 2; i <= 3; i++) {
  //   memset(visited,0,sizeof(visited));
  //   cout << i << ' ' << gett(i) << endl;
  // }
    cout << 6 << ' ' << gett(3) << endl;
}