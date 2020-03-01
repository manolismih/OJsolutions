#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2000000000

int n,k, s[2000005], dp[2000005], ans=-inf;

int main()
{
	freopen("scrabble1d.in","r",stdin);
	freopen("scrabble1d.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&s[i]);
		s[i] += s[i-1];
	}
	for (int i=n+1; i>n-k+1; i--)
		dp[i] = -inf;
		
	for (int i=n-k+1; i>0; i--)
		dp[i] = max(dp[i+1],s[i+k-1]-s[i-1]);
		
	for (int i=1; i<=n-k+1; i++)
		ans = max(ans,s[i+k-1]-s[i-1] + dp[i+k]);
	printf("%d\n",ans);
	return 0;
}
