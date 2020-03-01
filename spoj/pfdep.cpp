#include <cstdio>
#include <queue>
#include <list>
using namespace std;

int n,m, in[105], out[105];
priority_queue<int,vector<int>,greater<int>> oura;
list<int> oalist[105];

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int to,q, i=0; i<m; i++)
	{
		scanf("%d%d",&to,&q);
		for (int from, i=0; i<q; i++)
		{
			scanf("%d",&from);
			oalist[from].push_back(to);
			out[from]++;
			in[to]++;
		}
	}
	
	for (int i=1; i<=n; i++)
		if (!in[i]) oura.push(i);
		
	while (!oura.empty())
	{
		int v = oura.top();
		oura.pop();
		printf("%d ",v);
		for (auto next:oalist[v])
			if (!--in[next]) oura.push(next);
	}
	return 0;
}

