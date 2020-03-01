#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2000000000

int t,n,O2,N2,dp[2][22][80], oxygen, nitrogen, w;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d%d",&O2,&N2,&n);
		for (int i=0; i<22; i++)
			for (int j=0; j<80; j++)
				dp[0][i][j] = inf;
		dp[0][0][0]=0;
		
		for (int i=1; i<=n; i++)
		{
			scanf("%d%d%d",&oxygen,&nitrogen,&w);
			for (int j=0; j<=O2; j++)
				for (int k=0; k<=N2; k++)
					dp[i%2][j][k] = min(dp[(i-1)%2][j][k], w+dp[(i-1)%2][max(j-oxygen,0)][max(k-nitrogen,0)]);
		}
		printf("%d\n",dp[n%2][O2][N2]);
	}
	return 0;
}

