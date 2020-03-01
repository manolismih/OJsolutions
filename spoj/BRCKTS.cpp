#include <cstdio>
#include <algorithm>
using namespace std;

int q,n;
pair<int,int> tree[120000]; //pair< open(, open)>

void combine(pair<int,int> &target, pair<int,int> &a, pair<int,int> &b)
{
	target.second = a.second;
	target.first = b.first;
	if (a.first > b.second) target.first += a.first - b.second;
	else					target.second += b.second - a.first;
}

void read(int i, int posfrom, int posto)
{
	tree[i] = {0,0};
	if (posfrom==posto)
	{
		char c;
		scanf(" %c",&c);
		(c == '(' ? tree[i].first : tree[i].second) = 1;
		return;
	}
	read(2*i,posfrom,(posfrom+posto)/2);
	read(2*i+1,(posfrom+posto)/2+1,posto);
	combine(tree[i],tree[2*i],tree[2*i+1]);
}

void change(int pos, int i=1, int posfrom=1, int posto=n)
{
	if (posfrom==posto) swap(tree[i].first,tree[i].second);
	else
	{
		if (pos <= (posfrom+posto)/2) change(pos,2*i,posfrom,(posfrom+posto)/2);
		else change(pos,2*i+1,(posfrom+posto)/2+1,posto);
		combine(tree[i],tree[2*i],tree[2*i+1]);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	for (int i=1; i<=10; i++)
	{
		printf("Test %d:\n",i);
		scanf("%d",&n);
		read(1,1,n);
		scanf("%d",&q);
		for (int pos, i=0; i<q; i++)
		{
			scanf("%d",&pos);
			if (pos) change(pos);
			else printf(tree[1].first || tree[1].second ? "NO\n" : "YES\n");
		}
	}
	return 0;
}

