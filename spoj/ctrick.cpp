#include <cstdio>

int t,n, card[20005], tree[80000], passed;

void init(int i, int posfrom, int posto)
{
	if (posfrom==posto) tree[i]=1;
	else
	{
		int middle=(posfrom+posto)/2;
		init(2*i,posfrom,middle);
		init(2*i+1,middle+1,posto);
		tree[i] = tree[2*i]+tree[2*i+1];
	}
}

void put(int val, int seat, int i, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		tree[i]=0;
		card[posfrom] = val;
		return;
	}
	int middle = (posfrom+posto)/2;
	if (tree[2*i]>=seat) put(val,seat,2*i,posfrom,middle);
	else put(val,seat-tree[2*i],2*i+1,middle+1,posto);
	tree[i]--;
}

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d",&n);
		init(1,1,n);
		passed=0;
		for (int i=1; i<=n; i++)
		{
			int seat = passed+i+1, seats = n-i+1;
			if (seat > seats) seat %= seats;
			if (!seat) seat=seats;
			passed = seat-1;
			put(i,seat,1,1,n);
		}
		for (int i=1; i<=n; i++) printf("%d ",card[i]);
		printf("\n");
	}
	return 0;
}

