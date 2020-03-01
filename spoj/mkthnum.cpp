#include <cstdio>
#include <algorithm>
using namespace std;
#define val first
#define pos second

// general
int n,q, pin[100005];

//compression
pair<int,int> helpar[100005];
int antimap[100005];

//persistent segment tree : node of time i has root index i so nodes start from n+1
int sum[2000000], left[2000000], right[2000000], nodes;

void set(int pos, int i, int old, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		sum[i] = 1;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (pos<=middle)
	{
		right[i] = right[old];
		set(pos,left[i]=++nodes,left[old],posfrom,middle);
	} 
	else
	{
		left[i] = left[old];
		set(pos,right[i]=++nodes,right[old],middle+1,posto);	
	} 
	sum[i] = sum[left[i]] + sum[right[i]];
}

int ans(int l, int r, int k)
{
	int from=1, to=n, middle;
	while (from != to)
	{
		middle = (from+to)/2;
		if (sum[left[r]] - sum[left[l]] < k)
		{
			k -= sum[left[r]] - sum[left[l]];
			l = right[l], r = right[r];
			from = middle+1; 
		}
		else
		{
			l = left[l], r = left[r];
			to = middle;
		}
	}
	return antimap[from];
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&helpar[i].val);
		helpar[i].pos=i;
	}
	sort(helpar+1,helpar+n+1);
	for (int i=1; i<=n; i++)
	{
		pin[helpar[i].pos] = i;
		antimap[i] = helpar[i].val;
	}
	
	nodes=n;
	for (int i=1; i<=n; i++)
		set(pin[i],i,i-1,1,n);
		
	for (int from,to,k, i=0; i<q; i++)
	{
		scanf("%d%d%d",&from,&to,&k);
		printf("%d\n",ans(from-1,to,k));
	}
	return 0;
}

