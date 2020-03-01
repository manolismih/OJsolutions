#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
	char ltype;
	long long lazy,x,x2;
	void set(long long val, int size)
	{
		ltype = 's';
		lazy = val;
		x = val*size;
		x2 = x*val;
	}
	void add(long long val, int size)
	{
		if (ltype=='s') set(lazy+val,size);
		else
		{
			ltype = 'a';
			lazy += val;
			x2 += 2*val*x + size*val*val;
			x += size*val;
		}
	}
	void propagate(int i, int posfrom, int middle, int posto);
};
node tree[400000];
int t,n,q;

void node::propagate(int i, int posfrom, int middle, int posto)
{
	if (ltype=='a') tree[2*i].add(lazy,middle-posfrom+1), tree[2*i+1].add(lazy,posto-middle);
	else if (ltype=='s') tree[2*i].set(lazy,middle-posfrom+1), tree[2*i+1].set(lazy,posto-middle);
	ltype = lazy = 0;
}

long long sx2(int from, int to, int i=1, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto) return tree[i].x2;
	int middle = (posfrom+posto)/2;
	tree[i].propagate(i,posfrom,middle,posto);
	return (from<=middle ? sx2(from,min(to,middle),2*i,posfrom,middle) : 0
		  + to>middle ? sx2(max(from,middle+1),to,2*i+1,middle+1,posto) : 0);
}

void change(int from, int to, int val, int type, int i=1, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto)
	{
		if (type) tree[i].add(val,posto-posfrom+1); 
		else tree[i].set(val,posto-posfrom+1);
		return;
	}
	int middle = (posfrom+posto)/2;
	tree[i].propagate(i,posfrom,middle,posto);
	if (from<=middle) change(from,min(middle,to),val,type,2*i,posfrom,middle);
	if (to > middle) change(max(from,middle+1),to,val,type,2*i+1,middle+1,posto);
	tree[i].x = tree[2*i].x + tree[2*i+1].x;
	tree[i].x2 = tree[2*i].x2 + tree[2*i+1].x2;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
	{
		//memset(tree,0,sizeof(tree));
		for (int i=0; i<400000; i++) tree[i].lazy = tree[i].ltype = tree[i].x = tree[i].x2 = 0;
		printf("Case %d:\n",i);
		scanf("%d%d",&n,&q);
		for (int num, i=1; i<=n; i++)
		{
			scanf("%d",&num);
			change(i,i,num,0);
		}
		for (int type,from,to,val, i=0; i<q; i++)
		{
			scanf("%d%d%d",&type,&from,&to);
			if (type==2) printf("%lld\n",sx2(from,to));
			else
			{
				scanf("%d",&val);
				change(from,to,val,type);
			}
		}
	}	
	return 0;
}

