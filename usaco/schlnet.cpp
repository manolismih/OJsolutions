/*
ID:manolis2
PROG:schlnet
LANG:C++11
*/
#include <cstdio>
#include <list>
#include <bitset>
#include <algorithm>
using namespace std;

int n, dfs[105], stack[105], si, low[105], vistime[105], t, comp[105], ncomps;
list<int> alist[105];
bitset<105> in,out;

void tarjan(int v)
{
	dfs[v] = 1;
	low[v] = vistime[v] = ++t;
	stack[++si] = v;
	for (auto next:alist[v])
	{
		if (dfs[next]==2) continue;
		if (!dfs[next]) tarjan(next);
		if (low[next] < low[v]) low[v] = low[next];
	}
	if (low[v] == vistime[v])
	{
		ncomps++;
		for (; stack[si] != v; si--)
		{
			comp[stack[si]] = ncomps;
			dfs[stack[si]] = 2;
		}
		si--;
		comp[v] = ncomps;
		dfs[v] = 2;
	}
}

int main()
{
	freopen("schlnet.in","r",stdin);
	freopen("schlnet.out","w",stdout);
	scanf("%d",&n);
	for (int v,i=1; i<=n; i++)
		while (scanf("%d",&v) && v) alist[i].push_back(v);
		
	for (int i=1; i<=n; i++)
		if (!dfs[i]) tarjan(i);
	
	for (int i=1; i<=n; i++)
		for (auto it:alist[i])
			if (comp[i] != comp[it]) out[comp[i]] = in[comp[it]] = 1;
			
	int noin = ncomps-in.count(), noout = ncomps-out.count();
	printf("%d\n%d\n",noin,(ncomps>1 ? std::max(noin,noout) : 0));
}
