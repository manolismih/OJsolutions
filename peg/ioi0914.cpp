#include <cstdio>

int r,c, memo[51][51][51][51], s[51][51][51][51], raisins[51][51];
bool vmemo[51][51][51][51], vsum[51][51][51][51];

int sum(int y1, int x1, int y2, int x2)
{
	if (vsum[y1][x1][y2][x2]) return s[y1][x1][y2][x2];
	vsum[y1][x1][y2][x2] = true;
	int ret=0;
	for (int y=y1; y<=y2; y++)
		for (int x=x1; x<=x2; x++)
			ret += s[y][x][y][x];
	return s[y1][x1][y2][x2] = ret;
}

int best(int y1, int x1, int y2, int x2)
{
	if (vmemo[y1][x1][y2][x2]) return memo[y1][x1][y2][x2];
	vmemo[y1][x1][y2][x2] = true;
	if (y1==y2 && x1==x2) return 0;
	int ret=2000000000;
	for (int y=y1; y<y2; y++)
		if (best(y1,x1,y,x2) + best(y+1,x1,y2,x2) < ret) ret = best(y1,x1,y,x2) + best(y+1,x1,y2,x2);
	for (int x=x1; x<x2; x++)
		if (best(y1,x1,y2,x) + best(y1,x+1,y2,x2) < ret) ret = best(y1,x1,y2,x) + best(y1,x+1,y2,x2);
	return memo[y1][x1][y2][x2] = ret+sum(y1,x1,y2,x2);
}

int main()
{
	scanf("%d%d",&r,&c);
	for (int y=0; y<r; y++)
		for (int x=0; x<c; x++)
			scanf("%d",&s[y][x][y][x]);
	printf("%d\n",best(0,0,r-1,c-1));
	return 0;
}

