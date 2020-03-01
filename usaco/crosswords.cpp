/*
ID:manolis2
PROG:crosswords
LANG:C++11
*/
#include <fstream>
using namespace std;

ifstream fin("crosswords.in");
ofstream fout("crosswords.out");
int rows, columns, apantisi=0;
int pista[55][55];

int main()
{
	fin >> rows >> columns;
	char c;
	for (int i=1; i<=rows; i++)
		for (int j=1; j<=columns; j++)
		{
			fin >> c;
			pista[i][j] = c=='.' ? -1 : 0;
		}
	for (int row=1; row<=rows; row++)
		for (int col=1; col<=columns; col++)
			if (pista[row][col] && (
				!pista[row][col-1] && pista[row][col+1] && pista[row][col+2]
				|| !pista[row-1][col] && pista[row+1][col] && pista[row+2][col]))
				{
					pista[row][col] = ++apantisi;
				}
	fout << apantisi << endl;
	for (int row=1; row<=rows; row++)
		for (int col=1; col<=columns; col++)
			if (pista[row][col] > 0)
				fout << row << ' ' << col << endl;
	return 0;
}

