#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int N, M, start, finish, P, Q;
long long dist[60005];
vector<pair<int,int>> alist[60005];

long long dijkstra(int from, int to, bool allowedQ)
{
	set<pair<int,int>> dist_set;
	dist_set.insert(make_pair(0,from));
	while (!dist_set.empty())
	{
		pair<int,int> top = *dist_set.begin();
		dist_set.erase(dist_set.begin());
		if (top.first != dist[top.second]) continue;
		if (!allowedQ && top.second == Q) continue;
		if (top.second == to) return dist[to];
		
		from = top.second;
		for (int i=0; i<alist[from].size(); i++)
			if (dist[from] + alist[from][i].first < dist[alist[from][i].second])
			{
				dist[alist[from][i].second] = dist[from] + alist[from][i].first;
				dist_set.insert(make_pair(dist[alist[from][i].second], alist[from][i].second));
			}
	}
	return 4.2e15;
}

int main()
{
	freopen("supgame.in","r",stdin);
	scanf("%d%d%d%d%d%d",&N,&M,&start,&finish,&P,&Q);
	for (int i=0; i<M; i++)
	{
		int from, to, time;
		scanf("%d%d%d",&from,&to,&time);
		alist[from].push_back(make_pair(time,to));
	}
	for (int i=0; i<=60000; i++) dist[i] = 4.2e15;
	dist[start]=0;
	long long ans1 = dijkstra(start,finish,false);
	
	for (int i=0; i<=60000; i++) dist[i] = 4.2e15;
	dist[start]=0;
	long long ans2 = dijkstra(start,P,false);
	
	for (int i=0; i<=60000; i++) dist[i] = 4.2e15;
	dist[P] = 0;
	ans2 += dijkstra(P,finish,true);
	printf("%lld\n",std::min(ans1,ans2));
}
