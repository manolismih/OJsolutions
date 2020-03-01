#include <cstdio>
#include <algorithm>
using namespace std;

int nodes,n,q,nodei, match[100005], node[100005], tree[400000];

void maketree(int i, int posfrom, int posto)
{
	if (posfrom==posto) 
	{
		tree[i] = node[nodei] - node[nodei-1];
		nodei++;
		return;
	}
	int middle = (posfrom+posto)/2;
	maketree(2*i,posfrom,middle);
	maketree(2*i+1,middle+1,posto);
	tree[i] = max(tree[2*i],tree[2*i+1]);
}

int query(int from, int to, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto) return tree[i];
	int middle = (posfrom+posto)/2;
	return max(from<=middle ? query(from,min(middle,to),2*i,posfrom,middle) : 0 ,
			   to>middle ? query(max(middle+1,from),to,2*i+1,middle+1,posto) :0);
}

int main()
{
	while (1)
	{
		scanf("%d",&n);
		if (!n) return 0;
		int prev,num;
		match[1] = 1;
		nodes = nodei = 1;
		scanf("%d%d",&q,&prev);
		for (int i=2; i<=n; i++)
		{
			scanf("%d",&num);
			if (num == prev) match[i]=nodes;
			else
			{
				prev=num;
				node[nodes] = i-1;
				match[i] = ++nodes;
			}
		}
		maketree(1,1,nodes);
		
		for (int from,to, i=0; i<q; i++)
		{
			scanf("%d%d",&from,&to);
			int a = match[from], b = match[to];
			if (a==b) printf("%d\n",to-from+1);
			else if (a == b-1) printf("%d\n",max(node[a]-from+1, to-node[a]));
			else (printf("%d\n",max({node[a]-from+1, to-node[b-1], query(a+1,b-1,1,1,nodes)})));
		}
	}
}
