#include <cstdio>
#include <algorithm>

struct edge {	int v1,v2,cost;		};
bool operator<(edge a, edge b) {	return a.cost>b.cost;	}
int n,m,tnt, rep[20005], rank[20005];
edge bridge[1000005];

int find(int v)
{
	if (rep[v]==v) return v;
	return rep[v] = find(rep[v]);
}
void join(int v1, int v2)
{
	if (rank[v2]>rank[v1]) std::swap(v1,v2);
	if (rank[v1]==rank[v2]) rank[v1]++;
	rep[v2] = v1;
}

int main()
{
	freopen("resistance.in","r",stdin);
	freopen("resistance.out","w",stdout);
	scanf("%d%d%d",&n,&m,&tnt);
	for (int i=1; i<=n; i++)
		rep[i]=i, rank[i]=1;
	for (int i=0; i<m; i++)
		scanf("%d%d%d",&bridge[i].v1,&bridge[i].v2,&bridge[i].cost);
	std::sort(bridge,bridge+m);
	
	for (int f1,f2,i=0; i<m; i++)
	{
		f1=find(bridge[i].v1), f2=find(bridge[i].v2);
		if (f1!=f2)
		{
			join(f1,f2);
			bridge[i].cost=-1;
		}
	}
	
	int apantisi=0;
	for (int i=m-1; i>-1; i--)
		if (bridge[i].cost != -1)
			if (bridge[i].cost > tnt) break;
			else tnt -= bridge[i].cost, apantisi++;
			
	printf("%d\n",apantisi);
	return 0;
}

