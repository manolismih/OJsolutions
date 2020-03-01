#include <cstdio>
#include <algorithm>
using namespace std;

int n,q, tree[400000], lazy[400000], posintree[100005], oura[100005];
pair<int,int> init[100005];

void maketree(int i=1, int posfrom=1, int posto=n)
{
	if (posfrom==posto) tree[i] = init[posfrom].first;
	else
	{
		maketree(2*i,posfrom,(posfrom+posto)/2);
		maketree(2*i+1,(posfrom+posto)/2+1, posto);
		tree[i] = tree[2*i];
	}
}

void propagate(int i)
{
	if (!lazy[i]) return;
	lazy[2*i] += lazy[i];
	lazy[2*i+1] += lazy[i];
	tree[2*i] += lazy[i];
	tree[2*i+1] += lazy[i];
	lazy[i] = 0;
}

int get(int pos)
{
	int i=1, posfrom=1, posto=n, middle;
	while (posfrom != posto)
	{
		propagate(i);
		middle = (posfrom+posto)/2;
		if (pos <= middle) i*=2, posto=middle;
		else i = 2*i+1, posfrom=middle+1;
	}
	return tree[i];
}

int last(int val)
{
	if (val <= tree[1]) return 0;
	int i=1, posfrom=1, posto=n;
	while (posfrom != posto)
	{
		propagate(i);
		if (tree[2*i+1] < val) i = 2*i+1, posfrom = (posfrom+posto)/2 +1;
		else i*=2, posto = (posfrom+posto)/2;
	}
	return posfrom;
}

void add(int from, int to, int val, int i=1, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto)
	{
		tree[i] += val;
		lazy[i] += val;
		return;
	}
	propagate(i);
	int middle = (posfrom+posto)/2;
	if (from <= middle) add(from,min(middle,to),val,2*i,posfrom,middle);
	if (to > middle) add(max(middle+1,from),to,val,2*i+1,middle+1,posto);
	tree[i] = tree[2*i];
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&init[i].first);
		init[i].second = i;
	}
	
	sort(init+1,init+n+1);
	for (int i=1; i<=n; i++)
	{
		posintree[init[i].second] = i;
		oura[i] = init[i].second;
	} 
	maketree();
	
	for (int type,x, i=0; i<q; i++)
	{
		scanf("%d%d",&type,&x);
		if (type==1) 
		{
			int pos1 = posintree[x];
			int pos2 = last(get(pos1)+1);
			add(pos2,pos2,1);
			swap(oura[pos1],oura[pos2]);
			swap(posintree[oura[pos1]],posintree[oura[pos2]]);
		}
		else if (type==2) printf("%d\n",n-last(x));
		else
		{
			int from = last(x)+1;
			if (from<=n) add(from,n,-1);
		}
	}
	return 0;
}

