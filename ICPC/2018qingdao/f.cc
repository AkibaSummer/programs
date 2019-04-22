#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
void schedule(int sche[][1025], int n)
{
	if (n == 2) {
		sche[0][0] = 0; sche[0][1] = 1;
		sche[1][0] = 1; sche[1][1] = 0;
		return ;
	}
	if(n & 1) {
		schedule(sche, n + 1);
	} else {
		int nrs1 = n >> 1, nrs1p1 = nrs1 + 1;
		schedule(sche, nrs1);
		if (nrs1 & 1) {
			for (int i = nrs1; i < n; i++) {
				for (int j = 0; j < nrs1p1; j++) {
					sche[i][j] = sche[i - nrs1][j] + nrs1;
				}
				sche[i][n - i] = i - nrs1;
				sche[i - nrs1][n - i] = i;
			}
			for (int i = 0; i < nrs1; i++) {
				for (int j = nrs1 + 1; j < n; j++) {
					sche[i][j] = (i + j - nrs1) % nrs1 + nrs1;
					sche[i + nrs1][j] = (i - j + n) % nrs1;
				}
			}
		}else {
			for (int i = 0; i < nrs1; i++) {
				for (int j = nrs1; j < n; j++) {
					sche[i][j] = sche[i][j - nrs1] + nrs1;
				}
				memcpy(sche[i + nrs1], sche[i] + nrs1, n << 1);
				memcpy(sche[i + nrs1] + nrs1, sche[i], n << 1);
			}
		}
	}
}

void schedule_print (int **sche, int n)
{
    using std::cout;
    using std::endl;
    cout << "id      |";
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << "day " << std::setw(4) << i << "|";
        }
        for (int j = 0; j < n; j++) {
            cout << std::setw(4) << sche[j][i] << " ";
        }
        cout << endl;
        if (!i) {
            cout << "---------";
            for (int j = 0; j < n; j++) {
                cout << "-----";
            }
            cout << endl;
        }
    }
}
int a[1025][1025];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		// 1000&111
		int g=1;
		while((n&1)==0){
			g<<=1;
			n>>=1;
		}
		schedule(a, g);
		for(int i=0;i<g;i++){
			for(int j=0;j<i;j++){
				swap(a[i][j],a[j][i]);
			}
		}
		//printf("gn%d %d\n",g,n);
		if(g-1<k)puts("Impossible");
		else{
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=g;k++){
						printf("%d%s",a[i][k-1]+g*(j-1)+1,(j*k==n*g)?"\n":" ");
					}
				}
			}
		}
	}
}