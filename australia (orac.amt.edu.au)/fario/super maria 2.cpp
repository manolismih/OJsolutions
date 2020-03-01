#include "carriage_lib.h"
#include <algorithm>
#include <cstdio>
using namespace std;

int n,ask,turn, dp[1000005], choice[1000005];

int binary(int from, int to)
{
	int n = to-from+1;
	while (to-from>1)
	{
		int mid = (from+to)/2;
		if (dp[n-mid-1] > turn+dp[mid]) from=mid;
		else to=mid;
	}
	if (max(dp[n-from-1],turn+dp[from]) < max(dp[n-to-1],turn+dp[to])) return from;
	else return to;
}
int main()
{
	n = carriage_nb_cells();
	ask = carriage_open_cost();
	turn = carriage_reverse_cost();
	dp[0] = -turn;
	choice[1] = 0;
	dp[1] = ask;
	for (int i=2; i<=n; i++)
	{
		choice[i] = binary(0,i-1);
		dp[i] = ask+max(dp[i-choice[i]-1],turn+dp[choice[i]]);
	}
	
	int dir=1,ans;
	while (1)
	{
		carriage_move(choice[n]*dir);
		ans = carriage_open();
		if (ans*dir>0) n -= choice[n]+1;
		else
		{
			dir *= -1;
			n = choice[n];
		}
		carriage_move(dir);
	}
}
