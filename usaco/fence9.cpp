/*
ID:manolis2
PROG:fence9
LANG:C++11
*/
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("fence9.in");
ofstream fout("fence9.out");
int x1,y,x2;
long long apantisi=0;
class Klasma{
	public:
		int ari, par;
		int akeraio_meros()
		{
			return ari/par;
		}
		void set(int _ari, int _par)
		{
			ari = _ari;
			par = _par;
		}
		bool akeraio()
		{
			return ari % par == 0;
		}
};
void operator +=(Klasma &a, Klasma &b)
{
	a.ari += b.ari;
}
void operator -=(Klasma &a, Klasma &b)
{
	a.ari -= b.ari;
}

int main()
{
	fin >> x1 >> y >> x2;
	Klasma inc,total;
	if (x1 != 0)
	{
		inc.set(y,x1);
		total.set(0,x1);
		for (int i=1; i<x1; i++)
		{
			total += inc;
			apantisi += (total.akeraio() ? total.akeraio_meros()-1 : total.akeraio_meros());
		}
	}
	else
		apantisi -= y-1; 
		
	if (x1 < x2)
	{
		inc.set(y,x2-x1);
		total.set(y*(x2-x1),x2-x1);
		for (int i=0; i<x2-x1; i++)
		{
			apantisi += (total.akeraio() ? total.akeraio_meros()-1 : total.akeraio_meros());
			total -= inc;
		}	
	}
	else if (x2 < x1)
	{
		total.set(0,x1-x2);
		inc.set(y,x1-x2);
		for (int i=1; i<x1-x2; i++)
		{
			total += inc;
			apantisi -= total.akeraio_meros();
		}
	}
	fout << apantisi << endl;
	return 0;
}
