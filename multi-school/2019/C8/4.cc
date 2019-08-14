#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void puts32(int x,int y,int s,int t){
    if (s==1&&t==6){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+3<<' '<<y+2<<endl;
    }
    else if (s==6&&t==1){
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+1<<endl;
    }
}

void puts42(int x,int y,int s,int t){
    if (s==1&&t==8){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+4<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+4<<' '<<y+2<<endl;
    }
    else if (s==8&&t==1){
        cout<<x+4<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+4<<' '<<y+1<<endl;
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+1<<endl;
    }
}

void puts52(int x,int y,int s,int t){
    if (s==1&&t==10){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+5<<' '<<y+1<<endl;
        cout<<x+4<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+4<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+5<<' '<<y+2<<endl;
    }
    else if (s==10&&t==1){
        cout<<x+5<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+4<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+4<<' '<<y+2<<endl;
        cout<<x+5<<' '<<y+1<<endl;
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+1<<endl;
    }
}

void puts33(int x,int y,int s,int t){
    if (s==1&&t==9){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+3<<endl;
    }
    else if (s==9&&t==1){
        cout<<x+3<<' '<<y+3<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+3<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+3<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+1<<endl;        
    }
}

void puts23(int x,int y,int s,int t){
    if (s==1&&t==6){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+3<<endl;
    }
    else if (s==6&&t==1){
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+1<<endl;
    }
}

void puts24(int x,int y,int s,int t){
    if (s==1&&t==8){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+1<<' '<<y+4<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+4<<endl;
    }
    else if (s==8&&t==1){
        cout<<x+2<<' '<<y+4<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+4<<endl;
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+1<<endl;
    }
}

void puts25(int x,int y,int s,int t){
    if (s==1&&t==10){
        cout<<x+1<<' '<<y+1<<endl;
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+1<<' '<<y+5<<endl;
        cout<<x+2<<' '<<y+4<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+4<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+5<<endl;
    }
    else if (s==10&&t==1){
        cout<<x+2<<' '<<y+5<<endl;
        cout<<x+1<<' '<<y+3<<endl;
        cout<<x+2<<' '<<y+1<<endl;
        cout<<x+1<<' '<<y+2<<endl;
        cout<<x+1<<' '<<y+4<<endl;
        cout<<x+2<<' '<<y+2<<endl;
        cout<<x+2<<' '<<y+4<<endl;
        cout<<x+1<<' '<<y+5<<endl;
        cout<<x+2<<' '<<y+3<<endl;
        cout<<x+1<<' '<<y+1<<endl;
    }
}

void putsf23(int x,int y){
    cout<<x+2<<' '<<y+2<<endl;
    cout<<x+1<<' '<<y+3<<endl;
    cout<<x+2<<' '<<y+1<<endl;
    cout<<x+1<<' '<<y+2<<endl;
    cout<<x+2<<' '<<y+3<<endl;
    cout<<x+1<<' '<<y+1<<endl;
}

void putsf33(int x,int y){
    cout<<x+3<<' '<<y+2<<endl;
    cout<<x+2<<' '<<y+1<<endl;
    cout<<x+1<<' '<<y+3<<endl;
    cout<<x+2<<' '<<y+2<<endl;
    cout<<x+3<<' '<<y+1<<endl;
    cout<<x+3<<' '<<y+3<<endl;
    cout<<x+1<<' '<<y+2<<endl;
    cout<<x+2<<' '<<y+3<<endl;
    cout<<x+1<<' '<<y+1<<endl;
}

void slove(){
    int n,m;
    cin>>n>>m;
    if (n==1&&m==1){
        cout<<"YES"<<endl;
        cout<<"1 1"<<endl;
    }
    else if (n==1||m==1){
        cout<<"NO"<<endl;
    }
    else if (n==2&&m==2){
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        if (n==2){
            for (int i=0;i<m/3-1;i++){
                puts23(0,i*3,1,6);
            }
            if (m%3==0)puts23(0,(m/3-1)*3,1,6);
            if (m%3==1)puts24(0,(m/3-1)*3,1,8);
            if (m%3==2)puts25(0,(m/3-1)*3,1,10);
        }
        else {
            if (m%2==1){
                for (int i=0;i<m/2-1;i++){
                    if (i%2==0){
                        for (int j=0;j<n/3-1;j++){
                            puts32(j*3,i*2,1,6);
                        }
                        if (n%3==0)puts32((n/3-1)*3,i*2,1,6);
                        if (n%3==1)puts42((n/3-1)*3,i*2,1,8);
                        if (n%3==2)puts52((n/3-1)*3,i*2,1,10);                        
                    }
                    else {
                        if (n%3==0)puts32((n/3-1)*3,i*2,6,1);
                        if (n%3==1)puts42((n/3-1)*3,i*2,8,1);
                        if (n%3==2)puts52((n/3-1)*3,i*2,10,1);  
                        for (int j=n/3-1-1;j>=0;j--){
                            puts32(j*3,i*2,6,1);
                        }
                    }
                }
                if ((m/2-1)%2==0){
                    for (int i=0;i<n/2-1;i++){
                        puts23(i*2,(m/2-1)*2,1,6);
                    }
                    if (n%2==0){
                        puts23((n/2-1)*2,(m/2-1)*2,1,6);
                    }
                    else puts33((n/2-1)*2,(m/2-1)*2,1,9);
                }
                else {
                    if (n%2==0){
                        for (int i=n/2-1;i>=0;--i){
                            putsf23(i*2,(m/2-1)*2);
                        }
                    }
                    else {
                        for (int i=n/2-1;i>=1;--i){
                            putsf23(i*2+1,(m/2-1)*2);
                        }
                        putsf33(0,(m/2-1)*2);
                    }
                }
            }
            else {
                for (int i=0;i<m/2;i++){
                    if (i%2==0){
                        for (int j=0;j<n/3-1;j++){
                            puts32(j*3,i*2,1,6);
                        }
                        if (n%3==0)puts32((n/3-1)*3,i*2,1,6);
                        if (n%3==1)puts42((n/3-1)*3,i*2,1,8);
                        if (n%3==2)puts52((n/3-1)*3,i*2,1,10);                        
                    }
                    else {
                        if (n%3==0)puts32((n/3-1)*3,i*2,6,1);
                        if (n%3==1)puts42((n/3-1)*3,i*2,8,1);
                        if (n%3==2)puts52((n/3-1)*3,i*2,10,1);  
                        for (int j=n/3-1-1;j>=0;j--){
                            puts32(j*3,i*2,6,1);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        slove();
    }
}