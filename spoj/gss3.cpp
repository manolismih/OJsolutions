#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int full, from, to, sum;
};
node tree[200000];
int n,q;

void update(int pos, int val, int i, int posfrom, int posto)
{
	if (posfrom == posto)
	{
		tree[i].sum = tree[i].from = tree[i].to = tree[i].full = val;
		return;
	}
	int middle = (posfrom+posto)/2;
	pos <= middle ? update(pos,val,2*i,posfrom,middle) : update(pos,val,2*i+1,middle+1,posto);
	
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
	for (int num,i=1; i<=n; i++)
	{
		scanf("%d",&num);
		update(i,num,1,1,n);
	}
	scanf("%d",&q);
	for (int t,n1,n2, i=0; i<q; i++)
	{
		scanf("%d%d%d",&t,&n1,&n2);
		if (t) printf("%d\n",query(n1,n2,1,1,n).full);
		else update(n1,n2,1,1,n);
	}
	return 0;
}

