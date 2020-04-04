#include <bits/stdc++.h>
using namespace std;
int slove(){
    unsigned long long a,b;
    cout<<54<<endl;
    fflush;
    cin>>b;
    cout<<185<<endl;
    fflush;
    cin>>a;
    long long r1=0,r2=0,r3=0,r4=0,r5=0,r6=0;

    long long temp=0;
    for (int i=0;i<7;i++){
        temp|=1ll<<(30+i);
    }
    r6=a&temp;
    r6>>=30;

    temp=0;
    for (int i=0;i<8;i++){
        temp|=1ll<<(37+i);
    }
    r5=a&temp;
    r5>>=37;

    temp=0;
    for (int i=0;i<8;i++){
        temp|=1ll<<(46+i);
    }
    r4=a&temp;
    r4>>=46;

    temp=0;
    for (int i=0;i<8;i++){
        temp|=1ll<<(54+i);
    }
    r1=b&temp;
    r1>>=54;

    temp=0;
    for (int i=0;i<8;i++){
        temp|=1ll<<(27+i);
    }
    r2=b&temp;
    r2>>=27;

    temp=0;
    for (int i=0;i<8;i++){
        temp|=1ll<<(18+i);
    }
    r3=b&temp;
    r3>>=18;
    r3-=((r4<<4)+(r5<<1)+r6)>>9;
    cout<<r1<<' '<<r2<<' '<<r3<<' '<<r4<<' '<<r5<<' '<<r6<<endl;
    fflush;
    int in;
    cin>>in;
    return in;
}
int main(){
    int t,w;
    cin>>t>>w;
    while (t--){
        if (slove()==-1)return 0;
    }
}
/*
17592190257536
2305913516470566912

1 1
4618525082757627904
1801439864262385152
1

1 1
5501238925852672
216172786692648960
1
*/