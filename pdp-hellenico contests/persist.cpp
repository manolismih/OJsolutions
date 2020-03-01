#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ifstream fin("persist.in");
ofstream fout("persist.out");
string n1, n2, sapantisi;
int lowbound, maxbound, ndigits, apantisi=-1;
int d[12];

void fullcheck(int digit)
{
	if (digit==lowbound)
	{
		persistance();
		return;
	}
	for (;d[digit]<=9; d[digit]++)
		fullcheck(digit+1);
		
}

int main()
{
	fin >> n1 >> n2;
	lowbound = n1.length(), maxbound = n2.length();
	for (int i=0; i<lowbound; i++)
		d[i] = n1[i]-'0';
	fullcheck(0);
	for (ndigits=lowbound+1; ndigits<maxbound; ndigits++)
		check(0);
	fout << apantisi << endl;
	return 0;
}

