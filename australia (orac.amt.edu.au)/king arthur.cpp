#include <list>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin=fopen("arthin.txt","r"), *fout=fopen("arthout.txt","w");
int n, m, apantisi, groups[2];
bool visited[100005];
list<int> alist[100005];

void bfs(int v)
{
	visited[v] = true;
	groups[0] = groups[1] = 0;
	queue<pair<int,bool> > oura;
	oura.push(make_pair(v,0));
	while (!oura.empty())
	{
		pair<int,bool> top = oura.front();
		oura.pop();
		groups[top.second]++;
		for (list<int>::iterator it=alist[top.first].begin(); it!=alist[top.first].end(); it++)
			if (!visited[*it])
			{
				visited[*it] = true;
				oura.push(make_pair(*it,!top.second));
			}
	}
	apantisi += max(groups[0],groups[1]);
}

int main()
{
	fscanf(fin,"%i%i",&n,&m);
	for (int a,b, i=0; i<m; i++)
	{
		fscanf(fin,"%i%i",&a,&b);
		alist[a].push_back(b);
		alist[b].push_back(a);
	}
	
	for (int i=1; i<=n; i++)
		if (!visited[i])
			bfs(i);
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

