#include <cstdio>
#include <algorithm>
using namespace std; 
#define inf 2000000000

int n,m,k, **dp, products[100005], apantisi;

int main()
{
	freopen("supermarket.in","r",stdin);
	freopen("supermarket.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=n; i++) scanf("%d",&products[i]);
	
	dp = new int*[n+5];
	for (int i=0; i<n+5; i++) dp[i] = new int[m+5];
	
	for (int moves=0; moves<=m; moves++)
	{
		dp[n+1-moves][moves] = 0;
		for (int pos=1; pos<n+5; pos++) dp[pos][moves+1] = -inf;
		for (int moved=0; moved<moves; moved++) dp[n+1-moves][moved] = -inf;
		
		for (int pos=n-moves; pos>0; pos--)
			for (int moved=moves; moved>=0; moved--)
				dp[pos][moved] = max(dp[pos+1][moved] + (pos%k ? 0 : products[pos+moved]), 
								dp[pos][moved+1] + ((n-moves+moved+1)%k ? 0 : products[pos+moved]));
		apantisi = max(apantisi,dp[1][0]);
	}
	printf("%d\n",apantisi);
	return 0;
}

