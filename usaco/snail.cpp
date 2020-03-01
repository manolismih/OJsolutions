/*
ID:manolis2
PROG:snail
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n,b, moves[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
char pista[125][125];

int dfs(int y, int x, int kat) // 0 > , 1 < , 2 ^ , 3 v
{
	if (pista[y][x] != '.') return 0;
	pista[y][x] = '*';
	int ret;
	if (pista[y+moves[kat][0]][x+moves[kat][1]] == '.' || pista[y+moves[kat][0]][x+moves[kat][1]] == '*')
		ret = 1+dfs(y+moves[kat][0],x+moves[kat][1],kat);
	else if (kat==0 || kat==1) 
		ret = 1 + max(dfs(y+1,x,3), dfs(y-1,x,2));
	else  ret = 1 + max(dfs(y,x+1,0), dfs(y,x-1,1));
	pista[y][x] = '.';
	return ret;
}

int main()
{
	freopen("snail.in","r",stdin);
	freopen("snail.out","w",stdout);
	scanf("%d%d",&n,&b);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			pista[i][j] = '.';
	char c;
	for (int row,i=0; i<b; i++)
	{
		scanf(" %c%d",&c,&row);
		pista[row][c-'A'+1] = '#';
	}
	
	printf("%d\n",max(dfs(1,1,0), dfs(1,1,3)));
	return 0;
}

