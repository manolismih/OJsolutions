#include <cstdio>

long long n,money, pos[100005];

bool check(int size)
{
	long long sum=0;
	int from=0, to=size-1, middle=(from+to)/2;
	for (int i=0; i<middle; i++)
		sum += pos[middle]-pos[i];
	for (int i=middle+1; i<=to; i++)
		sum += pos[i]-pos[middle];
	if (sum <= money) return true;	
	while (to < n-1)
	{
		sum -= pos[middle]-pos[from++];
		if (!(size%2)) sum -= pos[middle+1]-pos[middle];
		sum += pos[++to] - pos[++middle];
		if (sum <= money) return true;
	}
	return false;
}

int main()
{
	scanf("%lld%*lld%lld",&n,&money);
	for (int i=0; i<n; i++)
		scanf("%lld",&pos[i]);
		
	int from=1, to=n, curr;
	while (from != to)
	{
		curr = (from+to)/2 + 1;
		if (check(curr)) from = curr;
		else to = curr-1;
	}
	printf("%i\n",from);
	return 0;
}

