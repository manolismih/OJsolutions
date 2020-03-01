/*
ID:manolis2
PROG:kimbits
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
long long length, asoi, ith;
long long memo[32][32]; // [posa bits exoume] [posa einai asoi]
string apantisi;

long long choose(int n, int k)
{
	if (n<k) return 0;
	long double ret = 1;
	if (k > n-k)
	{
		for (int i=k+1; i<=n; i++)
			ret *= i;
		for (int i=2; i<= n-k; i++)
			ret /= i;
	}
	else
	{
		for (int i=n-k+1; i<=n; i++)
			ret *=  i;
		for (int i=2; i<=k; i++)
			ret /= i;
	}
	return ret;
}

int main()
{
	fin >> length >> asoi >> ith;
	for (int i=0; i<=length; i++)
		for (int j=0; j<=asoi; j++)
			memo[i][j] = choose(i,j);
	int sum;
	for (int digits=length; digits>0; digits--)
	{
		sum = 0;
		for  (int i=0; i<=asoi; i++)
			sum += memo[digits-1][i];
		if (ith-sum > 0)
		{
			ith -= sum;
			apantisi += '1';
			asoi--;
		}
		else
			apantisi += '0';
	}
	fout << apantisi << endl;
	return 0;
}

