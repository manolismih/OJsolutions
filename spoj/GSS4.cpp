#include <cstdio>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

struct node{
	int lazy;
	list<long long> sum;
	void propagate(int i);
};
node tree[400000];
int n,q;

void node::propagate(int i)
{
	tree[2*i].lazy += lazy;
	tree[2*i+1].lazy += lazy;
	for (int i=0; !tree[2*i].sum.empty() && i<lazy; i++) tree[2*i].sum.pop_front();
	for (int i=0; !tree[2*i+1].sum.empty() && i<lazy; i++) tree[2*i+1].sum.pop_front();
	lazy=0;
}

void sinthesi(int i, int posfrom, int middle, int posto)
{
	tree[i].sum.clear();
	auto lit=tree[2*i].sum.begin(), rit=tree[2*i+1].sum.begin();
	for (; lit!=tree[2*i].sum.end() && rit!=tree[2*i+1].sum.end(); lit++,rit++)
		tree[i].sum.push_back(*lit + *rit);
	for (; lit != tree[2*i].sum.end(); lit++) tree[i].sum.push_back(*lit + posto-middle);
	for (; rit != tree[2*i+1].sum.end(); rit++) tree[i].sum.push_back(*rit + middle-posfrom+1);
}

void read(int i=1, int posfrom=1, int posto=n)
{
	if (posfrom==posto)
	{
		long long num;
		scanf("%lld",&num);
		for (; num>1; num = sqrt(num)) tree[i].sum.push_back(num);
		return;
	}
	int middle = (posfrom+posto)/2;
	read(2*i,posfrom,middle);
	read(2*i+1,middle+1,posto);
	sinthesi(i,posfrom,middle,posto);
}

long long sum(int from, int to, int i=1, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto) return tree[i].sum.empty() ? posto-posfrom+1 : tree[i].sum.front();
	int middle = (posfrom+posto)/2;
	if (tree[i].lazy) tree[i].propagate(i);
	return (from<=middle ? sum(from,min(middle,to),2*i,posfrom,middle) : 0)
		+  (to>middle ? sum(max(middle+1,from),to,2*i+1,middle+1,posto) : 0);
}

void root(int from, int to, int i=1, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto)
	{
		if (!tree[i].sum.empty()) tree[i].sum.pop_front();
		tree[i].lazy++;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (tree[i].lazy) tree[i].propagate(i);
	if (from<=middle) root(from,min(middle,to),2*i,posfrom,middle);
	if (to>middle) root(max(middle+1,from),to,2*i+1,middle+1,posto);
	sinthesi(i,posfrom,middle,posto);
}

int main()
{
	//freopen("in.txt","r",stdin);
	for (int i=1; scanf("%d",&n) && !feof(stdin); i++)
	{
		printf("Case #%d\n",i);
		
		for (int i=0; i<400000; i++)
		{
			tree[i].sum.clear();
			tree[i].lazy=0;
		}
		
		read();
		scanf("%d",&q);
		int j=0,type,from,to;
		for ( ; !tree[1].sum.empty() && j<q; j++)
		{
			scanf("%d%d%d",&type,&from,&to);
			if (from > to) swap(from,to);
			if (type) printf("%lld\n",sum(from,to));
			else root(from,to);
		}
		for (; j<q; j++)
		{
			scanf("%d%d%d",&type,&from,&to);
			if (from > to) swap(from,to);
			if (type) printf("%d\n",to-from+1);
		}
		printf("\n");
	}
}
