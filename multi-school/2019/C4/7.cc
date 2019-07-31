#include <bits/stdc++.h>
using namespace std;

int input[35];

int k[]={0,
    1,0,1,0,
    0,1,0,1,
    1,0,1,0,
    0,1,0,1
};

void slove(){
    int pos;
    for (int i=1;i<=16;i++){
        cin>>input[i];
        if (input[i]==0){
            pos=i;
        }
    }
    int sum=0;
    for (int i=1;i<=16;i++){
        for (int j=i+1;j<=16;j++){
            if (input[i]>input[j])sum++;
        }
    }
    if ((sum&1)==(k[pos]&1)){        
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        slove();
    }
}