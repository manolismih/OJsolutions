#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

ifstream fin("maintain.in");
ofstream fout("maintain.out");
int n,w,nvisited,i, inmst[6005], visited[205];
long long mst;
bool canignore=false;
struct node{
	int v, dist, id;
};
bool operator<(node a, node b)
{
	return a.dist > b.dist;
}
list<node> alist[205];
priority_queue<node> oura;

void findmst()
{
	nvisited = mst = 0;
	node temp = {1,0,6003};
	oura.push(temp);
	while (!oura.empty())
	{
		node curr = oura.top();
		oura.pop();
		if (visited[curr.v] == i) continue;
		visited[curr.v] = i;
		nvisited++;
		inmst[curr.id] = i;
		mst += curr.dist;
		for (list<node>::iterator it = alist[curr.v].begin(); it != alist[curr.v].end(); it++)
			if ((!canignore || inmst[it->id] == i-1) && visited[it->v] != i)
				oura.push(*it);	
	}
	if (nvisited != n)
		mst = -1;
}

int main()
{
	fin >> n >> w;
	node temp = {0,0,0};
	int from;
	for (i=0; i<w; i++, temp.id++)
	{
		fin >> from >> temp.v >> temp.dist;
		alist[from].push_front(temp);
		swap(temp.v,from);
		alist[from].push_front(temp);
		inmst[i]=i-1;
		if (i<n-2)
			fout << -1 << endl;
		else
		{
			findmst();
			fout << mst << endl;
			if (mst != -1)
				canignore = true;
		}	
	}
	return 0;
}

