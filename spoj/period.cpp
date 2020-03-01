#include <cstdio>
#include <cstring>
#define mod 18014398509481981

char s[1000005];
int t,n, apantisi[1000005];
long long k2[1000005][20], power[1000005]={1}, power2[20]={1};

void mark(int length)
{
	int pos1=1, pos2=length+1, similarity=0, pow;
	while (1)
	{
		for (pow=0; pos2+power[pow]-1<=n && k2[pos1][pow] == k2[pos2][pow]; pow++);
		if (!pow) break;
		pos1 += power2[pow-1], pos2 += power2[pow-1], similarity += power2[pow-1];
	}
	for (int i=2*length; i<=length+similarity; i+=length)
		if (!apantisi[i]) apantisi[i] = i/length;
}

int main()
{
	freopen("period.txt","r",stdin);
	freopen("period.out","w",stdout);
	for (int i=1; i<=20; i++)
		power2[i] = power2[i-1]*2;
	for (int i=1; i<1000001; i++)
		power[i] = (power[i-1]*128) % mod;	
	
	scanf("%i",&t);
	for (int i=1; i<=t; i++)
	{
		memset(apantisi,0,1000005*4);
		printf("Test case #%i\n",i);
		scanf("%i %s",&n,s+1);
		for (int i=1; i<=n; i++)
			k2[i][0] = s[i];
		for (int i=1; i<=n; i++)
			for (int log=1; i+power2[log]-1<=n; log++)
				k2[i][log] = (k2[i][log-1]*power[power2[log-1]] + k2[i+power2[log-1]][log-1]) % mod;
		
		int stop = n/2;
		for (int i=1; i<=stop; i++) mark(i);
		for (int i=1; i<=n; i++)
			if (apantisi[i])
				printf("%i %i\n",i,apantisi[i]);
		printf("\n");
	}
	return 0;
}

