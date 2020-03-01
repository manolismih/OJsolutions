#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, x[20005], y[20005], dp[2][2005][2];

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i] += 1000;
		y[i] += 1000;
	}
	x[0] = y[0] = 1000;

	for (int m=n-1; m>=0; m--)
		for (int pos=0; pos<=2000; pos++)
		{
			dp[m%2][pos][0] = min( abs(y[m]-y[m+1]) +dp[(m+1)%2][pos] [0], 
								   abs(pos-x[m+1])  +dp[(m+1)%2][y[m]][1] );
			dp[m%2][pos][1] = min( abs(x[m]-x[m+1]) +dp[(m+1)%2][pos] [1],
								   abs(pos-y[m+1])  +dp[(m+1)%2][x[m]][0] );							   
		}
	printf("%d\n",min(dp[0][1000][0], dp[0][1000][1]));
	return 0;
	
	/*
	dp[message][pos][x/y]
	dp[message][x][0] = min(
		dp[message+1][x][0] + |y-y[message+1]| 
		dp[message+1][y[message]][1] + |x-x[message+1]|
	dp[message][y][1] = min(
		dp[message+1][y][1] + |x-x[message+1]|
		dp[message+1][x[message]] + |y-y[message]|
	*/
}

