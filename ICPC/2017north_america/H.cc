#include <cstdio>
char mp[105][105];
int mmp[105][105];
int vecx[]={
	1,1,1,-1,-1,-1,0,0
};

int vecy[]={
	1,0,-1,1,0,-1,1,-1
};

void clrs(int x,int y){
	if(mp[x][y]!='#')return ;
	mp[x][y]=' ';
	for(int i=0;i<7;i++){
		int nx=x+vecx[i],ny=y+vecy[i];
		clrs(nx,ny);
	}
}

int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
            if (mp[i][j]=='#'){
			    clrs(i,j);
                cnt++;
            }
		}
	}
	printf("%d\n",cnt);
}

/*
12 12
.##########.
#..........#
#..#...##..#
#.##..#..#.#
#......#.#.#
#....#..#..#
#...#.#....#
#..#...#...#
.#..#.#....#
#....#.....#
#.........#.
.#########..

 */