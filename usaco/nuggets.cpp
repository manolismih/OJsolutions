/*
ID:manolis2
PROG:nuggets
LANG:C++11
*/
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nuggets.in");
ofstream fout("nuggets.out");
int n, packs[10], minpack=300, apantisi=1;
bool memo[66001];

int main()
{
	fin >> n;
	for (int i=0; i<n; i++)
	{
		fin >> packs[i];
		if (packs[i] < minpack)
			minpack = packs[i];
	}
	
	bool found=false;	
	for (int i=minpack; i>1; i--)
	{
		found=true;
		for (int j=0; found && j<n; j++)
			if (packs[j]%i != 0)
				found = false;
		if (found) break;	
	}
	if (found || minpack==1)
	{
		fout << 0 << endl;
		return 0;
	}
	
	memo[0] = true;
	for (int i=2; i<=66000; i++)
	{
		for (int j=0; j<n && !memo[i]; j++)
			if (i-packs[j]>-1 && memo[i-packs[j]])
				memo[i] = true;
		if (!memo[i])
			apantisi = i;
	}
	fout << apantisi << endl;
	return 0;
}

