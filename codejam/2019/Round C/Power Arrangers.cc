#include <bits/stdc++.h>
using namespace std;
int slove(){
    vector<string>orz(119);
    vector<int>cnt(5),flag(5,0);
    string want;

    for (int i=0;i<119;i++){
        cout<<i*5+1<<endl;
        fflush;
        char c;
        cin>>c;
        orz[i]=orz[i]+c;
        cnt[c-'A']++;        
    }
    for (int i=0;i<5;i++){
        if (cnt[i]==23){
            want=(char)(i+'A');
            flag[i]=1;
        }
        cnt[i]=0;
    }

    for (int i=0;i<119;i++){
        if (orz[i]==want){
            cout<<i*5+2<<endl;
            fflush;
            char c;
            cin>>c;
            orz[i]=orz[i]+c;
            cnt[c-'A']++;     
        }   
    }
    for (int i=0;i<5;i++){
        if (cnt[i]==5){
            want=want+(char)(i+'A');
            flag[i]=1;
        }
        cnt[i]=0;
    }

    for (int i=0;i<119;i++){
        if (orz[i]==want){
            cout<<i*5+3<<endl;
            fflush;
            char c;
            cin>>c;
            orz[i]=orz[i]+c;
            cnt[c-'A']++;     
        }   
    }
    for (int i=0;i<5;i++){
        if (cnt[i]==1){
            want=want+(char)(i+'A');
            flag[i]=1;
        }
        cnt[i]=0;
    }

    for (int i=0;i<119;i++){
        if (orz[i]==want){
            cout<<i*5+4<<endl;
            fflush;
            char c;
            cin>>c;
            orz[i]=orz[i]+c;
            cnt[c-'A']++;     
        }   
    }
    for (int i=0;i<5;i++){
        if (cnt[i]==0&&flag[i]==0){
            want=want+(char)(i+'A');
            flag[i]=1;
        }
        cnt[i]=0;
    }
    want=want+(char)(10-(want[0]-'A')-(want[1]-'A')-(want[2]-'A')-(want[3]-'A')+'A');
    cout<<want<<endl;
    fflush;
    char c;
    cin>>c;
    if (c=='N')return 1;
    else return 0;
}
int main(){
    int t,f;
    cin>>t>>f;
    for (int i=1;i<=t;i++){
        if (slove())return 0;
    }
}

/*
1 100
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
C
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
D
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E
E

A
A
A
A
A
A
B
B
B
B
B
B
C
C
C
C
C
C
D
D
D
D
D

A
A
B
B
C

A

*/