/*
ID:manolis2
PROG:fracdec
LANG:C++11
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
bool bupoloipa[100000];
int nupoloipa[100009];
string apantisi;

void addtostring(string& target, int number)
{
	stringstream ss;
	ss << number;
	target += ss.str();
}

int main()
{
	int nom, denom, i=0, upoloipo, ndigits;
	fin >> nom >> denom;
	addtostring(apantisi,nom/denom);
	apantisi += '.';
	
	upoloipo = nom%denom;
	while (!bupoloipa[upoloipo] && upoloipo != 0)
	{
		bupoloipa[upoloipo] = true;
		nupoloipa[i] = upoloipo;
		upoloipo *= 10;
		addtostring(apantisi,upoloipo/denom);
		upoloipo %= denom;
		i++;
	}
	int pos = apantisi.length()-1;
	
	if (upoloipo != 0)
	{
		while(i-1 >= 0 && nupoloipa[--i] != upoloipo)
		{
			pos--;
		}
		apantisi.insert(pos,"(");
		apantisi += ')';
	}
	
	if (apantisi[apantisi.length()-1] == '.')
		apantisi += '0';
	for (int i=0; i<apantisi.length(); i+=76)
		fout << apantisi.substr(i,76) << endl; 

	return 0;
}

