#include <cstdio>
#include <algorithm>
using namespace std;

struct query{
	int from,to,k,id;
};
bool operator<(query a, query b)
{
	return a.k < b.k;
}

query queries[200000];
int nums[30005], tree[120000], sorted[30005], apantiseis[200005], n,q;

bool comp(int a, int b)
{
	return nums[a] < nums[b];
}

void change(int pos, int val, int i, int posfrom, int posto)
{
	if (posfrom == posto)
		tree[i] = val;
	else
	{
		int middle = (posfrom+posto)/2;
		if (pos <= middle) change(pos,val,2*i,posfrom,middle);
		else change(pos,val,2*i+1,middle+1,posto);
		tree[i] = tree[2*i] + tree[2*i+1];
	}
}

int sum(int from, int to, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto) return tree[i];
	int middle = (posfrom+posto)/2;
	return (from<=middle ? sum(from,min(middle,to),2*i,posfrom,middle) : 0)
		 + (to>middle ? sum(max(from,middle+1),to,2*i+1,middle+1,posto) : 0);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		change(i,1,1,1,n);
		scanf("%d",&nums[i]);
		sorted[i]=i;
	}
	scanf("%d",&q);
	for (int i=0; i<q; i++)
	{
		scanf("%d%d%d",&queries[i].from,&queries[i].to,&queries[i].k);
		queries[i].id = i;
	}
	sort(sorted+1,sorted+n+1,comp);
	sort(queries,queries+q);
	 
	for (int qi=0,i=1; qi<q && i<=n; i++)
	{
		for (; qi<q && queries[qi].k<nums[sorted[i]]; qi++)
			apantiseis[queries[qi].id] = sum(queries[qi].from,queries[qi].to,1,1,n);
		change(sorted[i],0,1,1,n);
	}
	
	for (int i=0; i<q; i++)
		printf("%d\n",apantiseis[i]);	
	return 0;
}

