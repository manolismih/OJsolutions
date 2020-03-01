#include <cstdio>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int src,dest,n,m, blue[305],purple[305],best[305],prv[305],rem[305];
bool vis[305], color[305];
list<pair<int,int>> alist[305];

void answer()
{
	printf("%d\n%d\n",best[dest],src);
	list<int> ans;
	for (int v=dest; v!=src; )
	{
		ans.push_front(v);
		v = prv[v];
	}
	for (auto &it:ans) printf("%d\n",it);
	exit(0);
}

int next_v()
{
	int ret=0, small=2e9;
	for (int i=1; i<=n; i++)
		if (!vis[i] && best[i] < small)
		{
			small = best[i];
			ret = i;
		}
	return ret;
}

void info(int t, int v, bool &c, int &tnext)
{
	if (t < rem[v])
	{
		c = color[v];
		tnext = rem[v];
		return;
	}
	c = !color[v];
	tnext = rem[v];
	t -= rem[v];
	tnext += (t/(blue[v]+purple[v]))*(blue[v]+purple[v]);
	t %= (blue[v]+purple[v]);
	int colortime = (c ? purple[v] : blue[v]);
	if (t >= colortime)
	{
		c = !c;
		tnext += blue[v]+purple[v];
	}
	else tnext += colortime;
}

int next_t(int t, int fora, int from, int to)
{
	bool c1,c2;
	int t1,t2;
	info(t,from,c1,t1), info(t,to,c2,t2);
	if (c1==c2) return t;
	if (t1 != t2) return min(t1,t2);
	if (fora==3) return -1;
	return next_t(t1,fora+1,from,to);
}

int main()
{
	scanf("%d%d%d%d",&src,&dest,&n,&m);
	for (int i=1; i<=n; i++)
	{
		char c;
		scanf(" %c%d%d%d",&c,&rem[i],&blue[i],&purple[i]);
		color[i] = (c=='P');
	}
		
	for (int a,b,cost,i=0; i<m; i++)
	{
		scanf("%d%d%d",&a,&b,&cost);
		alist[a].push_back({b,cost});
		alist[b].push_back({a,cost});
	}
	
	for (int i=1; i<=n; i++) best[i] = 2e9;
	best[src] = 0;
	while(1)
	{
		int v = next_v();
		if (!v) break;
		if (v==dest) answer();
		vis[v] = 1;
		
		for (auto &it:alist[v])
		{
			int t = next_t(best[v],1,v,it.first);
			if (t==-1) continue;
			t += it.second;
			if (t<best[it.first])
			{
				best[it.first] = t;
				prv[it.first] = v;
			} 
		}
	}
	printf("0\n");
	return 0;
}
