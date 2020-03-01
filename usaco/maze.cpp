/*
ID:manolis2
PROG:maze1
LANG:C++11
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

FILE *input = fopen("maze1.in","r");
FILE *output = fopen("maze1.out","w");
int w, h;
bool map[100][38][4], visited[100][38][2];
int apostaseis[100][38][2];
int moves[4][2] = {{0,-1},{-1,0},{0,1},{1,0}}, exits[2][2], exiti=0;

struct komvos{
	int y,x,dist;
};
queue<komvos> oura;

inline komvos tokomvos(int grami, int stili, int apostasi)
{
	komvos node = {grami,stili,apostasi};
	return node;
}

void bfs(int exit)
{
	oura.push(tokomvos(exits[exit][0],exits[exit][1],1));
	komvos* v;
	while (!oura.empty())
	{
		v = &oura.front();
		apostaseis[v->y][v->x][exit] = v->dist;
		for (int i=0; i<4; i++)
			if (map[v->y][v->x][i] && !visited[v->y + moves[i][0]][v->x + moves[i][1]][exit])
			{
				oura.push(tokomvos(v->y + moves[i][0], v->x + moves[i][1], v->dist + 1));
				visited[v->y + moves[i][0]][v->x + moves[i][1]][exit] = true;
			}
		oura.pop();
	}
}

int main()
{
	char c=0;
	fscanf(input,"%i%i",&w,&h);
	for (int y=0; y<2*h+1; y++)
		if (y % 2 == 0)
		{
			for (int x=0; x<w; x++)
				{
					c = fgetc(input);
					if (c == '\n')
						fgetc(input);
					c = fgetc(input);
					if (c == ' ')
					{
						if (y/2 - 1 >= 0)
							map[y/2-1][x][3] = true;
						else
						{
							exits[exiti][1] = x;
							exits[exiti][0] = y/2;
							exiti++;
							continue;
						}
						if (y/2 < h)
							map[y/2][x][1] = true;
						else
						{
							exits[exiti][1] = x;
							exits[exiti][0] = y/2-1;
							exiti++;
							map[y/2-1][x][3] = false;
						}
					}
				}
			fgetc(input);
		}	
		else
			for (int x=0; x<=w; x++)
			{
				c = fgetc(input);
				if (c == '\n')
					c = fgetc(input);
				fgetc(input);
				if (c == ' ')
				{
					if (x-1 >= 0)
						map[y/2][x-1][2] = true;
					else
					{
						exits[exiti][1] = x;
						exits[exiti][0] = y/2;
						exiti++;
						continue;
					}
					if (x < w)
						map[y/2][x][0] = true;
					else
					{
						exits[exiti][1] = x-1;
						exits[exiti][0] = y/2;
						exiti++;
						map[y/2][x-1][2] = false;
					}
				}
			}
				
	bfs(0);
	bfs(1);
	int apantisi=0;
	for (int y=0; y<h; y++)
		for (int x=0; x<w; x++)
			if (min(apostaseis[y][x][0],apostaseis[y][x][1]) > apantisi)
				apantisi = min(apostaseis[y][x][0],apostaseis[y][x][1]);
	fprintf(output,"%i\n",apantisi);
	return 0;
}

