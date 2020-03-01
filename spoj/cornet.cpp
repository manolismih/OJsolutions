#include <cstdio>

int t,n,q, rep[20005], found[20005], dist[20005];

int ap(int num) {return (num<0 ? -num : num);}

int find(int v)
{
	if (rep[v] == v) return v;
	if (!found[v])
	{
		found[v] = 1;
		dist[v] = ap(v-rep[v])%1000;
	}
	int oldrep = rep[v];
	rep[v] = find(rep[v]);
	dist[v] += dist[oldrep];
	return rep[v];
}

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d",&n,&q);
		for (int i=1; i<=n; i++)
		{
			rep[i] = i;
			found[i] = dist[i] = 0;
		}
		char c; int v1,v2;
		while (scanf(" %c",&c) && c!='O')
			if (c=='I')
			{
				scanf("%d%d",&v1,&v2);
				rep[v1] = v2;
			}
			else
			{
				scanf("%d",&v1);
				find(v1);
				printf("%d\n",dist[v1]);
			}
	}
}
