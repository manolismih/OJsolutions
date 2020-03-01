/*
ID:manolis2
PROG:charrec
LANG:C++11
*/
#include <fstream>
#include <bitset>
#include <cassert>
#include <algorithm>
using namespace std;

ifstream fin("charrec.in"), font("font.in");
ofstream fout("charrec.out");
bitset<30> ideal[30][30], input[1205];
int n, curr=1, sums[30][30][3]; //sums[let][row][mode]
int best, rows;
char letter;

void getsums(int let)
{
	sums[let][1][1] = (input[curr] ^ ideal[let][1]).count();
	sums[let][1][2] = (input[curr] ^ ideal[let][2]).count();
	for (int i=curr+1; i<=curr+18; i++)
		for (int j=0; j<3; j++)
		{
			sums[let][i-curr+1][j] = (input[i] ^ ideal[let][i-curr+1+j-1]).count();
			sums[let][i-curr+1][j] += sums[let][i-curr][j];
		}
	if (curr+19<=n)
		for (int j=0; j<2; j++)
		{
			sums[let][20][j] = (input[curr+19] ^ ideal[let][20+j-1]).count();
			sums[let][20][j] += sums[let][19][j];
		}
	if (curr+20<=n)
	{
		sums[let][21][0] = (input[curr+20] ^ ideal[let][20]).count();
		sums[let][21][0] += sums[let][20][0];
	}
}

void missing(int let)
{
	int temp;
	for (int i=1; i<=20; i++)
	{
		temp = sums[let][i-1][1] + sums[let][19][2] - sums[let][i-1][2];
		if (temp < best)
		{
			best = temp;
			letter = let;
			rows = 19;
		}
	}
}

void normal(int let)
{
	if (sums[let][20][1] < best)
	{
		best = sums[let][20][1];
		letter = let;
		rows = 20;
	}
}

void duplicate(int let)
{
	int temp;
	for (int i=1; i<=20; i++)
	{
		temp = sums[let][i-1][1] + min((input[curr+i-1]^ideal[let][i]).count(),(input[curr+i]^ideal[let][i]).count()) 
			 + sums[let][21][0] - sums[let][i+1][0]; 
		if (temp < best)
		{
			best = temp;
			letter = let;
			rows = 21;
		}
	}
}

int main()
{
	font >> n;
	for (int i=0; i<27; i++)
		for (int j=1; j<=20; j++)
			font >> ideal[i][j];
	fin >> n;
	for (int i=1; i<=n; i++) fin >> input[i];
	
	while (curr<n)
	{
		best = 200000000;
		for (int i=0; i<27; i++)
		{
			getsums(i);
			missing(i);
			if (curr+19<=n) normal(i);
			if (curr+20<=n) duplicate(i);
		}
		if (!letter) letter=' ';
		else letter += 'a'-1;
		fout << letter;
		curr += rows;
	}
	fout << endl;
}
