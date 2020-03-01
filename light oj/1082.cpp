#include <cstdio>
#include <algorithm>
using namespace std;

int t,n,q,from,to, k2[100005][20], power[20]={1};

int apantisi()
{
	int ret = 200000, pow;
	while (from <= to)
	{
		for (pow=16; from+power[pow]-1>to; pow--);
		ret = min(ret,k2[from][pow]);
		from += power[pow];
	}
	return ret;
}

int main()
{
	for (int i=1; i<17; i++)
		power[i] = power[i-1] << 1;
	scanf("%i",&t);
	for (int i=1; i<=t; i++)
	{
		printf("Case %i:\n",i);
		scanf("%i%i",&n,&q);
		for (int i=1; i<=n; i++)
			scanf("%i",&k2[i][0]);
			
		for (int pow=1; pow<17; pow++)
			for (int i=0; i+power[pow]-1<=n; i++)
				k2[i][pow] = min(k2[i][pow-1],k2[i+power[pow-1]][pow-1]);
		
		for (int i=0; i<q; i++)
		{
			scanf("%i%i",&from,&to);
			printf("%i\n",apantisi());
		}
	}
	return 0;
}

