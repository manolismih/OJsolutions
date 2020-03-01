#include <cstdio>

int n,k,apantisi;

int main()
{
	freopen("ninjain.txt","r",stdin);
	freopen("ninjaout.txt","w",stdout);
	scanf("%d%d",&n,&k);
	int i=1;
	while (i+k+1 <= n)
	{
		apantisi += k;
		i += k+1;
	}
	
	if (n==0 || n==1)
		printf("0\n");
	else
		printf("%d\n",apantisi + n - i);
	return 0;
}

