#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define inf 700000.0

int t,n,m, from[1001005], to[1001005];
long double cost[1001005], dist[1005];

bool bellman_ford()
{
	for (int i=1; i<n; i++) dist[i] = inf;
	dist[0] = 0.0;
	for (int i=0; i<n-1; i++)
		for (int j=0; j<m; j++)
			dist[to[j]] = min(dist[to[j]],dist[from[j]]+cost[j]);
			
	for (int j=0; j<m; j++)
		if (dist[from[j]] + cost[j] < dist[to[j]]) return 1;
	return 0;
}

int main()
{
	freopen("millionaire.in","r",stdin);
	freopen("millionaire.out","w",stdout);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d",&n,&m);
		for (int tmp,i=0; i<m; i++)
		{
			scanf("%d%d%d",&from[i],&to[i],&tmp);
			cost[i] = -log(0.5 + 0.015*tmp); 
		}
		for (int i=1; i<=n; i++,m++)
		{
			from[m] = 0;
			to[m] = i;
			cost[m] = 0.0;
		}
		n++;
		printf(bellman_ford() ? "Possible\n" : "Not possible\n");
	}
	return 0;
}

