#include <cstdio>
#include <algorithm>
using namespace std;

int n,l,k,m, hand[100005][2]; //[left][right]
int ncomps=0, grames,circles, comp[100005], numincomp[100005];

void dfs(int v)
{
	comp[v] = ncomps;
	numincomp[ncomps]++;
	if (hand[v][0] && !comp[hand[v][0]]) dfs(hand[v][0]);
}

int main()
{
	scanf("%d%d%d%d",&n,&l,&k,&m);
	for (int a,b,i=0; i<l; i++)
	{
		scanf("%d%d",&a,&b);
		hand[a][0] = b;
		hand[b][1] = a;
	}
	
	for (int i=1; i<=n; i++)
		if (!hand[i][0] && !comp[i])
		{
			ncomps++;
			dfs(i);
		}	
	grames = ncomps;
	for (int i=1; i<=n; i++)
		if (!comp[i])
		{
			ncomps++;
			dfs(i);
		}
	circles = ncomps-grames;
	sort(numincomp+1+grames,numincomp+1+ncomps,greater<int>());
	
	int ans=ncomps;
	for (int i=1; i<=n; i++)
		if (numincomp[i] < m) ans--;
	
	for (int i=1; i<=n; i++)
		if (numincomp[i] >= m)
		if (i<=grames)
			if (numincomp[i]/m - 1 > k)
			{
				ans += k;
				goto end;
			}
			else
			{
				ans += numincomp[i]/m - 1;
				k -= numincomp[i]/m - 1;
			}
		else
			if (k<2) goto end;
			else
			{
				k--;
				if (numincomp[i]/m -1 > k)
				{
					ans += k;
					goto end;
				}
				else
				{
					ans += numincomp[i]/m - 1;
					k -= numincomp[i]/m - 1;
				}
			}
		
	end:
	printf("%d\n",ans);	
}
