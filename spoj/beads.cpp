#include <cstdio>
#include <cstring>
#define ull unsigned long long
#define p 131

int t,n, powof2[14];
ull hsh[20005][14], powofp[20005]={1};
char s[20005];

void reset()
{
	for (int i=0
}

void computehsh(int i)
{
	int l=powof2[i];
	ull h=0, power=powofp[l-1];
	for (int i=0; i<l-1; i++) h = h*p + s[i];
	for (int i=l-1; i<n; i++)
	{
		h = h*p + s[i];
		hsh[i-l+1] = h;
		h -= s[i-l+1]*power;
	}
}

int comp(int a, int b)
{
	int ret=0;
	for (int i=13; i>=0 && hsh[a][i] == hsh[b][i]; i--)
	{
		a += powof2[i];
		b += powof2[i];
		ret += powof2[i];
	}
	return ret;
}

int main()
{
	for (int i=1; i<=10000; i++) powofp[i] = powofp[i-1]*p;
	scanf("%d",&t);
	while (t--)
	{
		scanf(" %s",s);
		n = strlen(s);
		for (int i=n; i<2*n; i++)
			s[i] = s[i-n];
		reset();
			
		for (int i=0,l=1; l<=n; i++,l*=2)
		{
			powof2[i]=l;	
			computehsh(i);
		}
		
		int best=0;
		for (int i=1; i<n; i++)
		{
			int len = comp(best,i);
			if (s[i+len] < s[best+len]) best=i;
		}
		printf("%d\n",best+1);
	}
}
