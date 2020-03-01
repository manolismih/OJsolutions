#include <cstdio>
#include <cmath>

long long n, num[200005], pre[200005], post[200005], meion;
double ans=0;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%lld",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&num[i]);
		pre[i] = pre[i-1]+num[i];
	}
	for (int i=n; i>0; i--) post[i] = post[i+1]+num[i];
	
	for (int i=1; i<=n; i++)
	{
		meion += pre[i-1] + post[n-i+2];
		ans += (i*pre[n] - meion) / (double)i;
	}
	ans /= (n*(n+1)/2.0);
	
	double ans2 = trunc(ans);
	printf("%.0f\n",ans2==0 ? 0.0 : ans2);
	return 0;
}

