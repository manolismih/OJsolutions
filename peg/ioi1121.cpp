#include <cstdio>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

struct node{int to,dist;};
bool operator<(node a, node b) {return a.dist>b.dist;}

int n,m,exits,vis[100005];
list<node> alist[100005];
priority_queue<node> oura;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&exits);
	node temp;
	for (int from,i=0; i<m; i++)
	{
		scanf("%d%d%d",&from,&temp.to,&temp.dist);
		alist[from].push_back(temp);
		swap(from,temp.to);
		alist[from].push_back(temp);
	}
	temp.dist = 0;
	for (int i=0; i<exits; i++)
	{
		scanf("%d",&temp.to);
		vis[temp.to] = 1;
		oura.push(temp);
	}
	
	while (!oura.empty())
	{
		node curr = oura.top();
		oura.pop();
		if (++vis[curr.to] != 2) continue;
		if (!curr.to)
		{
			printf("%d\n",curr.dist);
			return 0;
		}
		for (auto it:alist[curr.to])
			if (vis[it.to] < 2)
				oura.push({it.to,curr.dist+it.dist});
	}
	return 0;
}
