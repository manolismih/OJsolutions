#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t,n,m, dp[2][2005];
char s1[2005], s2[2005];

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%s%s",s1,s2);
		n = strlen(s1);
		m = strlen(s2);
		dp[n%2][m] = 0;
		
		for (int j=0; j<m; j++) dp[n%2][j] = m-j; //i=n
		for (int i=n-1; i>=0; i--)				  //i=0 to n-1
		{
			dp[i%2][m] = n-i;
			for (int j=m-1; j>=0; j--)
				if (s1[i]==s2[j]) dp[i%2][j] = dp[(i+1)%2][j+1];
				else dp[i%2][j] = 1 + min({dp[(i+1)%2][j+1], dp[(i+1)%2][j], dp[i%2][j+1]});
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;
}

