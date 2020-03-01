#include <cstdio>
#include <algorithm>
using namespace std;
#define no -2000000000

struct node{
	int lazy;
	long long sum, maxsum;
	node *l, *r;
	node& left()
	{
		if (!l) l = new node{no};
		return *l;
	}
	node& right()
	{
		if (!r) r = new node{no};
		return *r;
	}
	void propagate(int sl, int sr)
	{
		if (lazy == no) return;
		left().lazy = right().lazy = lazy;
		l->sum = l->maxsum = lazy*sl;
		r->sum = r->maxsum = lazy*sr;
		lazy = no;
	}
};
node root={no};
int n;

void change(int from, int to, int val, node &curr=root, int posfrom=1, int posto=n)
{
	if (from==posfrom && to==posto)
	{
		curr.lazy = val;
		curr.sum = curr.maxsum = (long long)(posto-posfrom+1)*val;
		return;
	}
	int middle = (posfrom+posto)/2;
	curr.propagate(middle-posfrom+1,posto-middle);
	if (from <= middle) change(from,min(to,middle),val,curr.left(),posfrom,middle);
	if (to > middle) change(max(middle+1,from),to,val,curr.right(),middle+1,posto);
	curr.sum = curr.left().sum + curr.right().sum;
	curr.maxsum = max(curr.left().maxsum, curr.left().sum+curr.right().maxsum);
}

int q(int h, node &curr=root, int posfrom=1, int posto=n)
{
	if (curr.maxsum <= h) return posto-posfrom+1;
	if (posfrom==posto) return 0;
	int middle = (posfrom+posto)/2;
	curr.propagate(middle-posfrom+1,posto-middle);
	if (curr.left().maxsum > h) return q(h,curr.left(),posfrom,middle);
	return middle-posfrom+1 + q(h-curr.left().sum,curr.right(),middle+1,posto);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	char c;
	int n1, n2, n3;
	while (scanf(" %c%d",&c,&n1) && c!='E')
	{
		if (c=='I')
		{
			scanf("%d%d",&n2,&n3);
			change(n1,n2,n3);
		}
		else printf("%d\n",q(n1));
	}
	return 0;
}

