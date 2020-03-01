#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int n,q, from,to,x, tree[1000000];
set<pair<int,bool>> s[250005];

int ans()
{
	int from=1, to=n, i=1, sum=0;
	while (from<to)
	{
		sum += tree[i];
		if (x <= (from+to)/2) to = (from+to)/2, i*=2;
		else from = (from+to)/2+1, i=2*i+1;
	}
	sum += tree[i];
	return sum;
}

void inc2(int from, int to, int i=1, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto)
	{
		tree[i]++;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (from<=middle) inc2(from,min(to,middle),2*i,posfrom,middle);
	if (to>middle) inc2(max(middle+1,from),to,2*i+1,middle+1,posto);
}

inline void inc(int from, int to)
{
	if (from <= to)	inc2(from,to);
}

void insert()
{
	auto it = s[x].lower_bound({from,0}); //0 arxi, 1 telos
	if (!it->second) it = next(s[x].insert(it,{from,0}));
	int prev = from;
	bool add = !it->second;
	while (1)
	{
		if (it->first <= to)
		{
			if (add) inc(prev,it->first-1);
			prev = it->first+1;
			it = s[x].erase(it);
			add = !add;
		}
		else
		{
			if (add)
			{
				inc(prev,to);
				s[x].insert({to,1});
			}
			return;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	
	for (int i=1; i<=n; i++)
	{
		s[i].insert({0,1});
		s[i].insert({n+1,0});
	}
	
	for (int type, i=0; i<q; i++)
	{
		scanf("%d",&type);
		if (type)
		{
			scanf("%d",&x);
			printf("%d\n",ans());
		}
		else
		{
			scanf("%d%d%d",&from,&to,&x);
			insert();
		}
	}
	return 0;
}

