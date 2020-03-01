/*
ID:manolis2
PROG:marathon
LANG:C++11
*/
#include <cstdio>
#include <cmath>

using namespace std;

FILE *fin=fopen("marathon.in","r"), *fout=fopen("marathon.out","w");
int x[3],y[3], total=0, loss=0, n;

inline int dist(int& ax, int& ay, int& bx, int& by)
{
	return abs(ax-bx) + abs(ay-by);
}

int main()
{
	fscanf(fin,"%d%d%d%d%d",&n,x+1,y+1,x+2,y+2);
	total += dist(x[1],y[1],x[2],y[2]);
	for (int i=2; i<n; i++)
	{
		x[0] = x[1];
		y[0] = y[1];
		x[1] = x[2];
		y[1] = y[2];
		fscanf(fin,"%d%d",x+2,y+2);
		total += dist(x[1],y[1],x[2],y[2]);
		if (dist(x[0],y[0],x[1],y[1]) + dist(x[1],y[1],x[2],y[2]) - dist(x[0],y[0],x[2],y[2]) > loss)
			loss = dist(x[0],y[0],x[1],y[1]) + dist(x[1],y[1],x[2],y[2]) - dist(x[0],y[0],x[2],y[2]);
	}
	
	fprintf(fout,"%i\n",total-loss);
	return 0;
}

