#include <cstdio>

int t,n, steps[200005], children[800000], num[800000];

void init(int i, int posfrom, int posto)
{
	if (posfrom==posto)
	{
		children[i] = 1;
		num[i] = n-posfrom+1;
		return;
	}
	int middle = (posfrom+posto)/2;
	init(2*i,posfrom,middle);
	init(2*i+1,middle+1,posto);
	num[i] = 0;
	children[i] = children[2*i]+children[2*i+1];
}

int nth(int n, int i)
{
	children[i]--;
	if (num[i]) return num[i];
	if (n <= children[2*i]) return nth(n,2*i);
	else return nth(n-children[2*i],2*i+1);
}

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d",&n);
		init(1,1,n);
		for (int i=0; i<n; i++)
			scanf("%d",&steps[i]);
		for (int i=n-1; i>-1; i--)
			steps[i] = nth(steps[i]+1,1);
		for (int i=0; i<n-1; i++)
			printf("%d ",steps[i]);
		printf("%d\n",steps[n-1]);
	}
	return 0;
}

