#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
      int n;
      cin>>n;
      vector<int> input(n+1);
      for (int i=0;i<2*n;i++){
          int tmp;
          cin>>tmp;
          if (input[tmp]==0){
              cout<<tmp<<' ';
              input[tmp]++;
          }
      }
      cout<<endl;
  }
}