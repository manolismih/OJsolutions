#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define val first
#define pos second
#define gc getchar_unlocked

//general
int n,q, pin[100005];

//compression
pair<int,int> helpar[100005];
int antimap[100005];

//dfs
vector<int> alist[100005];

///lca
int par[17][100005], level[100005];

//persistent segment tree
int sum[2000000], left[2000000], right[2000000], nodes;

void readint(int &x)
{
	register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void set(int pos, int i, int old, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		sum[i] = 1;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (pos<=middle)
	{
		right[i] = right[old];
		set(pos,left[i]=++nodes,left[old],posfrom,middle);
	}
	else
	{
		left[i] = left[old];
		set(pos,right[i]=++nodes,right[old],middle+1,posto);
	}
	sum[i] = sum[left[i]] + sum[right[i]];
}

void dfs(int v)
{
	level[v] = 1+level[par[0][v]];
	for (int i=1; i<17; i++) par[i][v] = par[i-1][par[i-1][v]];
	set(pin[v],v,par[0][v],1,n);
	for (vector<int>::iterator it=alist[v].begin(); it!=alist[v].end(); it++)
	{
		if (*it == par[0][v]) continue;
		par[0][*it] = v;
		dfs(*it);
	}
}

int findlca(int v1, int v2)
{
	if (level[v1]>level[v2]) swap(v1,v2);
	for (int i=16; i>=0; i--)
		if (level[par[i][v2]] >= level[v1]) v2 = par[i][v2];
	if (v1==v2) return v1;
	for (int i=16; i>=0; i--)
		if (par[i][v1] != par[i][v2])
		{
			v1 = par[i][v1];
			v2 = par[i][v2];
		}
	return par[0][v1];
}

int ans(int v1, int v2, int lca, int plca, int k)
{
	int from=1, to=n, middle, s;
	while (from != to)
	{
		middle = (from+to)/2;
		s = sum[left[v1]] + sum[left[v2]] - sum[left[lca]] - sum[left[plca]];
		if (s < k)
		{
			k -= s;
			from = middle+1;
			v1 = right[v1];
			v2 = right[v2];
			lca = right[lca];
			plca = right[plca];
		}
		else
		{
			to = middle;
			v1 = left[v1];
			v2 = left[v2];
			lca = left[lca];
			plca = left[plca];
		}
	}
	return antimap[from];
}

int main()
{
	//freopen("in.txt","r",stdin);
	readint(n);
	readint(q);
	for (int i=1; i<=n; i++)
	{
		readint(helpar[i].val);
		helpar[i].pos = i;
	}
	sort(helpar+1,helpar+n+1);
	if (helpar[1].val==0) helpar[0].val=-1; // na min einai isa ta prota 2
	for (int i=1; i<=n; i++)
		if (helpar[i].val == helpar[i-1].val)
			pin[helpar[i].pos] = pin[helpar[i-1].pos];
		else
		{
			pin[helpar[i].pos] = i;
			antimap[i] = helpar[i].val;
		}
	
	for (int v1,v2,i=0; i<n-1; i++)
	{
		readint(v1);
		readint(v2);
		alist[v1].push_back(v2);
		alist[v2].push_back(v1);
	}
	nodes = n;
	dfs(1);
	
	for (int v1,v2,k, i=0; i<q; i++)
	{
		readint(v1);
		readint(v2);
		readint(k);
		int lca = findlca(v1,v2);
		printf("%d\n",ans(v1,v2,lca,par[0][lca],k));
	}
	return 0;
}

