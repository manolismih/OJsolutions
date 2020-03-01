#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int t,n, par[100015], dp[100015][2], ways[100015][2]; // dp,ways [v][parlit]
list<int> alist[100015];

void dfs(int v)
{
	int sumlit=0, sumnotlit=0, plit=1, pnotlit=1;
	for (auto it:alist[v])
		if (it != par[v])
		{
			par[it] = v;
			dfs(it);
			sumlit += dp[it][1];
			sumnotlit += dp[it][0];
			plit = (plit*ways[it][1])%10007;
			pnotlit = (pnotlit*ways[it][0])%10007;
		}
	dp[v][0] = 1 + sumlit;
	dp[v][1] = min(sumnotlit, 1+sumlit);
	ways[v][0] = plit;
	ways[v][1] = ((dp[v][1]==sumnotlit ? pnotlit : 0) + (dp[v][1]==1+sumlit ? plit : 0)) % 10007;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) alist[i].clear();
		for (int v1,v2, i=1; i<n; i++)
		{
			scanf("%d%d",&v1,&v2);
			alist[v1].push_back(v2);
			alist[v2].push_back(v1);
		}
		dfs(1);
		printf("%d %d\n",dp[1][1],ways[1][1]);
	}
	return 0;
}

