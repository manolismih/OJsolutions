/*
ID:manolis2
PROG:ratios
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstdlib>

using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");
int target[3], ms[3][3];
bool mixtures[3] = {1,1,1};
struct node{
	int m[3], prev;
};
node tonode(int a, int b, int c, int prev)
{
	node ret={a,b,c,prev};
	return ret;
}
queue<node> oura;

bool check(node &curr)
{
	for (int i=0; i<3; i++)
		if (curr.m[i] > 99)
			return false;
			
	int sum, ratio=-1;
	for (int component=0; component<3; component++)
		if (target[component])
		{
			sum = 0;
			for (int mixture=0; mixture<3; mixture++)
				sum += curr.m[mixture]*ms[mixture][component];
			if (sum%target[component] != 0 || sum==0 || (ratio != -1 && sum/target[component] != ratio))
				return true;
			if (ratio == -1)
				ratio = sum/target[component];
		}
	fout << curr.m[0] << ' ' << curr.m[1] << ' ' << curr.m[2] << ' ' << (curr.m[0]*ms[0][0] + curr.m[1]*ms[1][0] + curr.m[2]*ms[2][0]) / target[0] << endl;
	exit(0);
}

int main()
{
	fin >> target[0] >> target[1] >> target[2];
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			fin >> ms[i][j];
	for (int component=0; component<3; component++)
		if (!target[component])
			for (int i=0; i<3; i++)		
				if (ms[i][component])
					mixtures[i] = false;					
	oura.push(tonode(0,0,0,0));
	while (!oura.empty())
	{
		node curr = oura.front();
		if (!check(curr))
		{
			oura.pop();
			continue;
		}
		for (int i=curr.prev; i<3; i++)
			if (mixtures[i])
			{
				curr.prev=i;
				curr.m[i]++;
				oura.push(curr);
				curr.m[i]--;
			}
		oura.pop();
	}
	fout << "NONE" << endl;
	return 0;
}

