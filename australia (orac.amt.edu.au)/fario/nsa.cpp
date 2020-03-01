#include <cstdio>
#include <algorithm>

int n,m, from[100005], to[100005], virusblock[100005], loc[100005], pc[100005];
int rank[100005], rep[100005];

int find(int v)
{
	if (rep[v]==v) return v;
	return rep[v] = find(rep[v]);
}

int join(int v1, int v2)
{
	if (rank[v1]>rank[v2]) std::swap(v1,v2);
	if (rank[v1]==rank[v2]) rank[v2]++;
	return rep[v1] = v2;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	char c;
	for (int i=1; i<=m; i++)
	{
		scanf(" %c",&c);
		if (c=='E') scanf("%d%d",&from[i],&to[i]);
		else
		{
			scanf("%d",&from[i]);
			virusblock[i] = from[i];
			from[i] = i;
		}
	}
	for (int i=1; i<=n; i++)
	{
		loc[i] = pc[i] = rep[i] = i;
		rank[i]=1;
	}  
	
	for (int i=1; i<=m; i++)
	{
		if (to[i])
			if (pc[from[i]] && pc[to[i]])
			{
				int f1=find(pc[from[i]]), f2=find(pc[to[i]]);
				int j = join(f1,f2);
				pc[to[i]] = j;
				loc[j] = to[i];
				pc[from[i]] = 0;
			}
			else if (pc[from[i]])
			{
				pc[to[i]] = pc[from[i]];
				pc[from[i]] = 0;
				loc[pc[to[i]]] = to[i];
			}
			else ;
		else printf("%d\n",loc[find(virusblock[i])]);
	}
	return 0;
}

