#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for (auto&i:input)cin>>i;
    int summ=120000-input[n-1];
    int jz=100000;
    printf ("%d\n",n+1);
    printf("%d %d %d\n",1,n,summ);
    //printf ("%d\n",(input[n-1]+summ)%jz);
    for (int i=n-2;i>=0;i--){
        int addd=(input[i]+summ)/jz*jz+jz+i+1-(input[i]+summ);
        summ+=addd;
        printf("%d %d %d\n",1,i+1,addd);
        //printf("%d\n",(input[i]+summ)%jz);
    }
    printf("%d %d %d\n",2,n,jz);
}