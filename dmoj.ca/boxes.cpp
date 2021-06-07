#include <algorithm>
#define MAXN 10000005
using namespace std;
typedef long long ll;

ll bros_piso[MAXN];

long long delivery(int N, int K, int L, int positions[]) 
{
	for (int i=0; i<N && positions[i]<=L/2; i++)
		bros_piso[i] = 2*positions[i] + (i-K>=0 ? bros_piso[i-K] : 0);
	if (positions[N-1] <= L/2) return bros_piso[N-1];
	
	ll ans=4.2e18;
	if (K==N) ans=L;
	else if (positions[N-K-1] <= L/2) ans=L+bros_piso[N-K-1];
	for (int i=N-1; i>=1 && positions[i]>=L/2; i--)
	{
		bros_piso[i] = 2*(L-positions[i]) + (i+K<N ? bros_piso[i+K] : 0);
		
		if (positions[i-1] <= L/2) 		ans=min(ans,bros_piso[i]+bros_piso[i-1]);
		else if (i-K-1 < 0) 			ans=min(ans,bros_piso[i]+L);
		else if (positions[i-K-1]<=L/2) ans=min(ans,bros_piso[i]+L+bros_piso[i-K-1]);
	}
	if (positions[0] >= L/2) return 2*(L-positions[0]) + (K<N ? bros_piso[K] : 0);
	return ans;
}
