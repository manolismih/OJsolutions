#include <cstdio>
#include <cmath>
using namespace std;

int n,k, pos[100005];

int main()
{
	freopen("frogin.txt","r",stdin);
	freopen("frogout.txt","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1; i<n; i++)
	{
		scanf("%d",&pos[i]);
		pos[i] += pos[i-1];
	}
	
	long long from = -5000000000, to = 5000000000, curr,left,right;
	bool found=false;
	while (to-from > 1)
	{
		curr = (from+to)/2;
		left = right = 0;
		for (int i=0; i<n; i++,curr+=k)
			if (pos[i] < curr) right++;
			else if (pos[i]>curr) left++;
		if (left==right)
		{
			from = (from+to)/2;
			found = true;
			break;
		}
		(right>left ? to : from) = (from+to)/2;
	}
	
	long long best = 9000000000000000000, total;
	for (int i=from; i<=(found ? from : to); i++)
	{
		curr = i, total=0;
		for (int i=0; i<n; i++,curr+=k)
			total += abs(curr-pos[i]);
		if (total < best) best=total;
	}
	printf("%lld\n",best);
	return 0;
}
