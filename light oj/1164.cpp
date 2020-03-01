#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node{
	long long val, lazy;
};
node tree[400005];
int t,n,q,val,from,to;

void check(int &i, int &posfrom, int &posto);
void update(int from, int to, int val, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto)
	{
		tree[i].lazy += val;
		tree[i].val += (to-from+1)*val;
		return;
	}
	int middle = (posfrom+posto)/2;
	check(i,posfrom,posto);
	if (from <= middle) update(from,min(middle,to),val,2*i,posfrom,middle);
	if (to > middle) update(max(middle+1,from),to,val,2*i+1,middle+1,posto);
	tree[i].val = tree[2*i].val + tree[2*i+1].val;
}

void check(int &i, int &posfrom, int &posto)
{
	if (tree[i].lazy)
	{
		int middle = (posfrom+posto)/2;
		update(posfrom,middle,tree[i].lazy,2*i,posfrom,middle);
		update(middle+1,posto,tree[i].lazy,2*i+1,middle+1,posto);
		tree[i].lazy=0;
	}
}

long long sum(int from, int to, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto)
		return tree[i].val;
	int middle = (posfrom+posto)/2;
	check(i,posfrom,posto);
	return (from <= middle ? sum(from,min(middle,to),2*i,posfrom,middle) : 0)
		 + (to > middle ? sum(max(middle+1,from),to,2*i+1,middle+1,posto) : 0); 
}

int main()
{
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
	{
		memset(tree,0,400005*16);
		printf("Case %i:\n",i);
		scanf("%d%d",&n,&q);
		for (int type, i=0; i<q; i++)
		{
			scanf("%d%d%d",&type,&from,&to);
			if (type) printf("%lld\n",sum(from,to,1,0,n-1));
			else
			{
				scanf("%d",&val);
				update(from,to,val,1,0,n-1);
			}
		}
	}
	return 0;
}
