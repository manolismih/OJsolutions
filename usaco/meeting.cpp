#include <cstdio>
#include <list>
using namespace std;

struct node{
	int v,c,d;
};
list<node> alist[105];
list<int> sorted;

FILE *fin=fopen("meeting.in","r"), *fout=fopen("meeting.out","w");
int n,m,from;
node temp;
bool visited[105], dist[105][10005][2];

void dfs(int v)
{
	visited[v] = true;
	for (auto it=alist[v].begin(); it!=alist[v].end(); it++)
		if (!visited[it->v])
			dfs(it->v);
	sorted.push_front(v);
}

int main()
{
	fscanf(fin,"%i%i",&n,&m);
	for (int i=0; i<m; i++)
	{
		fscanf(fin,"%i%i%i%i",&from,&temp.v,&temp.c,&temp.d);
		alist[from].push_back(temp);
	}
	dfs(1);
	dist[1][0][0] = dist[1][0][1] = true;
	
	for (auto pos=sorted.begin(); pos!=sorted.end(); pos++)
		for (int i=0; i<10001; i++)
			if (dist[*pos][i][0] || dist[*pos][i][1])
				for (auto it=alist[*pos].begin(); it!=alist[*pos].end(); it++)
				{
					if (dist[*pos][i][0])
						dist[it->v][i+it->c][0] = true;
					if (dist[*pos][i][1])
						dist[it->v][i+it->d][1] = true;
				}
				
	for (int i=0; i<10001; i++)
		if (dist[n][i][0] && dist[n][i][1])
		{
			fprintf(fout,"%i\n",i);
			return 0;
		}
	fprintf(fout,"IMPOSSIBLE\n");
	return 0;
}

