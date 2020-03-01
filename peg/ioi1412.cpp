#include <cstdio>
#include <algorithm>
using namespace std;
#define add first
#define remove second

int n,q;
pair<int,int> tree[8000000], null(-1,100001);
bool lazy[8000000]={1,1};

void propagate (pair<int,int> &source, pair<int,int> &target)
{
	if (source.add == source.remove)
		target=source;
	else if (target.add == target.remove)
	{
		if (target.add < source.add) target.add = target.remove = source.add;
		else if (target.add > source.remove) target.add = target.remove = source.remove;
	}
	else
	{
		if (target.add < source.add && target.remove > source.remove)
		{
			target.add = source.add;
			target.remove = source.remove;
		} 
		else if (target.add < source.add)
		{
			if (source.add > target.remove) target.add = target.remove = source.add;
			else target.add = source.add;
		}	
		else if (target.remove > source.remove)
		{
			if (source.remove < target.add) target.add = target.remove = source.remove;
			else target.remove = source.remove;
		}
	}
}

void change(int from, int to, pair<int,int> &val, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto)
	{
		propagate(val,tree[i]);
		lazy[i] = true;
		return;
	}
	if (lazy[i])
	{
		propagate(tree[i],tree[2*i]);
		propagate(tree[i],tree[2*i+1]);
		tree[i] = null;
		lazy[i] = false;
		lazy[2*i] = lazy[2*i+1] = true;
	}
	int middle = (posfrom+posto)/2;
	if (from<=middle) change(from,min(to,middle),val,2*i,posfrom,middle);
	if (to>middle) change(max(middle+1,from),to,val,2*i+1,middle+1,posto);
}

void print(int i, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		printf("%d\n",tree[i].add);
		return;
	}
	if (lazy[i])
	{
		propagate(tree[i],tree[2*i]);
		propagate(tree[i],tree[2*i+1]);
		lazy[2*i] = lazy[2*i+1] = true;
	}
	int middle = (posfrom+posto)/2;
	print(2*i,posfrom,middle);
	print(2*i+1,middle+1,posto);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	int type, from, to ,val;
	pair<int,int> temp;
	for (int i=0; i<q; i++)
	{
		scanf("%d%d%d%d",&type,&from,&to,&val);
		if (type==1)
		{
			temp.add = val;
			temp.remove = 100001;
		}
		else
		{
			temp.add = -1;
			temp.remove = val;
		}
		change(from,to,temp,1,0,n-1);
	}
	print(1,0,n-1);
	return 0;
}

