#include <cstdio>
#include <list>
#include <cstring>
using namespace std;

int t,n, ncomps, comp[1005], dfs[1005], lowlink[1005], time[1005], currtime, stack[1005], si;
list<int> alist[1005];

void init()
{
	ncomps = currtime = si = 0;
	memset(dfs,0,4*1005);
	for (int i=1; i<=n; i++) alist[i].clear();
}

void tarjan(int v)
{
	dfs[v] = 1;
	lowlink[v] = time[v] = ++currtime;
	stack[++si] = v;
	for (auto next:alist[v])
	{
		if (dfs[next]==2) continue;
		if (!dfs[next]) tarjan(next);
		if (lowlink[next] < lowlink[v]) lowlink[v] = lowlink[next];
	}
	if (lowlink[v]==time[v])
	{
		ncomps++;
		for (; stack[si] != v; si--)
		{
			dfs[stack[si]]  = 2;
			comp[stack[si]] = ncomps;
		}
		si--;
		dfs[v] = 2;
		comp[v] = ncomps;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d",&n);
		init();
		int m,v;
		for (int i=1; i<=n; i++)
		{
			scanf("%d",&m);
			for (int j=0; j<m; j++)
			{
				scanf("%d",&v);
				alist[v].push_back(i);
			}
		}
		
		for (int i=1; i<=n; i++)
			if (!dfs[i]) tarjan(i);
		
		int in[1005] = {0};
		for (int i=1; i<=n; i++)
			for (auto it:alist[i])
				if (comp[i] != comp[it]) ++in[comp[it]];
				
		int noin=0;
		for (int i=1; i<=ncomps; i++)
			if (!in[i]) noin = noin ? -1 : i;
		if (noin==-1)
		{
			printf("0\n");
			continue;
		}
		int ans=0;
		for (int i=1; i<=n; i++)
			if (comp[i]==noin) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

