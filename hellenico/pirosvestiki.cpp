#include <cstdio>
#include <vector>
#define inf 999999999999999

using namespace std;

FILE *fin = fopen("troodos.in","r"), *fout = fopen("troodos.out","w");
int n, m, visited[10000]; // visited[i] == 0 gia longpath, 1 gia anamones
long long paths[10000][2], anamones[10000], anamoni; // paths[i][0] gia short path, 1 gia long
vector<pair<int,int> > oalist[10000], alist[10000];

long long dp(int v)
{
	if (visited[v] == 0)
		return paths[v][1];
	visited[v] = 0;
	for (vector<pair<int,int> >::iterator it=oalist[v].begin(); it!=oalist[v].end(); it++)
		if (it->second + dp(it->first) > paths[v][1])
			paths[v][1] = it->second + dp(it->first);
	return paths[v][1];
}

long long findanamones(int v)
{
	if (visited[v] == 1 || v==n-1)
		return anamones[v];
	visited[v] = 1;
	anamones[v] = inf;
	for (vector<pair<int,int> >::iterator it = alist[v].begin(); it!= alist[v].end(); it++)
		if (findanamones(it->first) + paths[it->first][1]-paths[v][1]-it->second < anamones[v])
			anamones[v] = findanamones(it->first) + paths[it->first][1]-paths[v][1]-it->second;
	if (anamones[v])
		anamoni++;
	return anamones[v];
}

int main()
{
	fscanf(fin,"%i%i",&n,&m);
	for (int from, to, cost, i=0; i<m; i++)
	{
		fscanf(fin,"%i%i%i",&from,&to,&cost);
		oalist[to].push_back(make_pair(from,cost));
		alist[from].push_back(make_pair(to,cost));
	}
	for (int i=0; i<10000; i++)
		visited[i] = -1;
	dp(n-1);
	for (int i=1; i<n; i++)
	{
		paths[i][0] = inf;
		for (vector<pair<int,int> >::iterator it = oalist[i].begin(); it!=oalist[i].end(); it++)
			if (paths[it->first][1] + it->second < paths[i][0])
				paths[i][0] = paths[it->first][1] + it->second;
	}
	fprintf(fout,"%lli ",paths[n-1][1]);
	for (int i=0; i<n; i++)
		printf("%lli %lli\n",paths[i][0],paths[i][1]);
	anamoni=0;
	for (int i=1; i<n; i++)
		anamoni += paths[i][1]-paths[i][0];
	fprintf(fout,"%lli ",anamoni);
	anamoni = 0;
	findanamones(0);
	fprintf(fout,"%lli\n",anamoni);
	printf("\n\nanamones:\n");
	for (int i=0; i<n; i++)
		printf("%i\n",anamones[i]);
	return 0;
}
