/*
ID:manolis2
PROG:wormhole
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");
int n, apantisi=0;
bool used[12];
bitset<12> processing, visited;
struct hole{
	int x,y,next,pair;
};
hole holes[12];

bool compy(hole a, hole b)
{
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void check()
{
	visited.reset();
	for (int v=0, i=0; i<n; v=++i)
	{
		processing.reset();
		while (v != -1)
		{
			if (processing[v])
			{
				apantisi++;
				return;
			}
			if (visited[v]) break;
			processing.set(v);
			v = holes[holes[v].pair].next; 
		}
		visited |= processing;
	}
}

void pairgen(int pair)
{
	if (pair == n/2)
	{
		check();
		return;
	}
	int a,i=0;
	while (used[i++]);
	a = i-1;
	used[a] = true;
	for (; i<n; i++)
		if (!used[i])
		{
			used[i] = true;
			holes[a].pair = i;
			holes[i].pair = a;
			pairgen(pair+1);
			used[i] = false;
		}
	used[a] = false;
}

int main()
{
	fin >> n;
	for (int i=0; i<n; i++)
		fin >> holes[i].x >> holes[i].y;
	sort(holes,holes+n,compy);
	for (int i=0; i<n-1; i++)
		holes[i].next = holes[i+1].y == holes[i].y ? i+1 : -1;
	holes[n-1].next = -1;
	pairgen(0);
	fout << apantisi << endl;
	return 0;
}

