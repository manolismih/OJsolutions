/*
ID:manolis2
PROG:theme
LANG:C++11
*/
#include <set>
#include <fstream>
#include <iostream>
#define mod 18014398509481989
using namespace std;

ifstream fin("theme.in");
ofstream fout("theme.out");
long long n, music[5005];
long long source, power[3000];

struct node{
	long long val;
	int start;
};
bool operator<(node a, node b)
{
	return a.val < b.val;
}
set<node> prints;

int main()
{
	fin >> n;
	for (int i=0; i<n; i++)
		fin >> music[i];
	for (int i=n-1; i>0; i--)
		music[i] -= music[i-1]-90;
	music[0] = 0;
	
	power[0] = 1;
	for (int i=1; i<=n/2 + 1; i++)
		power[i] = (power[i-1]*175) % mod;
		
	int i=0, start=0, finish=n/2, curr;
	bool found;
	while (start != finish)
	{
		source = 0;
		found = false;
		prints.clear();
		curr = (start+finish)/2 + 1;
		
		for (i=1; i<curr; i++)
			source = (source*175 + music[i]) % mod;
		prints.insert({source,0});
		for (; i < n; i++)
		{
			source = (source - music[i-curr+1]*power[curr-2]) % mod;
			if (source < 0) source += mod;
			source = (source*175 + music[i]) % mod;
			pair<set<node>::iterator,bool> result = prints.insert({source,i-curr+1});
			if (!result.second && i-curr+2 > result.first->start + curr)
			{
				found = true;
				break;
			}
		}
		found ? start=curr : finish=curr-1;
	}
	fout << (start>4?start:0) << endl;	
	return 0;
}

