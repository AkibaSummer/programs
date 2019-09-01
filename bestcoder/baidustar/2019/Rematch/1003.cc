#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int INF = 1 << 30;
const int mod = 1000000007;
int error(int x = 1) { return error(x + 1); }

class tree {
public:
  int id = 0;
  int weight = 0;
  int minn = INF, num = 0;
  // int l->minn = INF, l->num = 0;
  // int r->minn = INF, r->num = 0;
  tree *l = 0;
  tree *r = 0;
  tree *father = 0;
  tree(int _id) { id = _id; }
  ~tree() {
    if (l)
      delete l;
    if (r)
      delete r;
  }
  void dfs() {
    num = 1;
    minn = id;
    if (l) {
      l->dfs();
      num += l->num;
      minn = min(minn, l->minn);
    }
    if (r) {
      r->dfs();
      num += r->num;
      minn = min(minn, r->minn);
    }
  }
  void dfs2(int _l, int _r) {
    if (_l == _r)
      weight = _l;
    else if (l == 0) {
      if (r->minn > id) {
        weight = _l;
        r->dfs2(_l + 1, _r);
      } else {
        weight = _r;
        r->dfs2(_l, _r - 1);
      }
    } else if (r == 0) {
      if (l->minn > id) {
        weight = _l;
        l->dfs2(_l + 1, _r);
      } else {
        weight = _r;
        l->dfs2(_l, _r - 1);
      }
    } else if (id < l->minn && id < r->minn) {
      if (l->num < r->num || (l->num == r->num) && l->minn < r->minn) {
        weight = _l + l->num;
        l->dfs2(_l, _l + l->num - 1);
        r->dfs2(_l + l->num + 1, _r);
      } else {
        weight = _l + r->num;
        l->dfs2(_l + r->num + 1, _r);
        r->dfs2(_l, _l + r->num - 1);
      }
    } else if (l->minn < r->minn && l->minn < id) {
      weight = _l + l->num;
      l->dfs2(_l, _l + l->num - 1);
      r->dfs2(_l + l->num + 1, _r);
    } else {
      weight = _l + r->num;
      l->dfs2(_l + r->num + 1, _r);
      r->dfs2(_l, _l + r->num - 1);
    }
  }
};

void slove() {
  int n;
  cin >> n;
  vector<tree *> nodes(n), fathers(n);
  for (int i = 1; i <= n; i++) {
    nodes[i - 1] = new tree(i);
  }
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    if (l)
      nodes[l - 1]->father = nodes[i - 1];
    if (r)
      nodes[r - 1]->father = nodes[i - 1];
    if (l)
      nodes[i - 1]->l = nodes[l - 1];
    if (r)
      nodes[i - 1]->r = nodes[r - 1];
  }
  tree *root;
  for (int i = 0; i < n; i++)
    if (nodes[i]->father == 0) {
      root = nodes[i];
      break;
    }
  root->dfs();
  root->dfs2(1, n);
  long long ans = 0, tmp = 1;
  for (int i = 0; i < n; i++) {
    tmp = tmp * 233 % mod;
    ans = (ans + ((i + 1) ^ nodes[i]->weight) % mod * tmp % mod) % mod;
  }
  cout << ans << endl;
  delete root;
}

signed main() {
  fast;
  long long t;
  cin >> t;
  while (t--) {
    slove();
  }
}