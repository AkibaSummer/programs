#include <bits/stdc++.h>
using namespace std;

int q(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    int ret;
    cin>>ret;
    return ret;
}

int main(){
    int c=0,d=0;
    int ret=q(c,d);
    int ansa(0),ansb(0);
    for (int pos=29;pos>=0;pos--){
        if (ret>0){
            c|=1<<pos;
            d|=1<<pos;
            ret=q(c,d);
            if (ret<0){
                ansa|=1<<pos;
                d-=1<<pos;
                ret=q(c,d);
            }
        }
        else if (ret<0){
            c|=1<<pos;
            d|=1<<pos;
            ret=q(c,d);
            if (ret>0){
                ansb|=1<<pos;
                c-=1<<pos;
                ret=q(c,d);
            }
        }
        else if (ret==0){
            break;
        }
    }
    c=ansa;d=ansb;
    for (int pos=29;pos>=0;pos--){
        if (((c>>pos)%2)!=((d>>pos)%2)){
            continue;
        }
        else {
            if (q(c|(1<<pos),d)>0){
                continue;
            }
            else {
                ansa|=1<<pos;
                ansb|=1<<pos;
            }
        }
    }
    printf("! %d %d\n",ansa,ansb);
}