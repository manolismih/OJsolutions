/*
ID:manolis2
PROG:rockers
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("rockers.in");
ofstream fout("rockers.out");
int songs, capacity, disks, durations[20], diskcaps[20];

int apantisi(int song, int freedisk)
{
	if (song == songs) return 0;
	int a = apantisi(song+1,freedisk);
	while (freedisk < disks && durations[song]>diskcaps[freedisk])
		freedisk++;
	if (freedisk == disks) return a;
	diskcaps[freedisk] -= durations[song];
	int b = 1+apantisi(song+1,freedisk);
	diskcaps[freedisk] += durations[song];
	return max(a,b);
}

int main()
{
	fin >> songs >> capacity >> disks;
	for (int i=0; i<songs; i++)
		fin >> durations[i];
	for (int i=0; i<disks; i++)
		diskcaps[i] = capacity;
	fout << apantisi(0,0) << endl;
	return 0;
}

