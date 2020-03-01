/*
ID:manolis2
PROG:combo
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");
int n, a[3];
set<int> f[3];

int myhash(int number)
{
	if (number == 0 || number == -1)
		return number+n;
	if (number == n+1 || number == n+2)
		return number%n;
	return number;
}

int main()
{
	fin >> n;
	if (n==1)
	{
		fout << 1 << endl;
		return 0;
	}
	int number;
	for (int i=0; i<3; i++)
	{
		fin >> number;
		for (int j=-2; j<=2; j++)
			f[i].insert(myhash(number+j));
	}
	for (int i=0; i<3; i++)
	{
		fin >> number;
		for (int j=-2; j<=2; j++)
			if (f[i].find(myhash(number+j)) == f[i].end())
				a[i]++;
	}
	int p = n>=5 ? 5 : n;
	fout << p*p*p + a[0]*p*p + (p-a[0])*(p-a[1])*a[2] + (p-a[0])*a[1]*p << endl;
	return 0;
}

