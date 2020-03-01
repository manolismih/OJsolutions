/*
ID:manolis2
PROG:starry
LANG:C++
*/
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int col,row, pista[105][105], ymin,ymax,xmin,xmax,cluster=1;
char match[505],c;
class key{
	private:
		int height, width;
		string s;
	public:
		key(int y0, int x0, int y1, int x1, int id)
		{
			for (int y=y0; y<=y1; y++)
				for (int x=x0; x<=x1; x++)
					s += (pista[y][x]==id ? 1 : 0);
			height = y1-y0+1;
			width = x1-x0+1;
		}
		void rotate()
		{
			string temp;
			for (int x=0; x<width; x++)
				for (int y=height-1; y>-1; y--)
					temp += s[y*width + x];
			s = temp;
			swap(height,width);
		}
		void reflect()
		{
			string temp;
			for (int y=height-1; y>-1; y--)
				for (int x=0; x<width; x++)
					temp += s[y*width + x];
			s = temp;
		}
		friend bool operator<(key a, key b);
};
bool operator<(key a, key b)
{
	if (a.s != b.s) return a.s < b.s;
	return a.width < b.width;
}
map<key,char> xartis;

void dfs(int y, int x)
{
	if (pista[y][x] != 1) return;
	pista[y][x] = cluster;
	if (y > ymax) ymax = y;
	if (x < xmin) xmin = x;
	else if (x > xmax) xmax = x;
	dfs(y-1,x);
	dfs(y-1,x+1);
	dfs(y,x+1);
	dfs(y+1,x+1);
	dfs(y+1,x);
	dfs(y+1,x-1);
	dfs(y,x-1);
	dfs(y-1,x-1);
}

int main()
{
	freopen("starry.in","r",stdin);
	freopen("starry.out","w",stdout);
	scanf("%d%d",&col,&row);
	for (int y=1; y<=row; y++)
		for (int x=1; x<=col; x++)
		{
			scanf(" %c",&c);
			pista[y][x] = c-'0';
		}
		
	c='a';
	for (int y=1; y<=row; y++)
		for (int x=1; x<=col; x++)
			if (pista[y][x]==1)
			{
				xmin = xmax = x;
				ymin = ymax = y;
				cluster++;
				dfs(y,x);
				key curr(ymin,xmin,ymax,xmax,cluster);
				if (xartis[curr]) match[cluster] = xartis[curr];
				else
				{
					match[cluster] = c;
					xartis[curr] = c;
					for (int i=0; i<3; i++)
					{
						curr.rotate();
						xartis[curr] = c;
					}
					curr.reflect();
					for (int i=0; i<3; i++)
					{
						curr.rotate();
						xartis[curr] = c;
					}
					c++;
				}
			}
			
	match[0] = '0';
	for (int y=1; y<=row; y++)
	{
		for (int x=1; x<=col; x++)
			printf("%c",match[pista[y][x]]);
		printf("\n");
	}	
	return 0;
}

