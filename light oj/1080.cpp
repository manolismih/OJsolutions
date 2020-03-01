#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,t,q,from,to,pos;
bitset<100005> bits;
bitset<263000> tree;
char c;

void invert(int from, int to, int i, int posfrom, int posto)
{
	if (from == posfrom && to == posto)
	{
		tree.flip(i);
		return;
	}
	int middle = (posfrom+posto)/2;
	if (from <= middle) invert(from,min(to,middle),2*i,posfrom,middle);
	if (to > middle) invert(max(from,middle+1),to,2*i+1,middle+1,posto);
}

bool apantisi(int i, int posfrom, int posto)
{
	if (posfrom == posto) return tree[i];
	int middle = (posfrom+posto)/2;
	return tree[i]^(pos<=middle ? apantisi(2*i,posfrom,middle) : apantisi(2*i+1,middle+1,posto));
}

int main()
{
	scanf("%i",&t);
	for (int i=1; i<=t; i++)
	{
		tree.reset();
		printf("Case %i:\n",i);
		n=0;
		scanf(" %c",&c);
		ungetc(c,stdin);
		while (scanf("%c",&c) && c != '\n')
			bits[++n] = c-'0';
		scanf("%i",&q);
		
		for (int i=0; i<q; i++)
		{
			scanf(" %c",&c);
			if (c=='I')
			{
				scanf("%i%i",&from,&to);
				invert(from,to,1,1,n);
			}
			else
			{
				scanf("%i",&pos);
				printf("%i\n",bits[pos]^apantisi(1,1,n));
			}
		}
	}
	return 0;
}
