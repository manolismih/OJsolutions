#include <cstdio>
#include <algorithm>
using namespace std;

int n,k,l, pos[10000005];
long long left[10000005], right[20000005];

int main()
{
	scanf("%d%d%d",&n,&k,&l);
	for (int i=1; i<=n; i++) scanf("%d",&pos[i]);
	
	for (int i=1; i<=n && i<=k; i++) left[i] = 2*pos[i];
	for (int i=k+1; i<=n; i++) left[i] = left[i-k] + 2*pos[i];
	
	for (int i=n; i>n-k && i>0; i--) right[i] = 2*(l-pos[i]);
	for (int i=n-k; i>0; i--) right[i] = right[i+k] + 2*(l-pos[i]); 
	
	long long ans = 9e18;
	for (int i=0; i<=n; i++)
		ans = min({ans, left[i]+right[i+1], left[i]+l+right[i+k+1]});
	printf("%lld\n",ans);
}
