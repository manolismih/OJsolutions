#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define inf 2e9

struct akmi{ int to, dist;};
bool operator<(akmi a, akmi b)	{return a.dist>b.dist;}

int t,n,m,arxi,telos, best[10005];

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		vector<akmi> alist[10005];
		for (int i=0; i<10005; i++) best[i]=inf;
		akmi temp;
		
		scanf("%d%d",&n,&m);
		for (int from,i=0; i<m; i++)
		{
			scanf("%d%d%d",&from,&temp.to,&temp.dist);
			alist[from].push_back(temp);
		}
		scanf("%d%d",&arxi,&telos);
		
		temp.dist = best[arxi] = 0;
		temp.to = arxi;
		priority_queue<akmi> oura;
		oura.push(temp);
		while (!oura.empty())
		{
			akmi curr = oura.top();
			oura.pop();
			if (curr.dist > best[curr.to]) continue;
			for (auto it:alist[curr.to])
				if (curr.dist + it.dist < best[it.to])
				{
					best[it.to] = curr.dist + it.dist;
					oura.push({it.to,best[it.to]});
				}
		}
		if (best[telos]==inf) printf("NO\n");
		else printf("%d\n",best[telos]);
	}
}
