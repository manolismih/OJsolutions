#include <cstdio>
#include <algorithm>
using namespace std;

int t,n,tree[1200000], lazy, resigned, param, elax;
bool reset[1200000];
char c;

void propagate(int i)
{
	if (!reset[i]) return;
	reset[i] = false;
	reset[2*i] = reset[2*i+1] = true;
	tree[2*i] = tree[2*i+1] = 0;
}

void inc(int pos)
{
	int posfrom=-100000, posto=200000, i=1, middle;
	while (posfrom != posto)
	{
		propagate(i);
		tree[i]++;
		middle  = (posfrom+posto)/2;
		if (pos <= middle) i*=2, posto=middle;
		else i=2*i+1, posfrom=middle+1;
	}
	reset[i]=false;
	tree[i]++;
}

void set0(int from, int to, int i=1, int posfrom=-100000, int posto=200000)
{
	if (from==posfrom && to==posto)
	{
		resigned += tree[i];
		reset[i] = true;
		tree[i] = 0;
		return;
	}
	if (reset[i]) return;
	int middle = (posfrom+posto)/2;
	if (from <= middle) set0(from,min(middle,to),2*i,posfrom,middle);
	if (to > middle) set0(max(middle+1,from),to,2*i+1,middle+1,posto);
	tree[i] = tree[2*i] + tree[2*i+1];
}

int kth(int k, int i=1, int posfrom=-100000, int posto=200000)
{
	if (tree[1]<k) return -1;
	while (posfrom != posto)
		if (tree[2*i+1]>=k)
		{
			i = 2*i+1;
			posfrom = (posfrom+posto)/2+1;
		}
		else
		{
			k -= tree[2*i+1];
			i *= 2;
			posto = (posfrom+posto)/2;
		}
	return posfrom+lazy;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		lazy = resigned = 0;
		reset[1] = true;
		scanf("%d%d",&n,&elax);
		for (int i=0; i<n; i++)
		{
			scanf(" %c%d",&c,&param);
			if (c=='I' && param>=elax) inc(param-lazy);
			else if (c=='A') lazy += param;
			else if (c=='S')
			{
				lazy -= param;
				if (elax-lazy-1 >= -100000 && elax-lazy-1<=200000) set0(-100000,elax-lazy-1);
			}
			else if (c=='F') printf("%d\n",kth(param));
		}
		printf("%d\n",resigned);
	}
}
