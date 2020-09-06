#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  node* next;
};
int main() {
  int n;
  cin >> n;
  node* root1 = new node{0, NULL};
  node* pre = root1;
  while (n--) {
    int input;
    cin>>input;
    pre -> next = new node{input,NULL};
    pre = pre->next;
  }
  node* tmp = root1;
  root1 = root1->next;
  delete tmp;

  int m;
  cin >> m;
  node* root2 = new node{0, NULL};
  pre = root2;
  while (m--) {
    int input;
    cin>>input;
    pre -> next = new node{input,NULL};
    pre = pre->next;
  }
  tmp = root2;
  root2 = root2->next;
  delete tmp;

  // cerr<<root1->val<<root2->val<<endl;
  while (root1!=NULL && root2!=NULL){
    if (root1->val==root2->val){
      cout<<root1->val<<' ';
      root1=root1->next;
      root2=root2->next;
    }
    else if (root1->val>root2->val){
      root1=root1->next;
    } else {
      root2=root2->next;
    }
  }
}