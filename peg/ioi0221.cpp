#include <cstdio>
#include <algorithm>
using namespace std;

long long n,setup, tsum[10005], fsum[10005], dp[10005];

int main()
{
	scanf("%lld%lld",&n,&setup);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld",&tsum[i],&fsum[i]);
		tsum[i] += tsum[i-1];
		fsum[i] += fsum[i-1];
	}
	
	int best = n;
	for (int i=n; i>0; i--)
	{
		dp[i] = (fsum[n]-fsum[i-1])*(setup+tsum[best]-tsum[i-1]) + dp[best+1];
		while  (best>i && (fsum[n]-fsum[i-1])*(setup+tsum[best-1]-tsum[i-1]) + dp[best] < dp[i])
		{
			best--;
			dp[i] = (fsum[n]-fsum[i-1])*(setup+tsum[best]-tsum[i-1]) + dp[best+1];
		}
	}
	printf("%lld\n",dp[1]);
}
