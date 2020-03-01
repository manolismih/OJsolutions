/*
ID:manolis2
PROG:shuttle
LANG:C++11
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ifstream fin("shuttle.in");
ofstream fout("shuttle.out");
int n, m[2], printed;
char pista[30];
bool turn, hop[2];
stringstream ss;

void print(int &p)
{
	if (printed == 19)
	{
		ss << p-1 << '\n';
		printed = 0;
	}
	else
	{
		ss << p-1 << ' ';
		printed++;
	}	
}

void findmoves(int pos)
{
	if (pista[pos-1] == '0')
	{
		m[0] = pos-1;
		hop[0] = false;
	}
	else if (pista[pos-2] == '0')
	{
		m[0] = pos-2;
		hop[0] = true;
	}
	else 
	{
		m[0] = 0;
		hop[0] = false;
	}
	
	if (pista[pos+1] == '1')
	{
		m[1] = pos+1;
		hop[1] = false;
	}
	else if (pista[pos+2] == '1')
	{
		m[1] = pos+2;
		hop[1] = true;
	}
	else
	{
		m[1] = 0;
		hop[1] = false;
	}
}

void move(int pos)
{
	if (pista[pos] == '0')	
		pista[pista[pos+1] == '_' ? pos+1 : pos+2] = '0';
	else
		pista[pista[pos-1] == '_' ? pos-1 : pos-2] = '1';
	pista[pos] = '_';
}

int main()
{
	fin >> n;
	pista[0] = pista[1] = pista[2*n+3] = pista[2*n+4] = '|';
	pista[n+2] = '_';		
	for (int i=2; i<n+2; i++)
		pista[i] = '0';
	for (int i=n+3; i<2*n+3; i++)
		pista[i] = '1';
	m[0] = n+1, m[1] = n+3;
	while (m[0] || m[1])
	{
		if (!m[turn]) turn = !turn;
		while (hop[turn])
		{
			move(m[turn]);
			print(m[turn]);
			findmoves(m[turn]);
		}
		if (!m[turn]) continue;
		move(m[turn]);
		print(m[turn]);
		findmoves(m[turn]);
		turn = !turn;
	}
	string apantisi = ss.str();
	apantisi.erase(apantisi.length()-1);
	fout << apantisi << endl;
	return 0;
}

