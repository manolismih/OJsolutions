#include <cstdio>
#include <algorithm>
using namespace std;

int n,m, pos[305], dp[305][35], sum[305];

int best(int from, int to)
{
	int middle = (from+to)/2;
	return sum[to]-sum[middle]-(to-middle)*pos[middle]
	+ (middle-from)*pos[middle] -sum[middle-1]+sum[from-1];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&pos[i]);
		sum[i] = sum[i-1] + pos[i];
	}
	
	for (int i=1; i<=n; i++) dp[i][1] = best(i,n);
	for (int p=2; p<=m; p++)
		for (int i=n; i>0; i--)
		{
			dp[i][p] = dp[i][1];
			for (int j=i; j<n; j++)
				dp[i][p] = min(dp[i][p],best(i,j)+dp[j+1][p-1]);
		}
	int ans = dp[1][m];
	printf("%d\n",ans);
	int loc=1;
	while (m>1)
		for (int j=loc; j<n; j++)
			if (best(loc,j) + dp[j+1][m-1] == dp[loc][m])
			{
				printf("%d\n",pos[(loc+j)/2]);
				loc = j+1;
				m--;
				break;
			}
	printf("%d\n",pos[(loc+n)/2]);
	return 0;
}
