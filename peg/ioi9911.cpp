#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 10000

int n,v, beauty[105][105], dp[105][105]; //dp[flowers][vases]

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&v);
	for (int i=0; i<n; i++)
		for (int j=0; j<v; j++)
			scanf("%d",&beauty[i][j]);
			
	for (int flower=0; flower<n; flower++) dp[flower][v] = -inf;
	for (int vase=v-1; vase>=0; vase--)
		for (int flower=n-1; flower>=0; flower--)
			dp[flower][vase] = max(dp[flower][vase+1], beauty[flower][vase] + dp[flower+1][vase+1]);
			
	printf("%d\n",dp[0][0]);
	int flower=0, vase=0;
	while (flower<n && vase<v)
		if (dp[flower][vase] == beauty[flower][vase] + dp[flower+1][vase+1]) 
		{
			printf("%d ",vase+1);
			flower++, vase++;
		}
		else vase++;		
	/*
	dp(flower,vase) = max{dp(flower,vase+1), beauty[flower][vase] + dp(flower+1,vase+1)}
	dp(flower,v) = -inf
	dp(n,vase) = 0
	*/
}

