/*
ID:manolis2
PROG:job
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("job.in");
ofstream fout("job.out");
int n, ma, mb, apantisi=0;
vector<int> atimes, btimes;

struct machine{
	int speed, timeleft;
};
machine machines[65] = {0,0};
bool comp(machine a, machine b)
{
	return a.speed < b.speed;
}

int main()
{
	fin >> n >> ma >> mb;
	for (int i=0; i<ma+mb; i++)
		fin >> machines[i].speed;
	sort(machines,machines+ma,comp);
	sort(machines+ma,machines+ma+mb,comp);
	for (int besti, i=0; i<n; i++)
	{
		for (int best=2000000000, j=0; j<ma; j++)
			if (machines[j].timeleft + machines[j].speed < best)
			{
				best = machines[j].timeleft + machines[j].speed;
				besti = j;
			}
		machines[besti].timeleft += machines[besti].speed;
		atimes.push_back(machines[besti].timeleft);
		for (int best=200000000, j=ma; j<ma+mb; j++)
			if (machines[j].timeleft + machines[j].speed < best)
			{
				best = machines[j].timeleft + machines[j].speed;
				besti = j;
			}
		machines[besti].timeleft += machines[besti].speed;
		btimes.push_back(machines[besti].timeleft);
	}
	for (int a=0,b=n-1; a<n; a++,b--)
		if (atimes[a] + btimes[b] > apantisi)
			apantisi = atimes[a] + btimes[b];
	fout << atimes[n-1] << ' ' << apantisi << endl;
	return 0;
}

