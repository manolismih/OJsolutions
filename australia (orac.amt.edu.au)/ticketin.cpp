#include <cstdio>
#include <algorithm>
using namespace std;

int dp[100105],p1,d1,p2,d2,n,first,last;
bool tour[100105];

int main()
{
	freopen("ticketin.txt","r",stdin);
	freopen("ticketout.txt","w",stdout);
	scanf("%d%d%d%d%d",&p1,&d1,&p2,&d2,&n);	
	if (n==0)
	{
		printf("0\n");
		return 0;
	}
	scanf("%i",&first);
	tour[1]=true;
	for (int i=1; i<n; i++)
	{
		scanf("%i",&last);
		tour[last-first+1]=true;
	}
	last = last-first+1;
	for (int i=last+1; i<last+105; i++)
		tour[i] = true;
	
	for (int i=last; i>0; i--)
		if (!tour[i])
			dp[i] = (tour[i+1] ? i+1 : dp[i+1]);
		else
		{
			int a = (tour[i+d1] ? dp[i+d1] : dp[dp[i+d1]]) + p1;
			int b = (tour[i+d2] ? dp[i+d2] : dp[dp[i+d2]]) + p2;
			dp[i] = min(a,b);
		}
	printf("%i\n",dp[1]);
	return 0;
}

