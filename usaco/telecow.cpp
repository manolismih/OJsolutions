/*
ID:manolis2
PROG:telecow
LANG:C++11
*/
#include <fstream>
#include <list>
#include <sstream>
using namespace std;

list<int> *alist = new list<int>[205] + 102;
int n,m,source,sink,t, *vis = new int[205]() + 102, *removed = new int[205]() + 102;
int **cap = new int*[205] + 102, **init = new int*[205] + 102;

void add(int from, int to)
{
	if (from==-source || to==-source || from==sink || to==sink) return;
	cap[from][to] = 1;
	alist[from].push_back(to);
	alist[to].push_back(from);
}

int dfs(int v)
{
	if (v==-sink) return 1;
	vis[v] = t;
	for (auto next:alist[v])
		if (!removed[next] && vis[next]!=t && cap[v][next] && dfs(next))
		{
			cap[v][next]--;
			cap[next][v]++;
			return 1;
		}
	return 0;
}

int flow()
{
	int ret=0;
	for (t++; dfs(source); t++) ret++;
	return ret;
}

int main()
{
	ifstream fin("telecow.in");
	ofstream fout("telecow.out");
	for (int i=-100; i<=100; i++)
	{
		cap[i] = new int[205]() + 102;
		init[i] = new int[205]() +102;
	} 
	fin >> n >> m >> source >> sink;
	for (int v1,v2, i=0; i<m; i++)
	{
		fin >> v1 >> v2;
		add(v1,-v2);
		add(v2,-v1);
	}
	for (int i=1; i<=n; i++) add(-i,i);
	
	for (int i=-n; i<=n; i++)
			for (int j=-n; j<=n; j++)
				init[i][j] = cap[i][j];
		
	int totalf=flow();
	fout << totalf << endl;
	stringstream ans;
	for (int i=1; i<=n && totalf; i++)
	{
		if (i==source || i==sink) continue;
		for (int i=-n; i<=n; i++)
			for (int j=-n; j<=n; j++)
				cap[i][j] = init[i][j];
		removed[i] = removed[-i] = 1;
		if (flow() < totalf) totalf--, ans << i << ' ';
		else removed[i] = removed[-i] = 0;
	}
	string s = ans.str();
	s.pop_back();
	fout << s << endl;
	return 0;
}
