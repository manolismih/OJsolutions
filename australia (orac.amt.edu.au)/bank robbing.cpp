#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2e9

int n,b, hours[100005], bank[100005];
int brosta[100005], piso[100005];
// bottlenecks, the hardest time limits

int main()
{
	freopen("wherein.txt","r",stdin);
	freopen("whereout.txt","w",stdout);
	scanf("%d%d",&n,&b);
	for (int i=1; i<=b; i++) scanf("%d",&bank[i]);
	for (int i=1; i<n; i++) scanf("%d",&hours[i]);
	
	int bottleneck = inf;
	for (int i=bank[b]-1; i>0; i--)
	{
		bottleneck = min(bottleneck,hours[i]-i);
		brosta[i] = bottleneck+i;
	}
	
	bottleneck = inf;
	for (int i=bank[1]+1; i<=n; i++)
	{
		bottleneck = min(bottleneck,hours[i-1]-n+i);
		piso[i] = bottleneck+n-i;
	}
	
	int ans=0;
	for (int i=1; i<=bank[1]; i++)
		if (brosta[i]>0) ans++;
	for (int i=bank[1]+1; i<bank[b]; i++)
		if (brosta[i]>0 && piso[bank[b]]-bank[b]+i > 0
		|| piso[i]>0 && brosta[bank[1]]-i+bank[1] > 0)
			ans++;
	for (int i=bank[b]; i<=n; i++)
		if (piso[i]>0) ans++;
	if (b==1) ans++;
	printf("%d\n",ans);
}
