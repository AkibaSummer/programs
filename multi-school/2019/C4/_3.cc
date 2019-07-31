#include<bits/stdc++.h>
using namespace std;



void slove(){
    int n,k;
    scanf("%d %d",&n,&k);
    int num=n/k;
    if (n%2==0&&num%2==0){
        printf("yes\n");
        num/=2;
        int now=1;
        for (int i=1;i<=k;i++){
            for (int j=1;j<=num;j++){
                printf("%d %d ",now,n-now+1);
                now++;
            }
            puts("");
        }
    }
    else if (n%2==1&&num%2==1){
        printf("yes\n");
        int now=1;
        for (int i=1;i<=k;i++){
            for (int j=1;j<=(num-3)/2;j++){
                printf("%d %d ",now,n-now+1);
                now++;
            }
            int lp=(num-3)/2;

            /*
            xxxxxxx xxx xxx x xxx xxx x xxx xxx x xxx xxx x xxxxxxx
                  lp               (n+1)/2  (n+1)/2+(k-1)/4*3+1
             */
            if ((num-1)%12==0){
                if (i==1){
                    printf("%d %d %d ",(n+1)/2,lp+(n-1)/4*3+1,lp+(n-1)/4*3*3+3);
                }
                if (i%2==0){
                    int now = i/2;
                    printf("%d %d %d ",lp+(k/2-1)*3+2,);
                }  
            }
            puts("");
        }
    }
    else puts("no");
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        slove();
    }
}