#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t,n,q, par[10][1005], level[1005];
vector<int> children[1005];

void dfs(int v, int lev)
{
	level[v] = lev;
	for (int i=1; i<10; i++)
		par[i][v] = par[i-1][par[i-1][v]];
	for (auto child:children[v]) dfs(child,lev+1);
}

int lca(int v1, int v2)
{
	if (level[v1] < level[v2]) swap(v1,v2);
	for (int i=9; level[v1] > level[v2]; i--)
		if (level[par[i][v1]] >= level[v2]) v1 = par[i][v1];
		
	if (v1==v2) return v1;
	
	for (int i=9; par[0][v1] != par[0][v2]; i--)
		if (par[i][v1] != par[i][v2]) v1 = par[i][v1], v2=par[i][v2];
		
	return par[0][v1];
}

int main()
{
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
	{
		printf("Case %d:\n",i);
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
		{
			par[0][i] = 0;
			children[i].clear();
		}
		
		for (int num, i=1; i<=n; i++)
		{
			scanf("%d",&num);
			for (int v, j=0; j<num; j++)
			{
				scanf("%d",&v);
				par[0][v] = i;
				children[i].push_back(v);
			}
		}
		
		for (int i=1; i<=n; i++)
			if (!par[0][i])
				dfs(i,1);
		
		scanf("%d",&q);
		for (int v1,v2, i=0; i<q; i++)
		{
			scanf("%d%d",&v1,&v2);
			printf("%d\n",lca(v1,v2));
		}
	}
	return 0;
}
