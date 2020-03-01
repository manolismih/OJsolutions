/*
ID:manolis2
PROG:agrinet
LANG:C++
*/

#include <cstdio>
#include <queue>

using namespace std;

FILE *fin = fopen("agrinet.in","r"), *fout  = fopen("agrinet.out","w");
struct node{
	int komvos,dist;
};
inline bool operator<(node a, node b)
{
	return a.dist>b.dist;
}
inline node tonode(int komvos, int dist)
{
	node ret={komvos,dist};
	return ret;
}

int n,amatrix[100][100], msp=0;
priority_queue<node> oura;
bool visited[100];

int main()
{
	fscanf(fin,"%i",&n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			fscanf(fin,"%i",&amatrix[i][j]);
	oura.push(tonode(0,0));
	int v;
	for (int i=0; i<n;  i++)
	{
		v = oura.top().komvos;
		if (visited[v])
		{
			i--;
			oura.pop();
			continue;
		}
		visited[v] = true;		
		msp += oura.top().dist;
		oura.pop();
		for (int j=0; j<n; j++)
			if (amatrix[v][j])
				oura.push(tonode(j,amatrix[v][j]));
	}
	fprintf(fout,"%i\n",msp);
	return 0;
}
