#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005],pos[1000005];
struct inv{
	int l,r;
}I[2000005];
bool cmp(inv x,inv y){
	return x.l<y.l;
}
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		int g=0;
		for(int i=1;i+1<=n;i+=2){
			I[++g].l=pos[i];
			I[g].r=pos[i+1];
			if(I[g].l>I[g].r)swap(I[g].l,I[g].r);
		}
		sort(I+1,I+1+g,cmp);
		//for(int i=1;i<=g;i++)printf("[%d %d]",I[i].l,I[i].r);
		//puts("");
		bool flag=1;
		for(int i=1;i<=g;){
			int mos=I[i].r;
			i++;
			while(i<=g&&I[i].l<mos){
				if(I[i].r>mos){
					flag=0;
					break;
				}
				i++;
			}
			if(!flag)break;
		}
		if(!flag){
			//puts("first");
			puts("No");
			continue;
		}
		g=0;
		for(int i=2;i+1<=n;i+=2){
			I[++g].l=pos[i];
			I[g].r=pos[i+1];
			if(I[g].l>I[g].r)swap(I[g].l,I[g].r);
		}
		sort(I+1,I+1+g,cmp);
		//for(int i=1;i<=g;i++)printf("[%d %d]",I[i].l,I[i].r);
		//puts("");
		for(int i=1;i<=g;){
			int mos=I[i].r;
			i++;
			while(i<=g&&I[i].l<mos){
				if(I[i].r>mos){
					flag=0;
					break;
				}
				i++;
			}
			if(!flag)break;
		}
		if(!flag){
			puts("No");
			continue;
		}
		puts("Yes");
	}
}