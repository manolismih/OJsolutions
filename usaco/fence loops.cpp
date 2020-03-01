/*
ID:manolis2
PROG:fence6
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

ifstream fin("fence6.in");
ofstream fout("fence6.out");
vector<pair<int,int> > alist[105];
map<pair<int,int>,int> reg;
struct node{
	int v, dist;
};
bool operator<(node a, node b)
{
	return a.dist > b.dist;
}
priority_queue<node> oura;
int n,id=0,apantisi=2000000000, best[105];

int main()
{
	fin >> n;
	int s,length,ne1,ne2,e[9];
	for (int i=0; i<n; i++)
	{
		int vertices[2];
		fin >> s >> length >> ne1 >> ne2;
		for (int k=0; k<2; k++, ne1=ne2)
		{
			for (int j=0; j<ne1; j++)
				fin >> e[j];
			e[ne1++] = s;
			sort(e,e+ne1);
			if (reg.find(make_pair(e[ne1-1],e[ne1-2])) == reg.end())
			{
				reg[make_pair(e[ne1-1],e[ne1-2])] = id++;
				vertices[k] = id-1;
			}
			else
				vertices[k] = reg[make_pair(e[ne1-1],e[ne1-2])];		
		}
		alist[vertices[0]].push_back(make_pair(vertices[1],length));
		alist[vertices[1]].push_back(make_pair(vertices[0],length));
	}
	
	for (int i=0; i<id; i++)
	{
		memset(best,127,4*105);
		for (auto no=alist[i].begin(); no!=alist[i].end(); no++)
		{
			for (auto it=alist[i].begin(); it!=alist[i].end(); it++)
				if (it!=no)
					oura.push({it->first,it->second});
			best[i]=-1;
			while (!oura.empty())
			{
				node curr = oura.top();
				oura.pop();
				if (curr.dist+no->second >= apantisi || curr.dist > best[curr.v]) continue;
				if (curr.v == no->first)
				{
					apantisi = curr.dist + no->second;
					continue;
				}
				for (auto it=alist[curr.v].begin(); it!=alist[curr.v].end(); it++)
					if (curr.dist+it->second < best[it->first])
					{
						best[it->first] = curr.dist+it->second;
						oura.push({it->first,curr.dist+it->second});
					}
			}
		}
	}
	fout << apantisi << endl;
	return 0;
}

