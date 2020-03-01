#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nortin.txt");
ofstream fout("nortout.txt");
int apantisi, x, y;

int main()
{
	fin >> x >> y;
	fout << (x%2 && y%2 ? x*y-1 : x*y) << endl;
	return 0;
}

