#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t,n;
long long tree[4000005], apantisi;

void update(int val, int i, int posfrom, int posto)
{
	tree[i] += val;
	if (posfrom == posto) return;
	int middle = (posfrom+posto)/2;
	(val <= middle) ? update(val,2*i,posfrom,middle) : update(val,2*i+1,middle+1,posto);
}

long long sum(int from, int to, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto) return tree[i];
	int middle = (posfrom+posto)/2;
	return (from <= middle ? sum(from,min(middle,to),2*i,posfrom,middle) : 0)
	     + (to > middle ? sum(max(middle+1,from),to,2*i+1,middle+1,posto) : 0);
}

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		apantisi = 0;
		memset(tree,0,4000005*8);
		scanf("%d",&n);
		for (int num, i=0; i<n; i++)
		{
			scanf("%d",&num);
			if (num > 1) apantisi += sum(1,num-1,1,1,1000000);
			if (num > 0) update(num,1,1,1000000);
		}
		printf("%lld\n",apantisi);
	}
	return 0;
}
