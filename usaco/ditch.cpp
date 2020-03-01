/*
ID:manolis2
PROG:ditch
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream fin("ditch.in");
ofstream fout("ditch.out");
long long apantisi=0;
int n,m,minflow;
bool visited[205];
struct node{
	int v, cap, *rev;
};
list<node> alist[205];

void flow(int v, int currmin)
{
	if (visited[v] || !currmin) return;
	if (v==m)
	{
		minflow = currmin;
		return;
	}
	
	visited[v] = true;
	auto it = alist[v].begin();
	for (; it != alist[v].end(); it++)
	{
		flow(it->v,min(currmin,it->cap));
		if (minflow) break;
	}	
	if (!minflow) return;
	it->cap -= minflow;
	*(it->rev) += minflow;
	return;
}

int main()
{
	fin >> n >> m;
	node temp;
	for (int v, i=0; i<n; i++)
	{
		fin >> v >> temp.v >> temp.cap;
		if (temp.cap && v != temp.v)
		{
			alist[v].push_back(temp);
			alist[temp.v].push_back({v,0,&alist[v].back().cap});
			alist[v].back().rev = &alist[temp.v].back().cap;
		}		
	}
	for (minflow=0; ; minflow=0,memset(visited,0,m+3))
	{
		flow(1,2000000000);
		if (minflow == 0) break;
		apantisi += minflow;	
	}
	fout << apantisi << endl;
	return 0;
}

