/*
ID:manolis2
PROG:comehome
LANG:C++
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

ifstream fin("comehome.in");
ofstream fout("comehome.out");

struct twoints
{
	int x,y;
};

bool operator<(twoints a, twoints b)
{
	return a.x > b.x;
}

vector<pair<int,int> > alist[53];
pair<int,int> lisi = mp(2000000000,0);
priority_queue<twoints> oura;
bool visited[53];

inline int lettonum(char c)
{
	if (isupper(c)) return c-'A'+27;
	else return c-'a'+1;
}

inline char numtolet(int n)
{
	return char(n+int('A')-27);
}

void dijkstra()
{
	
}

int main()
{
	int paths, dist;
	char v1, v2;
	fin >> paths;
	for (int i=0; i<paths; i++)
	{
		fin >> v1 >> v2 >> dist;
		alist[lettonum(v1)].pb(mp(lettonum(v2),dist));
		alist[lettonum(v2)].pb(mp(lettonum(v1),dist));
	} 
	twoints lisi={15,0};
	dijkstra();
	fout << numtolet(lisi.y) << ' ' << lisi.x << endl;
	return 0;
}

