/*
ID:manolis2
PROG:stamps
LANG:C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");
int n,k,stamps[50];
vector<int> memo;

int main()
{
	fin >> k >> n;
	for  (int i=0; i<n; i++)
		fin >> stamps[i];
	sort(stamps,stamps+n);
	memo.push_back(0);
	int apantisi=0;
	while (memo[apantisi] <= k)
	{
		apantisi++;
		memo.push_back(500);
		for (int i=0; i<n && stamps[i] <= apantisi; i++)
			if (memo[apantisi-stamps[i]] + 1 < memo[apantisi])
				memo[apantisi] = memo[apantisi-stamps[i]] + 1;
	}
	fout << apantisi-1 << endl;
	return 0;
}

