#include <cstdio>
#include <queue>
using namespace std;

int n,nlanes,meion,limit;
priority_queue<int,vector<int>,greater<int>> cows, lanes;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&n,&nlanes,&meion,&limit);
	for (int s,i=0; i<n; i++)
	{
		scanf("%d",&s);
		cows.push(s);
	}
	for (int i=0; i<nlanes; i++) lanes.push(0);
	
	int ans=0, bestlane;
	while (!cows.empty())
	{
		bestlane = lanes.top();
		if (cows.top()-bestlane*meion >= limit)
		{
			ans++;
			lanes.pop();
			lanes.push(bestlane+1);
		}
		cows.pop();
	}
	printf("%d\n",ans);
	return 0;
}

