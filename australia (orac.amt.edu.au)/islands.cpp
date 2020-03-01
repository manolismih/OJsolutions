#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define pos first
#define num second

long long n,l;
pair<long long, long long> house[100005];
vector<pair<long long, long long>> event;
long long ans, change, curr;

int main()
{
	freopen("islandin.txt","r",stdin);
	freopen("islandout.txt","w",stdout);
	scanf("%lld%lld",&n,&l);
	for (long long i=0; i<n; i++)
	{
		scanf("%lld%lld",&house[i].pos,&house[i].num);
		if (house[i].pos <= 2*l+1)
		{
			curr += house[i].num * (house[i].pos-1);
			change -= house[i].num;
			event.push_back({house[i].pos+2*l,-house[i].num});
		}
		else
		{
			curr += house[i].num * (4*l-house[i].pos+1);
			change += house[i].num;
			event.push_back({house[i].pos-2*l,-house[i].num});
		}
		event.push_back({house[i].pos,house[i].num});
	}
	sort(event.begin(),event.end());
	
	ans = curr;
	long long pos=1;
	for (auto next:event)
	{
		//printf("%d %d\n",next.pos,next.num);
		curr += (next.pos-pos)*change;
		ans  = max(ans,curr);
		pos = next.pos;
		change += 2*next.num;
	}
	printf("%lld\n",ans);
	return 0;
}

