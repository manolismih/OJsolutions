#include <cstdio>
#include <queue>
using namespace std;

struct node{
	int y,x,day;
};
queue<node> oura;
int r,c,days, moves[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char pista[2005][2005];

int main()
{
	freopen("oilin.txt","r",stdin);
	freopen("oilout.txt","w",stdout);
	scanf("%d%d%d",&r,&c,&days);
	for (int y=1; y<=r; y++)
		for (int x=1; x<=c; x++)
		{
			scanf(" %c",&pista[y][x]);
			if (pista[y][x] == '$')
				oura.push({y,x,0});		
		}
		
	int y,x;
	while (!oura.empty())
	{
		node &curr = oura.front();
		if (curr.day < days)
			for (int i=0; i<4; i++)
			{
				y = curr.y+moves[i][0];
				x = curr.x+moves[i][1];
				if (pista[y][x] == '.')
				{
					oura.push({y,x,curr.day+1});
					pista[y][x] = '*';
				}
			}
		oura.pop();
	}
	
	for (y=1; y<=r; y++)
	{
		for (int x=1; x<=c; x++)
			printf("%c",pista[y][x]);
		printf("\n");
	}
	return 0;
}

