/*
ID:manolis2
PROG:camelot
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define x first
#define y second

using namespace std;

ifstream fin("camelot.in");
ofstream fout("camelot.out");
int r,c,id=1, distances[27][31][27][31], visited[27][31];
int moves[8][2] = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};
vector<pair<int,int> > knights;
pair<int,int> king;
struct node{
	int x,y,dist;
};
inline node tonode(int x, int y, int dist)
{
	node ret = {x,y,dist};
	return ret;
}
queue<node> oura;

inline int tonum(char c)
{
	return c-'A'+1;
}

void bfs(int x, int y)
{
	oura.push(tonode(x,y,0));
	visited[x][y] = id;
	while (!oura.empty())
	{
		node &curr = oura.front();
		distances[x][y][curr.x][curr.y] = curr.dist;
		for (int i=0; i<8; i++)
			if (curr.x+moves[i][0]>0 && curr.x+moves[i][0]<=c 
			&&  curr.y+moves[i][1]>0 && curr.y+moves[i][1]<=r
			&& visited[curr.x+moves[i][0]][curr.y+moves[i][1]] != id)
			{
				oura.push(tonode(curr.x+moves[i][0],curr.y+moves[i][1],curr.dist+1));
				visited[curr.x+moves[i][0]][curr.y+moves[i][1]] = id;
			}
		oura.pop();	
	}
}

int main()
{
	for (int i=1; i<27; i++)
		for (int j=1; j<31; j++)
			for (int k=1; k<27; k++)
				for (int l=1; l<31; l++)
					distances[i][j][k][l] = 200000000;
	int row;
	char col;
	fin >> r >> c >> col >> king.y;
	king.x = tonum(col);
	while (fin >> col >> row)
		knights.push_back(make_pair(tonum(col),row));
	for (int x=1; x<=c; x++)
		for (int y=1; y<=r; y++, id++)
			bfs(x,y);
								
	//pio kontino alogo
	int nearest_horse = 200000000;
	for (auto it=knights.begin(); it!=knights.end(); it++)
		if (max(abs(king.x-it->x),abs(king.y-it->y)) < nearest_horse)
			nearest_horse = max(abs(king.x-it->x),abs(king.y-it->y));
	int apantisi=200000000;
	for (int x=1; x<=c; x++)
		for (int y=1; y<=r; y++)
		{
			int cost=0,best;
			for (auto it=knights.begin(); it!=knights.end(); it++)
				cost += distances[x][y][it->x][it->y];
			best = min(cost+max (abs(king.x-x),abs(king.y-y)) , cost+nearest_horse);
			for (auto it=knights.begin(); it!=knights.end(); it++)
				if (best > cost-distances[x][y][it->x][it->y]+distances[it->x][it->y][king.x][king.y]+distances[king.x][king.y][x][y])
					best = cost-distances[x][y][it->x][it->y]+distances[it->x][it->y][king.x][king.y]+distances[king.x][king.y][x][y];
			if (best < apantisi)
				apantisi = best;
		}
	fout << apantisi << endl;		
	return 0;
}

