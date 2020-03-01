#include <cstdio>

int rows,cols,q,ans,pista[15][100005], dir[5][2]={{1,0},{0,1},{-1,0},{0,-1},{0,0}};

bool check(int r, int c)
{
	for (int i=0; i<4; i++)
		if (pista[r+dir[i][0]][c+dir[i][1]] > pista[r][c]) return false;
	return true;
}

int main()
{
	freopen("janitorin.txt","r",stdin);
	freopen("janitorout.txt","w",stdout);
	scanf("%d%d%d",&rows,&cols,&q);
	for (int r=2; r<=rows+1; r++)
		for (int c=2; c<=cols+1; c++)
		{
			scanf("%d",&pista[r][c]);
			pista[r][c]++;
		}
		
	for (int r=2; r<=rows+1; r++)
		for (int c=2; c<=cols+1; c++) ans += check(r,c);
	printf("%d\n",ans);		
	
	for (int r,c,neo, i=0; i<q; i++)
	{
		scanf("%d%d%d",&r,&c,&neo);
		r++, c++, neo++;
		for (int i=0; i<5; i++) ans -= check(r+dir[i][0], c+dir[i][1]);
		pista[r][c] = neo;
		for (int i=0; i<5; i++) ans += check(r+dir[i][0], c+dir[i][1]);	
		printf("%d\n",ans);
	}
}
