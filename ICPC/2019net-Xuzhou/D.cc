#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)


void preKMP(const char x[],int m,int kmpNext[]){
  int i,j;
  j=kmpNext[0]=-1;
  i=0;
  while(i<m){
    while(-1!=j && x[i]!=x[j])j=kmpNext[j];
    if (x[++i]==x[++j])kmpNext[i]=kmpNext[j];
    else kmpNext[i]=j;
  }
}

int Next[100010];
int KMP_Count(const char x[],int m,const char y[],int n){
  int i,j;
  int ans=0;
  preKMP(x,m,Next);
  i=j=0;
  while(i<n){
    while(-1!=j&&y[i]!=x[j])j=Next[j];
    i++;j++;
    if (j>=m){
      ans++;
      j=Next[j];
    }
  }
    return ans;
}

int judge(string &a,string &b){
  return KMP_Count(a.c_str(),a.size(),b.c_str(),b.size());
}

int main(){
  fast;
  string s;
  cin>>s;
  int T;
  cin>>T;
  while(T--){
    string t;
    cin>>t;
    if (t.length()==s.length()){
      if (s==t){
        cout<<"jntm!"<<endl;
      }
      else {
        cout<<"friend!"<<endl;
      }
    }
    else if (t.length()>s.length()){
      if (judge(s,t)){
        cout<<"my teacher!"<<endl;
      }
      else {
        cout<<"senior!"<<endl;
      }
    }
    else {
      if (judge(t,s)){
        cout<<"my child!"<<endl;
      }
      else {
        cout<<"oh, child!"<<endl;
      }
    }
  }

}