#include <cstdio>
#include <queue>
#include <algorithm>
#define inf 2000000000
using namespace std;

int n,speed,xarx,yarx,xtel,ytel,moves[4][2]={{0,-1},{1,0},{0,1},{-1,0}},times[805][805],best[805][805];
struct node {short y,x; int time;};
bool operator<(node a, node b)
{
	return min(a.time,times[a.y][a.x]) < min(b.time,times[b.y][b.x]);
}
queue<node> oura;

int main()
{
	scanf("%d%d",&n,&speed);
	for (int x=0; x<n+2; x++) times[0][x] = times[n+1][x] = -inf;
	for (int y=0; y<n+2; y++) times[y][0] = times[y][n+1] = -inf;
	char c;
	for (int y=1; y<=n; y++)
		for (int x=1; x<=n; x++)
		{
			best[y][x]=-1;
			scanf(" %c",&c);
			if (c == 'T') times[y][x] = -inf;
			else if (c == 'H') oura.push({y,x,-1}), times[y][x] = -1;
			else if (c == 'M') xarx=x, yarx=y;
			else if (c == 'D') xtel=x, ytel=y, times[y][x] = inf;
		}
		
	while (!oura.empty())
	{
		node &curr = oura.front();
		for (int i=0; i<4; i++)
			if (!times[curr.y+moves[i][0]][curr.x+moves[i][1]])
			{
				times[curr.y+moves[i][0]][curr.x+moves[i][1]] = curr.time+speed;
				oura.push({curr.y+moves[i][0],curr.x+moves[i][1],curr.time+speed});
			}
		oura.pop();
	}
	
	priority_queue<node> oura;
	oura.push({ytel,xtel,inf});
	best[ytel][xtel] = inf;
	while (!oura.empty())
	{
		node curr = oura.top();
		oura.pop();
		if (curr.y == yarx && curr.x == xarx)
		{
			printf("%d\n",curr.time/speed);
			return 0;
		}
		if (curr.time < best[curr.y][curr.x] || !curr.time) continue;
		int y,x;
		for (int i=0; i<4; i++)
		{
			y = curr.y+moves[i][0], x = curr.x+moves[i][1];
			if (times[y][x] >= 0 && min(curr.time-1,times[y][x]) > best[y][x])
			{
				best[y][x] = min(curr.time-1,times[y][x]);
				oura.push({y,x,min(curr.time-1,times[y][x])});
			}
		}
	}
	printf("-1\n");
	return 0;
}
