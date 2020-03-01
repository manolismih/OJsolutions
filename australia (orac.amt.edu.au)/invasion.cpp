#include <cstdio>

int r,c, amatrix[300][300];
char pista[1005][1005];

int main()
{
	freopen("invin.txt","r",stdin);
	freopen("invout.txt","w",stdout);
	scanf("%d%d",&r,&c);
	for (int y=1; y<=r; y++)
		for (int x=1; x<=c; x++)
			scanf(" %c",&pista[y][x]);
	
	for (int y=0; y<=r+1; y++)
	{
		pista[y][0] = pista[y][1];
		pista[y][c+1] = pista[y][c];
	}
	for (int x=0; x<=c+1; x++)
	{
		pista[0][x] = pista[1][x];
		pista[r+1][x] = pista[r][x];
	}
	
	for (int y=1; y<=r; y++)
		for (int x=1; x<=c; x++)
		{
			char a=pista[y][x], b=pista[y-1][x], c=pista[y+1][x], d=pista[y][x+1], e=pista[y][x-1];
			amatrix[a][b] = amatrix[b][a] = 1;
			amatrix[a][c] = amatrix[c][a] = 1;
			amatrix[a][d] = amatrix[d][a] = 1;
			amatrix[a][e] = amatrix[e][a] = 1;
		}
		
	int ans=0;
	for (int y='a'; y<='z'; y++)
	{
		amatrix[y][y]=1;
		int sum=0;
		for (int x='a'; x<='z'; x++) sum += amatrix[y][x];
		if (sum>ans) ans=sum;
	}
	printf("%d\n",ans-1);
	return 0;
}

