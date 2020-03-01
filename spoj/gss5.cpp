#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int sum,full,start,end;
};
node tree[40000];
int t,n,q, s1,e1,s2,e2;

void combine(node &target, node &a, node &b)
{
	target.sum   = a.sum + b.sum;
	target.full  = max({a.full, b.full, a.end+b.start});
	target.start = max(a.start, a.sum+b.start);
	target.end   = max(b.end, b.sum+a.end);
}

node val(int from, int to, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto) return tree[i];
	int middle = (posfrom+posto)/2;
	if (to <= middle)  return val(from,to,2*i,posfrom,middle);
	if (from > middle) return val(from,to,2*i+1,middle+1,posto);
	node left  = val(from,middle,2*i,posfrom,middle);
	node right = val(middle+1,to,2*i+1,middle+1,posto);
	node ret;
	combine(ret,left,right);
	return ret;
}

node query(int from, int to)
{
	if (from>to || !to || from>n) return {0};
	return val(from,to,1,1,n);
}

void read(int i, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		scanf("%d",&tree[i].full);
		tree[i].start = tree[i].end = tree[i].sum = tree[i].full;
		return;
	}
	read(2*i,posfrom,(posfrom+posto)/2);
	read(2*i+1,(posfrom+posto)/2+1,posto);
	combine(tree[i],tree[2*i],tree[2*i+1]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=1; i<=t; i++)
	{
		scanf("%d",&n);
		read(1,1,n);
		scanf("%d",&q);
		for (int i=0; i<q; i++)
		{
			scanf("%d%d%d%d",&s1,&e1,&s2,&e2);
			if (e1<s2) printf("%d\n",query(s1,e1).end + query(e1+1,s2-1).sum + query(s2,e2).start);
			else
			{
				node left  = query(s1,s2-1);
				node mid   = query(s2,e1);
				node right = query(e1+1,e2);
				printf("%d\n",max({left.end+mid.start, left.end+mid.sum+right.start, mid.full, mid.end+right.start}));
			}
		}
	}
	return 0;
}

/*
	if (e1 < s2)
		end1 + sum + start2
	max{ end(s1,s2-1)+start(s2,e1), end(s1,s2-1)+sum(s2,e1)+start(e1+1,e2), full(s2,e1), end(s2,e1)+start(e1+1,e2) }
*/
