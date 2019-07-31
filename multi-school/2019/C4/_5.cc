#include <bits/stdc++.h>
using namespace std;

int gettarget(int n,int type){
    int q=n/64;
    int w=n%64/8;
    int e=n%8;
    if (type==0){
        if (q) return (q-1)*64+(w+1)*8+e;
        else return -1;
    }
    if (type==1){
        if (w) return q*64+(w-1)*8+(e+1);
        else return -1;
    }
    if (type==2){
        if (e) return (q+1)*64+w*8+(e-1);
        else return -1;
    }
}

template<typename T, int N>
struct matrixX
{
    T m[N][N];
};
const int N = 513;
typedef matrixX<long long, N> matrix;
matrix onestep;
const long long mod=1e9+9;

matrix idt;

//3*3的矩阵乘法
void mat(const matrix &a,const matrix &b,matrix &c)
{
    // matrix c;
    for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
    {
        c.m[i][j]=0;
        for (int k=0;k<N;k++) c.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
        c.m[i][j]%=mod;
    }
    // return ;
}
//矩阵快速幂 b^n

void doexpmat(matrix b, matrix &a,int n)
{
    static matrix tmp;
    a= idt;
    while(n)
    {
        tmp = a;
        if (n&1) mat(tmp,b,a);
        n=n>>1;
        tmp = b;
        mat(tmp,tmp,b);
    }
    return ;
}

matrix ret1,ret2;
void slove(long long k,int p){
}

int main(){
    for (int i=0;i<=512;i++){
        idt.m[i][i]=1;
        onestep.m[i][gettarget(i,0)]++;
        onestep.m[i][gettarget(i,1)]++;
        onestep.m[i][gettarget(i,2)]++;
    }
    long long k;int p;
    while (~scanf("%lld%d",&k,&p)){
        cout<<"23333"<<endl;
    //     cout<<"2333"<<endl;
        doexpmat(onestep,ret1,k);
    //     cout<<"233"<<endl;
        cout<<ret1.m[8*64][8*64]<<endl;
    }

        cout<<"23333"<<endl;
}