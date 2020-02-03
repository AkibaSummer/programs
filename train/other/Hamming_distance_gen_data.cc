#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)

void output(vector<int> &vec) {
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << (i == vec.size() - 1 ? endl : " ");
  }
}
void randpos(vector<int> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    auto ran = rand() % vec.size();
    swap(vec[i], vec[ran]);
  }
  output(vec);
}

void gen1(int n) {
  vector<bool> vec(65536, false);
  while (n--) {
    int now = rand() % 65536;
    while (vec[now]) {
      now = rand() % 65536;
    }
    vec[now] = true;
  }
  vector<int> generated;
  for (int i = 0; i < 65536; i++) {
    if (vec[i]) {
      generated.push_back(i);
    }
  }
  randpos(generated);
}

void gen2(int n) {
  int now = 0;
  vector<int> gen;
  while (n <= 65536) {
    gen.push_back(now);
    now = (now + n);
  }
  randpos(gen);
}

vector<int> vecc;

void ins(int num, int s, int now) {
  if (num == 0) {
    vecc.push_back(now);
    return;
  }
  for (int i = s; i <= 16 - num; i++) {
    ins(num - 1, i + 1, now | (1 << i));
  }
}

void gen3() {
  ins(1,0,0);
  // ins(2,0,0);
  cerr<<vecc.size()<<endl;
  int now = 0;
  vector<bool>vec(65536,true);
  for (int i=0;i<65536;i++){
    if (vec[i]){
      for (int j=0;j<vecc.size();j++){
        vec[i^vecc[j]]=false;
      }
    }
  }
  vector<int> generated;
  for (int i = 0; i < 65536; i++) {
    if (vec[i]&&rand()%2) {
      generated.push_back(i);
    }
  }
  randpos(generated);
}

int main() {
  srand(time(0));
  // gen1(32768);
  // gen2(0x0821);
  gen3();
}