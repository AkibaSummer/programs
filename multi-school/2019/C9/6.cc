#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

void slove(){
    int n;
    cin>>n;
    vector<int> input(n);
    int flag = 0;
    for (auto &i:input){
        cin>>i;
        if (i%10)flag=1;
    }
    if (flag){
        cout<<-1<<endl;
        return ;
    }
    else {
        sort(input.begin(),input.end());
        vector<int> tmp(10);
        int cnt=0;
        for (auto &i:input){
            tmp[i%100/10]=1;
            cnt=max(cnt,i);
        }
        int a1=0,a2=0,a5=0,a10=0;
        int minn=1000000000;
        for (a1=0;a1<=1;a1++){
            for (a2=0;a2<=3;a2++){
                for (a5=0;a5<=1;a5++){
                    vector<int> tmpp(20);
                    for (int i=0;i<=a1;i++){
                        for (int j=0;j<=a2;j++){
                            for (int k=0;k<=a5;k++){
                                tmpp[(i+j*2+k*5)%10]=1;
                            }
                        }
                    }
                    int ok=1,nowmaxx=0;
                    for (auto &i:input){
                        if (i>=100&&tmp[i%100/10+10]){
                            nowmaxx=max(nowmaxx,i/100-1+a1+a2+a5);
                        }
                        else {
                            nowmaxx=max(nowmaxx,i/100+a1+a2+a5);
                        }
                    }
                }
            }
        }
        // if (tmp[1])a1++;
        // if (tmp[2])a2++;
        // if (tmp[3])a1=1,a2=1;
        // if (tmp[4])a2=2;
        // if (tmp[5]){
        //     if (a1*1+a2*2!=5){
        //         a5=1;
        //     }
        // }
        // if (tmp[8])a5=1,a1=1,a2=max(a2,1ll);
        // if (tmp[9])a5=1,a2=max(a2,2ll);
        // if (tmp[7])a5=1,a2=max(a2,1ll);
        // if (tmp[6]){
        //     if (a5==0&&a1==0&&a2==2){
        //         a2++;
        //     }
        //     else {
        //         a5=1;
        //         a1=1;
        //     }
        // }
    }
}

signed main(){
    // fast();
    int tt;
    cin>>tt;
    while(tt--){
        slove();
    }
}