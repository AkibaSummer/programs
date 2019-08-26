#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
// #define int long long

inline void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int output[1005][1005];

void slove() {
    int a, b, n;
    cin >> n;
    output[0][0] = 8;
    output[0][1] = 9;
    output[0][2] = 1;
    output[0][3] = 13;
    output[1][0] = 3;
    output[1][1] = 12;
    output[1][2] = 7;
    output[1][3] = 5;
    output[2][0] = 0;
    output[2][1] = 2;
    output[2][2] = 4;
    output[2][3] = 11;
    output[3][0] = 6;
    output[3][1] = 10;
    output[3][2] = 15;
    output[3][3] = 14;
    // for (int i=0;i<n/4-1;i++){
    //     for (int j=0;j<(1<<i)*4;j++){
    //         for (int k=0;k<(1<<i)*4;k++){
    //             output[j+(1<<i)*4][k]=output[j][k]|(1<<(i*2+4));
    //             output[j][k+(1<<i)*4]=output[j][k]|(2<<(i*2+4));
    //             output[j+(1<<i)*4][k+(1<<i)*4]=output[j][k]|(3<<(i*2+4));
    //         }
    //     }
    // }
    int num=0;
    for (int i=0;i<n/4;i++){
        for (int j=0;j<n/4;j++){
            if (i==0&&j==0)continue;
            num++;
            // puts("233");
            for (int k=0;k<4;k++){
                for (int l=0;l<4;l++){
                    output[i*4+k][j*4+l]=output[k][l]|(num<<4);
                    // cout<<i*4+k<<' '<<j*4+l<<endl;
                }
            }
            // puts("233");
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<output[i][j]<<' ';
            // printf("%x ",output[i][j]);
        }
        cout<<endl;
    }
}

int main() {
    // fast();
    // int tt;
    // cin>>tt;
    // tt=1;
    // while(tt--){
    slove();
    // }
}