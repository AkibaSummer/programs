#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<pair<int, pair<int, int>>> input(n);
  int maxr = 0;
  for (auto &i : input) {
    cin >> i.first >> i.second.first >> i.second.second;
    maxr = max(maxr, i.second.second);
  }
  sort(input.begin(), input.end(),
       [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
         return a.second.second > b.second.second;
       });
  vector<int> weight(maxr + 5);
  vector<vector<pair<int, pair<int, int>>>> ans(maxr + 5);
  for (int i = 0; i <= maxr; i++) {
    while (input.size() && input.back().second.second == i) {
      auto top = input.back();
      input.pop_back();
      if (top.first + weight[top.second.first] > weight[top.second.second]) {
        weight[top.second.second] = top.first + weight[top.second.first];
        ans[top.second.second] = ans[top.second.first];
        ans[top.second.second].push_back(top);
      }
    }
    if (i && weight[i - 1] > weight[i]) {
      weight[i] = weight[i - 1];
      ans[i] = ans[i - 1];
    }
  }
  cout << "Max weight is:" << weight[maxr] << endl;
  cout << "The interval selected are:" << endl;
  for (auto &i : ans[maxr]) {
    cout << "weight:" << i.first << " left:" << i.second.first
         << " right:" << i.second.second << endl;
    }
}
/*
5
1 0 3
1 2 5
2 4 7
3 6 9
4 8 11
*/