/*
ID:manolis2
PROG:stall4
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream fin("stall4.in");
ofstream fout("stall4.out");
int n, m, apantisi=0;
bool foundflow=false, visited[405];
struct node{
	int v, cap, *rev;
};
list<node> alist[405];

void flow (int v)
{
	if (v==404)
	{
		foundflow = true;
		return;
	}
	visited[v] = true;
	auto it=alist[v].begin();
	for (; it!=alist[v].end(); it++)
		if (it->cap && !visited[it->v])
		{
			flow(it->v);
			if (foundflow) break;
		}	
	if (!foundflow) return;
	(it->cap)--;
	if (it->rev) (*it->rev)++;
	return;
}

int main()
{
	fin >> n >> m;
	node temp = {0,1,0};
	for (temp.v = 1; temp.v <= n; temp.v++)
		alist[0].push_back(temp);
	temp.v = 404;
	for (int i=201; i<=200+m; i++)
		alist[i].push_back(temp);
	for (int ni, i=1; i<=n; i++)
	{
		fin >> ni;
		for (int j=0; j<ni; j++)
		{
			fin >> temp.v;
			temp.v += 200;
			alist[i].push_back(temp);
			alist[temp.v].push_back({i,0,&alist[i].back().cap});
			alist[i].back().rev = &alist[temp.v].back().cap;
		}
	}
	for (;;foundflow=false,memset(visited,false,405))
	{
		flow(0);
		if (foundflow) apantisi++; 
		else break;
	}
	fout << apantisi << endl;
	return 0;
}

