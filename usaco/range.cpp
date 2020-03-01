/*
ID:manolis2
PROG:range
LANG:C++11
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("range.in");
ofstream fout("range.out");
int n,metriseis[255],field[255][255][2];

int main()
{
	char c;
	int count;
	fin >> n;
	for (int i=1; i<=n; i++)
	{
		count=0;
		for (int j=1; j<=n; j++)
		{
			fin >> c;
			field[i][j][0] = (c=='0' ? count=0 : ++count);
		}
	}	
	for (int j=1; j<=n; j++)
	{
		count=0;
		for (int i=1; i<=n; i++)
			field[i][j][1] = (field[i][j][0] ? ++count : count=0);
	}
	
	for (int i=1; i<=n; i++)
		for (int j=1;  j<=n; j++)
			for (int size=1; field[i+size-1][j+size-1][0] >= size && field[i+size-1][j+size-1][1] >= size; size++)
				metriseis[size]++;	
	for (int i=2; i<=n; i++)
		if (metriseis[i])
			fout << i << ' ' << metriseis[i] << endl;
	return 0;
}
