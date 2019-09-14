#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)

vector<int> getcards(string s) {
  vector<int> ret;
  for (auto &i : s) {
    if (i == 'A')
      ret.push_back(1);
    else if (i == '2')
      ret.push_back(2);
    else if (i == '3')
      ret.push_back(3);
    else if (i == '4')
      ret.push_back(4);
    else if (i == '5')
      ret.push_back(5);
    else if (i == '6')
      ret.push_back(6);
    else if (i == '7')
      ret.push_back(7);
    else if (i == '8')
      ret.push_back(8);
    else if (i == '9')
      ret.push_back(9);
    else if (i == '1')
      ret.push_back(10);
    else if (i == 'J')
      ret.push_back(11);
    else if (i == 'Q')
      ret.push_back(12);
    else if (i == 'K')
      ret.push_back(13);
  }
  return ret;
}

int getpoint(vector<int> &vec) {
  sort(vec.begin(), vec.end());
  
if (vec[0]==1&&vec[1]==10&&vec[2]==11&&vec[3]==12&&vec[4]==13){
  return 11000000;
}

  int isStraight = 1;
  for (int i = 1; i < 5; i++) {
    if (vec[i] != vec[i - 1]+1) {
      isStraight = 0;
      break;
    }
  }
  if (isStraight){
    return 10000000+vec[4];
  }

  if (vec[0]==vec[3]){
    return 9000000+vec[0]*100+vec[4];
  }
  if (vec[1]==vec[4]){
    return 9000000+vec[1]*100+vec[0];
  }

  if (vec[0]==vec[2]&&vec[3]==vec[4]){
    return 8000000+vec[0]*100+vec[3];
  }
  if (vec[0]==vec[1]&&vec[2]==vec[4]){
    return 8000000+vec[2]*100+vec[0];
  }

  if (vec[0]==vec[2]){
    return 7000000+vec[0]*100+vec[3]+vec[4];
  }
  if (vec[1]==vec[3]){
    return 7000000+vec[1]*100+vec[0]+vec[4];
  }
  if (vec[2]==vec[4]){
    return 7000000+vec[2]*100+vec[0]+vec[1];
  }

  if (vec[0]==vec[1]&&vec[2]==vec[3]){
    return 6000000+vec[2]*10000+vec[0]*100+vec[4];
  }
  if (vec[0]==vec[1]&&vec[3]==vec[4]){
    return 6000000+vec[3]*10000+vec[0]*100+vec[2];
  }
  if (vec[1]==vec[2]&&vec[3]==vec[4]){
    return 6000000+vec[3]*10000+vec[1]*100+vec[0];
  }

  if (vec[0]==vec[1]){
    return 5000000+vec[0]*1000+vec[2]+vec[3]+vec[4];
  }
  if (vec[1]==vec[2]){
    return 5000000+vec[1]*1000+vec[0]+vec[3]+vec[4];
  }
  if (vec[2]==vec[3]){
    return 5000000+vec[2]*1000+vec[0]+vec[1]+vec[4];
  }
  if (vec[3]==vec[4]){
    return 5000000+vec[3]*1000+vec[0]+vec[1]+vec[2];
  }

  return accumulate(vec.begin(), vec.end(), 0);
}

bool cmp(pair<int,string> a,pair<int,string> b){
  return a.first==b.first?a.second<b.second:a.first>b.first;
}

int main() {
  fast;
  int n;
  cin >> n;
  vector<pair<int, string>> input(n);
  for (auto &i : input) {
    string cards;
    cin >> i.second >> cards;
    vector<int> nowvec = getcards(cards);
    i.first=getpoint(nowvec);
  }
  sort(input.begin(),input.end(),cmp);
  // reverse(input.begin(),input.end());
  for (auto &i:input){
    // cout<<i.second<<' '<<i.first<<endl;
    cout<<i.second<<endl;
  }
}