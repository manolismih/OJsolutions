#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define inf 2000000000
#define f first
#define v second

int n,m, lastmod[5005], proig[5005], time;
long long best[5005], cap[5005][5005];
vector<int> alist[5005];

int dijkstra()
{
	best[1] = inf;
	lastmod[1] = time;
	priority_queue<pair<long long,int>> oura;
	oura.push({inf,1});
	pair<long long,int> curr;
	while (!oura.empty())
	{
		curr = oura.top();
		oura.pop();
		if (curr.f < best[curr.v]) continue;
		if (curr.v == n) return curr.f;
		for (auto next:alist[curr.v])
			if (cap[curr.v][next] && lastmod[next] != time || min(curr.f,cap[curr.v][next]) > best[next])
			{
				proig[next] = curr.v;
				lastmod[next] = time;
				best[next] = min(best[curr.v],cap[curr.v][next]);
				oura.push({best[next],next});
			}
	}
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int v1,v2,cost, i=0; i<m; i++)
	{
		scanf("%d%d%d",&v1,&v2,&cost);
		if (v1==v2) continue;
		if (!cap[v1][v2])
		{
			alist[v1].push_back(v2);
			alist[v2].push_back(v1);	
		}
		cap[v1][v2] += cost;
		cap[v2][v1] += cost;
	}
	long long flow=0, bottleneck;
	for (++time; bottleneck=dijkstra(); ++time)
	{
		flow += bottleneck;
		for (int pos=n; pos>1; pos=proig[pos])
		{
			cap[pos][proig[pos]] += bottleneck;
			cap[proig[pos]][pos] -= bottleneck;
		} 
	}
	printf("%lld\n",flow);
	return 0;
}

