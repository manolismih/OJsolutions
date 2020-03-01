#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

list<int> alist[100005];
int n,m,ncomps, comp[100005], rep[100005], vistime[100005], low[100005], t;
int stack[100005], stacki;

int dfs(int v)
{
	if (vistime[v]) return low[v];
	low[v] = vistime[v] = ++t;
	stack[stacki++] = v;
	for (auto next:alist[v])
		if (!comp[next]) low[v] = min(low[v],dfs(next));
	if (vistime[v]==low[v])
	{
		rep[++ncomps] = 200000;
		for (stacki--; stacki && stack[stacki]!=v; stacki--)
		{
			comp[stack[stacki]] = ncomps;
			rep[ncomps] = min(rep[ncomps],stack[stacki]);
		}
		comp[v] = ncomps;
		rep[ncomps] = min(rep[ncomps],v);
	}
	return low[v];
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int from,to, i=0; i<m; i++)
	{
		scanf("%d%d",&from,&to);
		alist[from].push_back(to);
	}
	
	for (int i=0; i<n; i++) dfs(i);
	for (int i=0; i<n; i++) printf("%d\n",rep[comp[i]]);
	return 0;
}

