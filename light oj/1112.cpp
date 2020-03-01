#include <cstdio>
#include <algorithm>
using namespace std;

int t,n,q,money[100005], tree[800005];

void update(int pos, int val, int i, int posfrom, int posto)
{
	if (posfrom == posto)
	{
		tree[i] = val;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (pos <= middle) update(pos,val,2*i,posfrom,middle);
	else update(pos,val,2*i+1,middle+1,posto);
	tree[i] = tree[2*i]+tree[2*i+1];
}

int sum(int from, int to, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto)
		return tree[i];
	int middle = (posfrom+posto)/2;
	return (from<=middle ? sum(from,min(to,middle),2*i,posfrom,middle) : 0)
			+ (to>=middle+1 ? sum(max(middle+1,from),to,2*i+1,middle+1,posto) : 0);
}

int main()
{
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
	{
		printf("Case %i:\n",i);
		scanf("%d%d",&n,&q);
		for (int i=0; i<n; i++)
		{
			scanf("%d",&money[i]);
			update(i,money[i],1,0,n-1);
		}
		for (int type, i=0; i<q; i++)
		{
			scanf("%d",&type);
			if (type == 1)
			{
				int pos;
				scanf("%d",&pos);
				printf("%d\n",money[pos]);
				money[pos]=0;
				update(pos,0,1,0,n-1);
			}
			else if (type == 2)
			{
				int pos, val;
				scanf("%d%d",&pos,&val);
				money[pos] += val;
				update(pos,money[pos],1,0,n-1);
			}
			else
			{
				int from, to;
				scanf("%d%d",&from,&to);
				printf("%d\n",sum(from,to,1,0,n-1));
			}
		}
	}
	return 0;
}
