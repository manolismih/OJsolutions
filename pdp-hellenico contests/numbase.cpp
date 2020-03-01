#include <cstdio>
#define stop 1000000000000

int n;
long long m[10], ans[10];

void checkNums(long long pol, int x)
{
	for (int i=0; i<n; i++)
		if (ans[i] ==0 && m[i]%pol ==0 && m[i]/pol <x) ans[i]=x;
}

void checkBase(int x)
{
	long long pow=x, pol=x+1;
	while (1)
	{
		pow*=x;
		pol+=pow;
		if (pol>stop) return;
		checkNums(pol,x);	
	}
}

long long check2digits(long long num)
{
	for (long long div=3; div*div <= num; div++)
		if (num%div ==0 && num/div < div-1) return div-1;
	if (num%2 ==0 && 2< num/2 -1) return num/2 -1;
	if (num-1 >= 2) return num-1;
	return num+1;
}

int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%lld",&m[i]);
	
	for (long long x=2; x*x +x +1 <= stop; x++) checkBase(x);
	for (int i=0; i<n; i++)
		if (ans[i]==0) ans[i] = check2digits(m[i]);
	for (int i=0; i<n; i++) printf("%lld\n",ans[i]);
}
