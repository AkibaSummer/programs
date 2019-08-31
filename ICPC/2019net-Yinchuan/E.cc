#include <bits/stdc++.h>
using namespace std;

class trees {
public:
  trees *father;
  int nums[4];
  int size;
  trees *sons[5] = {0};
  trees() {
    size = 0;
    father = 0;
    memset(sons, 0, sizeof(sons));
  }
  trees(int n, trees *_father, trees *l, trees *r) {
    size = 1;
    father = _father;
    nums[1] = n;
    sons[1] = l;
    sons[2] = r;
  }
  ~trees() {
    for (int i = 1; i <= size + 1; i++) {
      if (sons[i] != 0)
        delete sons[i];
    }
  }
  void insert(int n) {
    nums[++size] = n;
    sort(nums + 1, nums + size + 1);
  }
  trees *push_up(int n) {
    if (n > nums[size]) {
      nums[++size] = n;
      sons[size + 1] = new trees(sons[size]->nums[3], this, sons[size]->sons[3],
                                 sons[size]->sons[4]);
      sons[size]->size -= 2;
      return this;
    } else {
      for (int i = 1; i <= size; i++) {
        if (nums[i] > n) {
          ++size;
          for (int j = size; j > i; j--) {
            nums[j] = nums[j - 1];
            sons[j + 1] = sons[j];
          }
          nums[i] = n;
          sons[i + 1] = new trees(sons[i]->nums[3], this, sons[i]->sons[3],
                                  sons[i]->sons[4]);
          sons[i]->size -= 2;
          return this;
        }
      }
    }
  }
  trees *getpos(int n) {
    if (n > nums[size])
      return sons[size + 1];
    for (int i = 1; i <= size; i++) {
      if (nums[i] > n)
        return sons[i];
    }
  }
  void output() {
    for (int i = 1; i <= size; i++)
      cout << nums[i] << " \n"[i == size];
    if (sons[1] == 0)
      return;
    for (int i = 1; i <= size + 1; i++)
      sons[i]->output();
  }
};

void insert(trees *&root, int ins) {
  trees *now = root;
  while (true) {
    if (now->size == 3) {
      int tmp = now->nums[2];
      if (now->father == 0) {
        trees *r = new trees(now->nums[3], 0, now->sons[3], now->sons[4]);
        trees *new_root = new trees(tmp, 0, now, r);
        root = new_root;
        r->father = new_root;
        now->father = new_root;
        now->size = 1;
        now = now->father;
      } else {
        now = now->father;
        now->push_up(tmp);
      }
    }
    if (now->sons[1] == 0) {
      now->insert(ins);
      return;
    }
    now->getpos(ins)->father = now;
    now = now->getpos(ins);
  }
}

void slove() {
  int n;
  cin >> n;
  trees *root = new trees;
  for (int i = 1; i <= n; i++) {
    int now;
    cin >> now;
    insert(root, now);
  }
  root->output();
  delete root;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":" << endl;
    slove();
  }
}