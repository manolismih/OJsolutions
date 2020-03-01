/*
ID:manolis2
PROG:skidesign
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");
int n, hills[1000], apantisi=2000000000, curr;

int main()
{
	fin >> n;
	for (int i=0; i<n; i++)
		fin >> hills[i];
	for (int h=17; h<=100; h++)
	{
		curr = 0;
		for (int i=0; i<n; i++)
			if (hills[i] < h-17)
				curr += pow(h-17-hills[i],2);
			else if (hills[i] > h)
				curr += pow(hills[i]-h,2);
		if (curr < apantisi)
			apantisi = curr;
	}
	fout << apantisi << endl;
	return 0;
}

