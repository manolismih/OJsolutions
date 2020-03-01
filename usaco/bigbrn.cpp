/*
ID:manolis2
PROG:bigbrn
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n,t,apantisi=1, dp[1005][1005];

int main()
{
	freopen("bigbrn.in","r",stdin);
	freopen("bigbrn.out","w",stdout);
	scanf("%d%d",&n,&t);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dp[i][j]=1;
			
	for (int y,x,i=0; i<t; i++)
	{
		scanf("%d%d",&y,&x);
		dp[y][x]=0;
	}
	
	for (int y=n; y; y--)
		for (int x=n; x; x--)
			if (dp[y][x])
			{
				dp[y][x] = 1 + min({dp[y+1][x], dp[y][x+1], dp[y+1][x+1]});
				if (dp[y][x] > apantisi) apantisi = dp[y][x];
			}
	printf("%d\n",apantisi);
	return 0;
}

