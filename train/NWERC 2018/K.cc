#include <cstdio>
#include <cstring>


char k[200],b[200],a[200];
int main() {
    int n,m;
    scanf("%d%d%s%s",&n, &m,k,b);
    for(int i=m-n;i<m;i++) {
        a[i]=k[i-m+n];
    }
    // puts(k);puts(b);
    for(int j=m-n;j>=0;j-=n) {
        for(int i=n-1;i>=0;i--) {
            if(j-n+i<0){
                break;
            }
            //printf("%c %c %c %d\n",b[j+i],k[i],a[j-n+i], b[j+i]-k[i]);
            k[i] = a[j-n+i] = (b[j+i] - k[i] + 26) % 26 + 'a';
            // printf("%c %c %c %d\n",b[j+i],k[i],a[j-n+i], b[j+i]-k[i]);
        }
    }



    puts(a);
}
/*
    5 16
    again
    pirpumsemoystoal

*/