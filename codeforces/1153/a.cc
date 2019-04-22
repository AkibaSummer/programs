#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    int minn=0x7fffffff,minpos;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if (a>t){
            if (a<minn){
                minn=a;
                minpos=i+1;
            }
        }
        else {
            while (a<t) a+=b;
            if (a<minn){
                minn=a;
                minpos=i+1;
            }
        }
    }
    cout<<minpos<<endl;
}