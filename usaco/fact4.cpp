/*
ID:manolis2
PROG:fact4
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");
int n;
vector<int> upoloipa[4222]; // upoloipa[paragontas paragontikou (1,2,3..6 gia 6!)][psifio pou psaxnoume gia mh 0]

int main()
{
	fin >> n;
	if (n==0)
	{
		fout << 1 << endl;
		return 0;
	}
	for (int i=1; i<=n; i++)
		upoloipa[i].push_back(0);
	upoloipa[1].push_back(1);
	for (int i=2; i<=n; i++)
		upoloipa[i].push_back(0);
	
	bool found, foundnonzero;
	int digit;
	for (int pos=1; ; pos++)
	{
		digit = 0;
		for (int factor=1; factor<=n; factor++)
		{
			digit = digit*factor + upoloipa[factor][pos];
			upoloipa[factor].push_back(digit/10);
			digit %= 10;
		}
		if (digit)
		{
			fout << digit << endl;
			return 0;
		}
	}
	return 0;
}

