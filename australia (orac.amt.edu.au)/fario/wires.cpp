#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, dp[205][205][205], first[105], second[105], num[205];
bool print=0;

int dp(int pos, int up, int down)
{
	if ()
}

void do_dp()
{
	for (int i=0; i<n; i++)
	{
		scanf("%d",&num[i]);
		if (!first[num[i]]) first[num[i]] = i;
		else second[num[i]] = i;
	}
	int ret = dp(0,201,201);
	if (!ret)
	{
		printf("0\n");
		exit(0);
	}
	print=1;
	dp(0,201,201);
	exit(0);
}

int stack[200005], si=0;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	n *= 2;
	if (n<205) do_dp();
	for (int num, i=0; i<n; i++)
	{
		scanf("%d",&num);
		if (!si) stack[si++] = num;
		else if (stack[si-1]==num) si--;
		else stack[si++] = num;
	}
	if (si) printf("0\n");
	else for (int i=0; i<n; i++) printf("1\n");
	return 0;
}

