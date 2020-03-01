#include <cstdio>
#include <algorithm>
using namespace std;

int t,stalls, cows,pos[100005];

bool check(int dist)
{
	int prev=pos[0], remain=cows-1;
	for (int i=1; i<stalls && remain>0; i++)
		if (pos[i]-prev>=dist)
		{
			remain--;
			prev=pos[i];
		}
	return !remain;
}

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d",&stalls,&cows);
		for (int i=0; i<stalls; i++)
			scanf("%d",&pos[i]);
		sort(pos,pos+stalls);
		
		int lo=0, hi=pos[stalls-1], mid;
		while(lo<hi)
		{
			mid = (lo+hi)/2 + 1;
			if (check(mid)) lo=mid;
			else hi=mid-1;
		}
		printf("%d\n",lo);
	}
}
