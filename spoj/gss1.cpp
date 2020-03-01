#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int full, from, to, sum;
};
node tree[200000];
int n,q;

void read(int i, int posfrom, int posto)
{
	if (posfrom == posto)
	{
		scanf("%d",&tree[i].full);
		tree[i].sum = tree[i].from = tree[i].to = tree[i].full;
		return;
	}
	int middle = (posfrom+posto)/2;
	read(2*i,posfrom,middle);
	read(2*i+1,middle+1,posto);
	
	tree[i].full = max({tree[2*i].full, tree[2*i+1].full, tree[2*i].from+tree[2*i+1].to});
	tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
	tree[i].from = max(tree[2*i+1].from, tree[2*i+1].sum+tree[2*i].from);
	tree[i].to = max(tree[2*i].to, tree[2*i].sum+tree[2*i+1].to);
}

node query(int from, int to, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto) return tree[i];
	int middle = (posfrom+posto)/2;
	if (from <= middle)
	{
		if (to > middle)
		{
			node a = query(from,middle,2*i,posfrom,middle);
			node b = query(middle+1,to,2*i+1,middle+1,posto);
			return {max({a.full, b.full, a.from+b.to}),
					max(b.from, b.sum+a.from),
					max(a.to, a.sum+b.to),
					a.sum + b.sum};
		}
		return query(from,to,2*i,posfrom,middle);
	}
	return query(from,to,2*i+1,middle+1,posto);
}

int main()
{
	scanf("%d",&n);
	read(1,1,n);
	scanf("%d",&q);
	for (int start,end, i=0; i<q; i++)
	{
		scanf("%d%d",&start,&end);
		printf("%d\n",query(start,end,1,1,n).full);
	}
	return 0;
}

