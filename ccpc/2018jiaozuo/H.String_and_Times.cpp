#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N=200005;
struct node{int len,lnk,nx[26];}sa[N<<1];
int sz,last;
int deg[N<<1]={0},endsize[N<<1]={0};
void sam_init(){
	memset(sa[0].nx,0,sizeof(sa[0].nx));
	sa[sz=0].len=0;sa[sz].lnk=-1;
	endsize[sz]=0;
	deg[sz]=0;
	last=sz++;
}
int newnode(){
	endsize[sz]=0;
	deg[sz]=0;
	memset(sa[sz].nx,0,sizeof(sa[sz].nx));
	return sz++;
}
void sam_extend(char c){
	int p,x=c-'A',cur=newnode();sa[cur].len=sa[last].len+1;
	endsize[cur]=1;
	for(p=last;p+1&&!sa[p].nx[x];p=sa[p].lnk)sa[p].nx[x]=cur;
	if(p==-1)sa[cur].lnk=0;
	else{
		int q=sa[p].nx[x];
		if(sa[q].len==sa[p].len+1)sa[cur].lnk=q;
		else {
			int qw=newnode();sa[qw]=sa[q];sa[qw].len=sa[p].len+1;
			for(;p+1&&sa[p].nx[x]==q;p=sa[p].lnk)sa[p].nx[x]=qw;
			sa[q].lnk=sa[cur].lnk=qw;
		}
	}
	last=cur;
}

void debug(){
	printf("      ");
	for(int i=0;i<26;i++)printf(" %c",i+'a');
	puts("");
	for(int i=0;i<sz;i++){
		node &u=sa[i];
		printf("%d %d %2d ",i,u.len,u.lnk);
		for(int i=0;i<26;i++)printf("%d ",u.nx[i]);
		puts("");
	}
	puts("");
}
queue<int> Q;
char s[N];
long long res;int ml;
int main(){
	int l,r;
	while(~scanf("%s%d%d",s,&l,&r)){res=0;
		int slen=strlen(s);
		sam_init();
		for(int i=0;i<slen;i++)sam_extend(s[i]);
		//debug();
		for(int i=1;i<sz;i++){
			deg[sa[i].lnk]++;
		}
		for(int i=0;i<sz;i++)if(!deg[i])Q.push(i);
		int tmp;
		while(Q.size()){
			tmp=Q.front();Q.pop();
			if(!tmp)continue;
			endsize[sa[tmp].lnk]+=endsize[tmp];
			//printf("%2d %2d|%2d|\n",tmp,sa[tmp].len,endsize[tmp]);
			if(--deg[sa[tmp].lnk]==0)Q.push(sa[tmp].lnk);
		}
		//puts("");
		//return 0;
		for(int i=1;i<sz;i++){
			//printf("[%2d,%2d] |%2d|\n",sa[sa[i].lnk].len+1,sa[i].len,endsize[i]);
			if(l<=endsize[i]&&endsize[i]<=r){
				res+=sa[i].len-sa[sa[i].lnk].len;
			}
		}
		printf("%lld\n",res);
	}
	
	
}