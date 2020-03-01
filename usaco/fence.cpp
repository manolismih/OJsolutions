/*
ID:manolis2
PROG:fence
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");
int n;
multiset<int> alist[505];
vector<int> revtour;

void findtour(int v)
{
	while (!alist[v].empty())
	{
		int next = *alist[v].begin();
		alist[v].erase(alist[v].begin());
		alist[next].erase(alist[next].find(v));
		findtour(next);
	}
	revtour.push_back(v);
	return;
}

int main()
{
	fin >> n;
	for (int a,b,i=1; i<=n; i++)
	{
		fin >> a >> b;
		alist[a].insert(b);
		alist[b].insert(a);
	}
	for (int i=1; i<=500; i++)
		if (alist[i].size()%2 == 1)
		{
			findtour(i);
			break;
		}
	if (revtour.empty())
		findtour(1);
	for (int i=revtour.size()-1;  i>=0; i--)
		fout << revtour[i] << endl;
	return 0;
}
