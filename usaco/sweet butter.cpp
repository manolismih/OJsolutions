/*
ID:manolis2
PROG:butter
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");
int cows, pastures, paths, cowpos[500], distances[800][800]; // distances[from][to]
int visited[800];
struct node{
	int v, dist;
};
bool operator< (node a, node b)
{
	return a.dist > b.dist;
}
node tonode(int v, int dist)
{
	node ret={v,dist};
	return ret;
}
vector<node> alist[800]; // alist[from][i].(to || dist)
priority_queue<node> oura;

int main()
{
	fin >> cows >> pastures >> paths;
	for (int i=0; i<cows; i++)
	{
		fin >> cowpos[i];
		cowpos[i]--;
	}	
	for (int i=0, v1, v2, dist; i<paths; i++)
	{
		fin >> v1 >> v2 >> dist;
		alist[v1-1].push_back(tonode(v2-1,dist));
		alist[v2-1].push_back(tonode(v1-1,dist));
	}
	for (int i=0; i<cows; i++)
	{
		oura.push(tonode(cowpos[i],0));
		while (!oura.empty())
		{
			node curr=oura.top();
			oura.pop();
			if (visited[curr.v] == i+1)
				continue;
			visited[curr.v] = i+1;
			distances[cowpos[i]][curr.v] = curr.dist;
			for (int j=0; j<alist[curr.v].size(); j++)
				if (visited[alist[curr.v][j].v] != i+1)
					oura.push(tonode(alist[curr.v][j].v,curr.dist + alist[curr.v][j].dist));
		}
	}
	int apantisi=2000000000, sum;
	bool found;
	for (int i=0; i<pastures; i++)
	{
		sum=0, found=true;
		for (int j=0; found && j<cows; j++)
		{
			sum += distances[cowpos[j]][i];
			if (sum >= apantisi)
				found = false;
		}
		if (found)
			apantisi = sum;	 
	}
	fout << apantisi << endl;
	return 0;
}

