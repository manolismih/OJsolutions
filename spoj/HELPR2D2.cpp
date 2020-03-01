#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

int t,n,k, tree[4000000], used, wasted;

void add(int val, int i=1, int posfrom=1, int posto=100000)
{
	if (posfrom==posto) tree[i] += val;
	else 
	{
		if (k-tree[2*i] >= val) add(val,2*i,posfrom,(posfrom+posto)/2);
		else add(val,2*i+1,(posfrom+posto)/2 +1,posto);
		tree[i] = min(tree[2*i],tree[2*i+1]);
	}
}

int findans(int i=1, int posfrom=1, int posto=100000)
{
	if (posfrom==posto)
		if (tree[i])
		{
			used++;
			wasted += k-tree[i];
			return 1;
		} 
		else return 0;
	if (findans(2*i,posfrom,(posfrom+posto)/2)) findans(2*i+1,(posfrom+posto)/2+1,posto);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		memset(tree,0,4000000*4);
		used = wasted = 0;
		scanf("%d%d",&k,&n);
		char c;
		int num, ogos;
		for (int i=0; i<n;)
		{
			scanf(" %c",&c);
			if (isalpha(c)) scanf("%d%d",&num,&ogos);
			else
			{
				ungetc(c,stdin);
				scanf("%d",&ogos);
				num = 1;
			}
			i += num;
			for (int i=0; i<num; i++) add(ogos);
		}
		findans();
		printf("%d %d\n",used,wasted);
	}
	return 0;
}

