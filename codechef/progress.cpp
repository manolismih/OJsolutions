#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define bsize 223
#define from first
#define to second

int n,q;
pair<int,int> qinfo[50005];
long long a[50005], ans[50005], currans;
vector<int> queria[230];
multiset<long long> curr; 

bool comp(int a, int b)	{	return qinfo[a].to < qinfo[b].to;}
inline long long sqr(long long a) {return a*a;}

void add(int x)
{
	auto it=curr.insert(x);
	if (curr.size()==1) return;
	if (it==curr.begin()) currans += sqr(x-*next(it));
	else if (next(it)==curr.end()) currans += sqr(x-*prev(it));
	else currans += sqr(x-*prev(it)) + sqr(x-*next(it)) - sqr(*prev(it)-*next(it));
}

void del(int x)
{
	auto it=curr.find(x);
	if (curr.size()>1)
		if (it==curr.begin()) currans -= sqr(x-*next(it));
		else if (next(it)==curr.end()) currans -= sqr(x-*prev(it));
		else currans -= sqr(x-*prev(it)) + sqr(x-*next(it)) - sqr(*prev(it)-*next(it));
	curr.erase(it);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
	
	scanf("%d",&q);
	for (int i=0; i<q; i++)
	{
		scanf("%d%d",&qinfo[i].from,&qinfo[i].to);
		queria[qinfo[i].from/bsize].push_back(i);
	}
	int nbuckets = n/bsize+2;
	for (int i=0; i<=nbuckets; i++) sort(queria[i].begin(),queria[i].end(),comp);
	
	for (int i=0; i<=nbuckets; i++)
	{
		if (queria[i].empty()) continue;
		curr.clear();
		int from = qinfo[queria[i].front()].from, to=from;
		curr.insert(a[from]);
		currans=0;
		for (auto it:queria[i])
		{
			for (; to<qinfo[it].to; to++) add(a[to+1]);
			for (; from<qinfo[it].from; from++) del(a[from]);
			for (; from>qinfo[it].from; from--) add(a[from-1]);
			ans[it] = currans;
		}
	}
	for (int i=0; i<q; i++) printf("%lld\n",ans[i]);
}
