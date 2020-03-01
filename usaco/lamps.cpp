/*
ID:manolis2
PROG:lamps
LANG:C++11
*/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream input("lamps.in");
ofstream output("lamps.out");
int n, c, tropos[4], moves[4][2] = {{1,1},{1,2},{2,2},{1,3}};
string periorismoi(101,'x'), lisi, init(101,'1');
vector<string> liseis;

void myswap(char &c)
{
	(c=='1') ? c='0' : c='1';
}

void findliseis(int i)
{
	if (i==4)
	{
		int sum = tropos[0]+tropos[1]+tropos[2]+tropos[3];
		if (c<sum || c%2 != sum%2) return;
		lisi = init;
		for (int i=0; i<4; i++)
			if (tropos[i])
				for (int j=moves[i][0]; j<=n; j+=moves[i][1])
					myswap(lisi[j]);
		for (int i=1; i<=n; i++)
			if (periorismoi[i] != 'x' && lisi[i] != periorismoi[i]) return;
		liseis.push_back(lisi);
		return;
	}
	tropos[i]=0;
	findliseis(i+1);
	tropos[i]=1;
	findliseis(i+1);
}

int main()
{
	input >> n >> c;
	int temp;
	input >> temp;
	while (temp != -1)
	{
		periorismoi[temp]='1';
		input >> temp;
	}
	input >> temp;
	while (temp != -1)
	{
		periorismoi[temp]='0';
		input >> temp;
	}
	findliseis(0);
	sort(liseis.begin(),liseis.end());
	for (int i=0; i<liseis.size(); i++)
	{
		for (int j=1; j<=n; j++)
			output << liseis[i][j];
		output << endl;
	}
	if (liseis.size() == 0)
		output << "IMPOSSIBLE" <<endl;	
	return 0;
}

