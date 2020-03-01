/*
ID:manolis2
PROG:race3
LANG:C++11
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <iostream>

using namespace std;

FILE *fin = fopen("race3.in","r");
FILE *fout = fopen("race3.out","w");
int n=0;
vector<int> alist[55], oalist[55], unavoidable, diaxoristika;
bitset<55> memo[55];
queue<int> tpsqueue;
bool visited[55], visited1[55], visited2[55];

void toposort_and_dp()
{
	while (!tpsqueue.empty())
	{
		if (!visited[tpsqueue.front()])
		{
			int v = tpsqueue.front();
			visited[v] = true;
			for (int i=0; i<alist[v].size(); i++)
				memo[v] &= memo[alist[v][i]];
			memo[v].set(v); 
			for (int i=0; i<oalist[v].size(); i++)
				tpsqueue.push(oalist[v][i]);
		}
		tpsqueue.pop();
	}
}

void findkomvous(int from, int to, bool* visited)
{
	if (visited[from] || from == to) return;
	visited[from] = true;
	for (int i=0; i<alist[from].size(); i++)	
		findkomvous(alist[from][i],to,visited);
}

bool check()
{
	for (int i=0; i<n; i++)
		if (visited1[i] == visited2[i])
			return false;
	return true;
}


int main()
{
	int i=0, temp;
	while (fscanf(fin,"%i",&temp) && temp != -1)
	{
		while (temp != -2)
		{
			alist[i].push_back(temp);
			oalist[temp].push_back(i);
			if (temp>n) n=temp;
			fscanf(fin,"%i",&temp);
		}
		i++;
	}
	
	for (int i=0; i<oalist[n].size(); i++)
		tpsqueue.push(oalist[n][i]);
	for (int i=0; i<n; i++)
		memo[i].set();
	toposort_and_dp();
	
	for (int i=1; i<n; i++)
		if (memo[0][i])
			unavoidable.push_back(i);
	fprintf(fout,"%i",unavoidable.size());
	for (int i=0; i<unavoidable.size(); i++)
		fprintf(fout," %i",unavoidable[i]);
	fprintf(fout,"\n");
	
	for (int i=0; i<unavoidable.size(); i++)
	{
		findkomvous(0,unavoidable[i],visited1);
		findkomvous(unavoidable[i],n,visited2);
		if (check())
			diaxoristika.push_back(unavoidable[i]);
		for (int i=0; i<=n; i++)
		{
			visited1[i] = 0;
			visited2[i] = 0;
		}
	}
	fprintf(fout,"%i",diaxoristika.size());
	for (int i=0; i<diaxoristika.size(); i++)
		fprintf(fout," %i",diaxoristika[i]);
	fprintf(fout,"\n");
	return 0;
}


