#include <cstdio>
#include <algorithm>

struct edge{
	int v1,v2,cost;
};
bool operator<(edge a, edge b) {return a.cost<b.cost;}

int t,n, rep[15005], plithos[15005], rank[15005];
edge edges[15005];

int find(int v)
{
	if (rep[v] == v) return v;
	return rep[v] = find(rep[v]);
}

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
		{
			rep[i] = i;
			plithos[i] = rank[i] = 1;
		}
		long long apantisi=0;
		
		for (int i=0; i<n-1; i++)
			scanf("%d%d%d",&edges[i].v1,&edges[i].v2,&edges[i].cost);
		std::sort(edges,edges+n-1);
		
		for (int i=0; i<n-1; i++)
		{
			int r1=find(edges[i].v1), r2=find(edges[i].v2);
			apantisi += (long long)plithos[r1]*plithos[r2]*(edges[i].cost+1)-1;
			if (rank[r1] <= rank[r2])
			{
				rep[r1] = r2;
				plithos[r2] += plithos[r1];
				if (rank[r1] == rank[r2]) rank[r2]++;
			} 
			else
			{
				rep[r2] = r1;
				plithos[r1] += plithos[r2];
			}
		}
		printf("%lld\n",apantisi);
	}
	return 0;
}
