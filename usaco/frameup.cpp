/*
ID:manolis2
PROG:frameup
LANG:C++11
*/
#include <cstdio>
#include <set>
using namespace std;

FILE *fin=fopen("frameup.in","r"), *fout=fopen("frameup.out","w");
char pista[40][40], ordering[30];
int nrows, ncolumns, nletters;
struct frame{
	int maxx, maxy, minx=2000, miny=2000;
};
frame frames[30];
set<int> alist[30], oalist[30];
bool visited[30];

void findtoposorts(int pos)
{
	if (pos==nletters)
		fprintf(fout,"%s\n",ordering);
	else
		for (int i=0; i<26; i++)
			if ((frames[i].maxx || frames[i].maxy) && alist[i].empty() && !visited[i])
			{
				visited[i] = true;
				ordering[pos] = i+'A';
				for (auto it=oalist[i].begin(); it!=oalist[i].end(); it++)
					alist[*it].erase(i);
				findtoposorts(pos+1);
				visited[i] = false;
				ordering[pos] = 0;
				for (auto it=oalist[i].begin(); it!=oalist[i].end(); it++)
					alist[*it].insert(i);
			}
}

int main()
{
	fscanf(fin,"%i%i\n",&nrows,&ncolumns);
	for (int i=0; i<nrows; i++)
		fscanf(fin,"%s",pista[i]);
	for (int i=0; i<nrows; i++)
		for (int j=0; j<ncolumns; j++)
			if (pista[i][j] != '.')
			{
				if (i < frames[pista[i][j]-'A'].miny) frames[pista[i][j]-'A'].miny = i;
				if (i > frames[pista[i][j]-'A'].maxy) frames[pista[i][j]-'A'].maxy = i;
				if (j < frames[pista[i][j]-'A'].minx) frames[pista[i][j]-'A'].minx = j;
				if (j > frames[pista[i][j]-'A'].maxx) frames[pista[i][j]-'A'].maxx = j;
			}
	for (int i=0; i<26; i++)
		if (frames[i].maxx || frames[i].maxy)
		{
			for (int col=frames[i].minx; col<=frames[i].maxx; col++)
			{
				oalist[i].insert(pista[frames[i].miny][col]-'A');
				oalist[i].insert(pista[frames[i].maxy][col]-'A');
			}
			for (int row=frames[i].miny; row<=frames[i].maxy; row++)
			{
				oalist[i].insert(pista[row][frames[i].minx]-'A');
				oalist[i].insert(pista[row][frames[i].maxx]-'A');
			}
			oalist[i].erase(i);
			nletters++;
		}
		
	for (int i=0; i<26; i++)
		if (frames[i].maxx || frames[i].maxy)
			for (auto it=oalist[i].begin(); it!=oalist[i].end(); it++)
				alist[*it].insert(i);
	findtoposorts(0);
	return 0;
}

