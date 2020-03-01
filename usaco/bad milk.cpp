/*
ID:manolis2
PROG:milk6
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <cstring>
using namespace std;

ifstream fin("milk6.in");
ofstream fout("milk6.out");
int n, m, initmatrix[35][35], amatrix[35][35]; //amatrix[from][to]
struct akmi{ // "akmi" is a greek word for "edge"
	int from, to, cost, id;
};
bool comp(akmi a, akmi b)
{
	return a.cost > b.cost;
}
list<akmi> akmes; // "akmes" is the plural for "akmi" and means "edges"

int flow()
{
	//copy the initmatrix into amatrix to leave initmatrix untouched for the next flow() call 
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			amatrix[i][j] = initmatrix[i][j];
	int prev[35], flow[35], ret=0;
	bool visited[35];
	while (1)
	{
		//initialize
		memset(prev,0,35*4), memset(flow,0,35*4), memset(visited,0,35);
		flow[1] = 2100000000;
		//algorithm given by usaco 4.2 theory
		while(1)
		{
			int maxflow=0, maxloc=0;
			for (int i=1; i<=n; i++)
				if (flow[i] > maxflow && !visited[i])
				{
					maxflow = flow[i];
					maxloc = i;
				}
			if (!maxloc) return ret;
			if (maxloc == n) break;
			visited[maxloc] = true;
			for (int i=1; i<=n; i++)
				if (min(amatrix[maxloc][i],maxflow) > flow[i])
				{
					flow[i] = min(amatrix[maxloc][i],maxflow);
					prev[i] = maxloc;
				}
		}
		int cap=flow[n];
		ret += cap;
		for (int pos=n; pos!=1; pos=prev[pos])
		{
			amatrix[pos][prev[pos]] += cap;
			amatrix[prev[pos]][pos] -= cap;
		}
	}	
}

int main()
{
	fin >> n >> m;
	akmi temp;
	//read input and keep a copy for every edge
	for (int i=0; i<m; i++)
	{
		fin >> temp.from >> temp.to >> temp.cost;
		temp.id = i+1;
		akmes.push_back(temp);
		//parallel edges are being merged into 1
		initmatrix[temp.from][temp.to] += temp.cost;
	}
	akmes.sort(comp); // sort the edges by cost
	
	int maxflow = flow();
	fout << maxflow << ' ';
	
	list<int> trucks; // it contains the indices of the trucks stopped
	int newflow;
	//try removing each edge in decreasing and NOT in increasing weight order!!!
	for (auto it=akmes.begin(); it!=akmes.end();)
	{
		initmatrix[it->from][it->to] -= it->cost; //remove only one edge (thus the rest stay merged)
		newflow = flow();
		if (maxflow-newflow == it->cost) // member of min cut?
		{
			maxflow = newflow - initmatrix[it->from][it->to]; // we remove the one merged edge from the newflow	
			initmatrix[it->from][it->to] = 0; //every parallel edge to *it must be removed
			trucks.push_back(it->id);		
			for (auto it2=next(it); it2!=akmes.end();)
				if (it2->from == it->from && it2->to == it->to) //paallel edge to *it
				{
					trucks.push_back(it2->id);
					it2 = akmes.erase(it2);
				}
				else it2++;
			it = akmes.erase(it);
		}
		else // not a member of min cut
		{
			initmatrix[it->from][it->to] += it->cost; //put back again the removed edge
			it++;	
		}
	}
	trucks.sort();
	fout << trucks.size() << endl;
	for (auto it=trucks.begin(); it!=trucks.end(); it++)
		fout << *it << endl;
	return 0;
}
