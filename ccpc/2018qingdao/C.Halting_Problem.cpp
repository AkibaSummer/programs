#include <cstdio>
#include <cstring>
char s[10];
int c[10005],g[10005],jmp[10005];
bool vis[10005][256];
#define add 'd'
#define beq 'e'
#define bne 'n'
#define blt 'l'
#define bgt 'g'
int main(){
	int T;
	scanf("%d",&T);
	int n,r=0;
	while(T--){
	  r=0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%s%d",s,&g[i]);
			c[i]=s[1];
			if(c[i]!=add)scanf("%d",&jmp[i]);
		}
		int flag=1;
		for(int i=1;i<=n&&flag;){
			switch(c[i]){
				case add:{
					r+=g[i];
					if(r>=256)r-=256;
					i++;
					break;
				}
				case beq:{
					if(vis[i][r]){
						flag=0;
						break;
					}
					vis[i][r]=1;
					if(r==g[i]){
						i=jmp[i];
					}else i++;
					break;
				}
				case bne:{
					if(vis[i][r]){
						flag=0;
						break;
					}
					vis[i][r]=1;
					if(r!=g[i]){
						i=jmp[i];
					}else i++;
					break;
				}
				case blt:{
					if(vis[i][r]){
						flag=0;
						break;
					}
					vis[i][r]=1;
					if(r<g[i]){
						i=jmp[i];
					}else i++;
					break;
				}
				case bgt:{
					if(vis[i][r]){
						flag=0;
						break;
					}
					vis[i][r]=1;
					if(r>g[i]){
						i=jmp[i];
					}else i++;
					break;
				}
			}
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}