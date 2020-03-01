#include <cstdio>
#include <algorithm>
using namespace std;

int r,c, dp[505][505], sum[505][505], grami[505][505];

inline int s(int from, int to, int grames)
{
	return sum[grames][to] - sum[grames][from-1];
}

int main()
{
	while (scanf("%d%d",&r,&c) && r)
	{
		for (int y=1; y<=r; y++)
			for (int x=1; x<=c; x++)
			{
				scanf("%d",&grami[y][x]);
				grami[y][x] += grami[y][x-1];
			} 
		for (int y=1; y<=r; y++)
			for (int x=1; x<=c; x++)
			{
				scanf("%d",&sum[y][x]);
				sum[y][x] += sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1];
			}
			
		
		dp[1][1] = max(sum[1][1],grami[1][1]);
		for (int x=2; x<=c; x++) dp[1][x] = max(grami[1][x], dp[1][x-1]+s(x,x,1));
		
		for (int y=2; y<=r; y++)
			for (int x=1; x<=c; x++)
			{
				dp[y][x] = dp[y-1][x] + grami[y][x];
				for (int i=0; i<x; i++) dp[y][x] = max(dp[y][x], dp[y][i]+s(i+1,x,y));
			}
		printf("%d\n",dp[r][c]);
	}
}
