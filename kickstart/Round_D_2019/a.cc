#include <bits/stdc++.h>
using namespace std;

int bitcount(int k){
    int ret=0;
    // cout<<k;
    for (ret=0;k;++ret){
        k&=(k-1);
    }
    // cout<<' '<<ret<<endl;
}

void slove(int t){
    int n, q;
    cin>>n>>q;
    vector<int>input(n);
    for (auto &i:input){
        cin>>i;
    }
    while (q--){
        int fodd=-1,eodd=-1,feven=-1,eeven=-1,xors=0;
        int p,v;
        cin>>p>>v;
        input[p]=v;
        for (int i=0;i<n;i++){
            xors^=input[i];
            if (bitcount(xors)&1){
                if (fodd==-1)fodd=i;
                eodd=i;
            }
            else {
                // if (feven==-1)feven=i;
                eeven=i;
            }
            // cout<<i<<' '<<eeven<<' '<<feven<<' '<<eodd<<' '<<fodd<<endl;
        
        }
        cout<<max(eeven-feven-1,eodd-fodd-1)<<" \n"[!q];
    }


}

int main(){
    int t;
    cin>>t;
    for (int ttt=1;ttt<=t;ttt++){
        cout<<"Case #"<<ttt<<": ";
        slove(ttt);
    }
}