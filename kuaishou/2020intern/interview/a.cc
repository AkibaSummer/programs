#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  int data;
  node* next;
  int visited;
  node(int a, node* b, int c) {
    data = a;
    next = b;
    visited = c;
  }
};

int find(node* now) {
  if (now->visited == 1) {
    return 1;
  }
  now->visited = 1;
  if (now->next == 0) {
    return 0;
  } else {
    return find(now->next);
  }
}

int main() {
  // 1->2 2->3 3->4 4->2
  int n;
  cin >> n;
  int front;
  cin >> front;
  vector<pair<int, int>> input(n);
  map<int, node*> nodes;
  for (auto& i : input) {
    cin >> i.first >> i.second;
    if (!nodes.count(i.second)) {
      nodes[i.second] = new node(i.second, 0, 0);
      // cerr<<"new node"<<i.second<<endl;
    }
    if (!nodes.count(i.first)) {
      nodes[i.first] = new node(i.second, nodes[i.second], 0);
      // cerr<<"new node"<<i.first<<endl;
    } else {
      nodes[i.first]->next = nodes[i.second];
    }
  }
  if (find(nodes[front])) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  // for (auto &i:nodes){
  //   cout<<i.second->data<<' '<<i.second->visited<<' '<<i.second->next<<endl;
  // }
}
/*
4
1
1 2
2 3
3 4
4 5
*/