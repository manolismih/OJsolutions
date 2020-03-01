#include <cstdio>

int n,h[100005],ans;

int main()
{
	freopen("balancein.txt","r",stdin);
	freopen("balanceout.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&h[i]);
	for(int i=1,j=n; i<=j;)
		if(h[i]<h[j])
		{
			h[i+1] += h[i];
			i++;
			ans++;
		}
		else if(h[i]>h[j])
		{
			h[j-1] += h[j];
			j--;
			ans++;
		}
		else
		{
			i++;
			j--;
		}
	printf("%d",ans);
}

