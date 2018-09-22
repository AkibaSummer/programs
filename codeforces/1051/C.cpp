#include <bits/stdc++.h>
using namespace std;


int num[105];
int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for(auto&i:input){
        cin>>i;
        num[i]++;
    }
    int k(0),pos(0);
    for (int i=1;i<=100;i++){
        if (num[i]==1)k++;
        if (num[i]>2)pos=i;
    }
    if ((k%2==1)&&(pos==0))cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        if (k%2==0){
            k/=2;
            for (auto i:input){
                if (k&&(num[i]==1)){
                    k--;
                    cout<<"A";
                }
                else cout<<"B";
            }
        }
        else {
            k/=2;
            for (auto i:input){
                if (i==pos){
                    cout<<'A';
                    pos=0;
                }
                else if ((num[i]==1)&&k){
                    k--;
                    cout<<"A";
                }
                else cout<<"B";
            }
        }
    }
}