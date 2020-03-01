#include <cstdio>
#include <cstring>

int t,n,k;
long long dp[50][50];
bool open[50];

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d",&n,&k);
		n *= 2;
		memset(open,0,50);
		for (int pos,i=0; i<k; i++)
		{
			scanf("%d",&pos);
			open[pos] = true;
		}
		dp[n+1][0] = 1;
		for (int i=1; i<=n; i++) dp[n+1][i] = 0;
		for (int i=n; i>0; i--)
			for (int ao=0; ao<=n; ao++)
				dp[i][ao] = dp[i+1][ao+1] + (ao && !open[i] ? dp[i+1][ao-1] : 0);
				
		printf("%lld\n",dp[1][0]);
	}
}
