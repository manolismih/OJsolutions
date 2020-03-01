#include <cstdio>
#include <algorithm>
using namespace std;

int n, dp[5005][2];
char s[5005];

int main()
{
	scanf("%d%s",&n,s);
	
	for (int j=1; j<n; j++)
	{
		for (int i=n-2; i>=j; i--) dp[i][j%2]=0;
		for (int i=j-1; i>=0; i--)
			if (s[i]==s[j]) dp[i][j%2] = dp[i+1][(j-1)%2];
			else dp[i][j%2] = 1 + min(dp[i+1][j%2], dp[i][(j+1)%2]);
	}
	printf("%d\n",dp[0][(n-1)%2]);
}
