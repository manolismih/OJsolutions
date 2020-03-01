#include <cstdio>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node{
	int par[15], level; // for lca
	int from, to; // for update. Το βαφτιστικό του κόμβου είναι επίσης το from.
	int genies; // local copy
};
Node node[30005];
list<int> alist[30005];
int t,n,q, arxika[30005], id, tree[120000];

void init()
{
	for (int i=0; i<=n; i++) alist[i].clear();
	memset(tree,0,480000);
	id = 0;
	node[1].level = 1;
	node[1].par[0] = 0;
}

void dfs(int v)
{
	node[v].genies = arxika[v];
	for (int i=1; i<15; i++) node[v].par[i] = node[node[v].par[i-1]].par[i-1];
	node[v].from = ++id;
	for (list<int>::iterator next = alist[v].begin(); next != alist[v].end(); next++)
		if (*next != node[v].par[0])
		{
			node[*next].par[0] = v;
			node[*next].level = node[v].level+1;
			dfs(*next);
		}
	node[v].to = id;
}

int findlca(int v1, int v2)
{
	if (node[v2].level > node[v1].level) swap(v1,v2);
	for (int i=14; node[v1].level > node[v2].level; i--)
		if (node[node[v1].par[i]].level >= node[v2].level) v1 = node[v1].par[i];
	if (v1 == v2) return v1;
	for (int i=14; node[v1].par[0] != node[v2].par[0]; i--)
		if (node[v1].par[i] != node[v2].par[i]) v1 = node[v1].par[i], v2 = node[v2].par[i];
	return node[v1].par[0];
}

void add(int from, int to, int val, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto) tree[i] += val;
	else
	{
		int middle = (posfrom+posto)/2;
		if (from <= middle) add(from,min(middle,to),val,2*i,posfrom,middle);
		if (to > middle) add(max(from,middle+1),to,val,2*i+1,middle+1,posto);
	}
}

int val(int pos, int i, int posfrom, int posto)
{
	int middle;
	while (posfrom != posto)
	{
		tree[2*i] += tree[i];
		tree[2*i+1] += tree[i];
		tree[i] = 0;
		middle = (posfrom+posto)/2;
		if (pos <= middle) i*=2, posto=middle;
		else i = 2*i+1, posfrom = middle+1;
	}
	return tree[i];
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
	{
		printf("Case %d:\n",i);
		scanf("%d",&n);
		init();
		for (int i=1; i<=n; i++) scanf("%d",&arxika[i]); // θέλω 1 ως n
		for (int v1,v2, i=1; i<n; i++)
		{
			scanf("%d%d",&v1,&v2);
			alist[++v1].push_back(++v2); // θέλω 1 ως n
			alist[v2].push_back(v1);
		}
		dfs(1);
		
		for (int i=1; i<=n; i++) add(node[i].from,node[i].to,node[i].genies,1,1,n);
		scanf("%d",&q);
		for (int type,a,b,lca, i=0; i<q; i++)
		{
			scanf("%d%d%d",&type,&a,&b);
			a++;
			if (type)
			{
				add(node[a].from,node[a].to,b-node[a].genies,1,1,n);
				node[a].genies = b;
			}
			else
			{
				b++;
				lca = findlca(a,b);
				printf("%d\n",val(node[a].from,1,1,n) + val(node[b].from,1,1,n) -2*val(node[lca].from,1,1,n) + node[lca].genies);
			}
		}
	}
	return 0;
}

