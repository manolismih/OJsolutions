#include <cstdio>
#include <algorithm>
using namespace std;
#define maxnodes 2000000
#define maxn 100005

int n,q,nodes, sum[maxnodes], left[maxnodes], right[maxnodes];
// Root of time i has index i :). So the nodes variable begins from q+1

void build(int v=0, int from=1, int to=n)
{
	if (from==to)
	{
		scanf("%d",&sum[v]);
		return;
	}
	int middle = (from+to)/2;
	build(left[v]=++nodes,from,middle);
	build(right[v]=++nodes,middle+1,to);
	sum[v] = sum[left[v]] + sum[right[v]];
}

void set(int pos, int val, int old, int v, int from, int to)
{
	if (from==to)
	{
		sum[v] = val;
		return;
	}
	int middle = (from+to)/2;
	if (pos <= middle)
	{
		right[v] = right[old];
		set(pos,val,left[old],left[v]=++nodes,from,middle);
	}
	else if (pos>middle)
	{
		left[v] = left[old];
		set(pos,val,right[old],right[v]=++nodes,middle+1,to);
	}
	sum[v] = sum[left[v]] + sum[right[v]];
	return;
}

int query(int from, int to, int v, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto) return sum[v];
	int middle = (posfrom+posto)/2;
	return (from<=middle ? query(from,min(middle,to),left[v],posfrom,middle) : 0) 
		+ (to>middle ? query(max(middle+1,from),to,right[v],middle+1,posto) : 0);
}

int main()
{
	scanf("%d%d",&n,&q);
	nodes = q+1;
	build();
	
	int from, to, time, pos, val, ans;
	scanf("%d%d",&from,&to);
	printf("%d\n",ans=query(from,to,0));
	for (int i=1; i<=q; i++)
	{
		pos = (10301LL*ans)%n + 1;
		val = (10889LL*ans)%20000 + 1;
		from = (33617LL*ans)%n + 1;
		to = from + (58049LL*ans)%(n-from+1);
		time = (81517LL*ans)%(i+1);
		
		set(pos,val,i-1,i,1,n);
		printf("%d\n",ans=query(from,to,time,1,n));
	}
	
}
