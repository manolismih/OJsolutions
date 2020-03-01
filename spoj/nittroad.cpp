#include <cstdio>
#include <algorithm>
 
int t,n,q,rep[20005],rank[20005],num[20005],edges[20005][2],queries[20005],apantiseis[20005];
bool exist[20005];

int find(int v)
{
	if (rep[v] == v) return v;
	return rep[v] = find(rep[v]);
}

void join(int v1, int v2)
{
	if (rank[v2] > rank[v1]) std::swap(v1,v2);
	if (rank[v1] == rank[v2]) rank[v1]++;
	rep[v2] = v1;
	num[v1] += num[v2];
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
			rank[i] = num[i] = exist[i] = 1;
		}
		
		for (int i=1; i<n; i++)
			scanf("%d%d",&edges[i][0],&edges[i][1]);
		
		int qnum=0; char c;
		scanf("%d",&q);
		for (int i=0; i<q; i++)
		{
			scanf(" %c",&c);
			if (c=='Q') qnum++, queries[i]=0;
			else scanf("%d",&queries[i]), exist[queries[i]]=0;
		}
		
		int apantisi = (n*n-n)/2;
		for (int i=1; i<n; i++)
			if (exist[i])
			{
				int f1=find(edges[i][0]), f2=find(edges[i][1]);
				apantisi -= num[f1]*num[f2];
				join(f1,f2);
			}
			
		int api=qnum;
		for (int i=q-1; i>-1; i--)
			if (!queries[i]) apantiseis[--api] = apantisi;
			else
			{
				int f1=find(edges[queries[i]][0]), f2=find(edges[queries[i]][1]);
				apantisi -= num[f1]*num[f2];
				join(f1,f2);
			}
			
		for (int i=0; i<qnum; i++) printf("%d\n",apantiseis[i]);
		printf("\n");
	}
}
