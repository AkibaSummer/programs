#include <bits/stdc++.h>
using namespace std;

int input[200005];

int n,fnum(0),znum(0),zeronum(0),
fupos,zpos,zeropos,zeroposs,
fpd(-1<<10),zpd(1<<10);
int pre;

void outp(int pos){
    cout<<2<<' '<<pos<<endl;
    if (pos==1)pre=2;
    else pre=1;
    for (int i=2;i<=n;i++){
        if (i==pos||i==pre)continue;
        cout<<1<<' '<<pre<<' '<<i<<endl;
        pre=i;
    }
}

void outp(int pos1,int pos2){
    cout<<1<<' '<<pos1<<' '<<pos2<<endl;
    cout<<2<<' '<<pos2<<endl;
    pre=1;
    if (pos1==pre||pos2==pre)pre++;
    if (pos2==pre||pos1==pre)pre++;
    for (int i=2;i<=n;i++){
        if (i==pos1||i==pos2||i==pre)continue;
        cout<<1<<' '<<pre<<' '<<i<<endl;
        pre=i;
    }
}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>input[i];
        if (input[i]>0) {
            ++znum;
        }
        else if(input[i]){
            ++fnum;
            if (input[i]>fpd){
                fupos=i;
                fpd=input[i];
            }
        }
        else {
            zeroposs=zeropos;
            zeropos=i;
            ++zeronum;
        }
    }
    if (fnum%2==1){
        if (zeronum){
            outp(fupos,zeropos);
        }
        else {
            outp(fupos);
        }
    }
    else {
        if (zeronum==1){
            outp(zeropos);
        }
        else outp(zeroposs);
    }
    return 0;
}