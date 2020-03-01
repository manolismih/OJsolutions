#include <cstdio>
#include <set>
using namespace std;
#define size 1130

int n,l,q, pos[150005], photos[150005], upto[150005], inbucket[150000];
bool comp(int a, int b) {return pos[a] < pos[b];}
multiset<int,bool(*)(int,int)> el(comp);

void make_buckets()
{
	auto it = prev(el.end()), next = it;
	int b = (n-1)/size, p = (n-1)%size, last = pos[*it];
	for ( ; b>=0; b--)
	{
		for ( ; p>=0; p--,it--)
		{
			while (pos[*prev(next)] > pos[*it]+l) next--;
			if (pos[*it]+l >= last) photos[*it]=1, upto[*it] = pos[*it]+l;
			else photos[*it] = 1+photos[*next], upto[*it] = upto[*next];
			inbucket[*it] = b;
		}
		p = size-1;
		last = pos[*it];
	}
}

void remove(int id)
{
	auto it = el.erase(id), next = it;
	int last = pos[*it], b = inbucket[id];
	it--, next--;
	for ( ; inbucket[*it]==b; it--)
	{
		while (pos[*prev(next)] > pos[*it]+l) next--;
		if (pos[*it]+l < last) photos[*it] = 1+photos[*next], upto[*it] = upto[*next];
	}
}

void add(int id, int newpos)
{
	pos[id] = newpos;
	auto it = el.insert(id).first();
	inbucket[id] = (next(it)==el.end() ? (n-1)/size : inbucket[*next(it)]);
	pos[150003] = newpos+l;
	auto next = el.upper_bound(150003);
	if (next==el.end() || inbucket[*next] != inbucket[id]) photos[id]=1, upto[id] = newpos+l;
	
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&l,&q);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&pos[i]);
		el.insert(el.end(),i);
	}
	pos[150000] = 2000000000;
	el.insert(150000);
	
	for (int id,newpos, i=0; i<q; i++)
	{
		if (i%387) make_buckets();
		scanf("%d%d",&id,&newpos);
		remove(id);
		add(id,newpos);
		printf("%d\n",ans());
	}
}
