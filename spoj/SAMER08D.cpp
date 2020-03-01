#include <cstdio>
#include <cstring>

int k,l1,l2, dp[1005][1005][2];
unsigned long long h1[1005], h2[1005], p=1;
char s1[1005], s2[1005];

int max(int a, int b, int c)
{
	int max=a;
	if (b>max) max=b;
	if (c>max) max=c;
	return max;
}

int main()
{
	freopen("in.txt","r",stdin);
	while (scanf("%d",&k) && k)
	{
		scanf("%s%s",s1,s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		if (l1<k || l2<k)
		{
			printf("0\n");
			continue;
		}
		h1[0] = h2[0] = 0;
		p=1;
		for (int i=1; i<k; i++) p *= 131;
		
		for (int i=0; i<k; i++) h1[0] = h1[0]*131 + s1[i];
		for (int i=k; i<l1; i++) h1[i-k+1] = (h1[i-k] - s1[i-k]*p)*131 + s1[i];
		
		for (int i=0; i<k; i++) h2[0] = h2[0]*131 + s2[i];
		for (int i=k; i<l2; i++) h2[i-k+1] = (h2[i-k] - s2[i-k]*p)*131 + s2[i];
		
		for (int i=0; i<=l1; i++) dp[i][l2][0] = dp[i][l2][1] = 0;
		for (int i=0; i<=l2; i++) dp[l1][i][0] = dp[l1][i][1] = 0;
		
		for (int i=l1-1; i>=0; i--)
			for (int j=l2-1; j>=0; j--)
			{
				dp[i][j][0] = max(dp[i+1][j][0], dp[i][j+1][0], (i+k-1<l1 && j+k-1<l2 && h1[i]==h2[j]) ? dp[i+k][j+k][1]+k : 0);
				dp[i][j][1] = max(dp[i+1][j][0], dp[i][j+1][0], (s1[i]==s2[j]) ? dp[i+1][j+1][1]+1 : 0);
			}
		printf("%d\n",dp[0][0][0]);
	}
	return 0;
}

