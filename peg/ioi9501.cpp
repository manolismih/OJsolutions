#include <string>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string s;
int pista[99][99], moves[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{-1,1}};
int x=50, y=50, dir, filled;
//οι στήλες και γραμμές με άρτια συντεταγμένη έχουν τοίχους, και τα υπόλοιπα τετράγωνα είναι κενά.
//άρα τα κενά στο σύνολο είναι 2401

void step()
{
	y += moves[dir][0];
	x += moves[dir][1];
}
void turn(int lr)
{
	dir += lr;
	if (dir>3) dir-=4;
	if (dir<0) dir+=4;
}

void fill(int y, int x)
{
	pista[y][x]=5;
	filled++;
	for (int i=0; i<8; i++)
		if ((pista[y+moves[i][0]][x+moves[i][1]]==0	||	pista[y+moves[i][0]][x+moves[i][1]]==2)
		&&	 pista[y+2*moves[i][0]][x+2*moves[i][1]]==0)
			fill(y+2*moves[i][0],x+2*moves[i][1]);
}

int main()
{
	for (int i=0; i<99; i++)
	{
		pista[i][0] = pista[i][98] = 1;
		pista[0][i] = pista[98][i] = 1;
	}
	cin >> s;
	for (int i=0; i<s.length(); i++)
	{
		step();
		pista[y][x]++;
		step();
		pista[y][x]++;
		turn(s[i] == 'R' ? 1 : -1);
	}
	fill(1,1);
	cout << 2401-filled << endl;
	
	
	set<string> ans;
	ans.insert(s);
	for (int i=0; i<s.length(); i++)
	{
		s += s[0];
		s.erase(s.begin());
		ans.insert(s);
	}
	for (int i=0; i<s.length(); i++)
		s[i] = (s[i]=='L' ? 'R' : 'L');
	for (int i=0; i<s.length()/2; i++)
		swap(s[i],s[s.length()-1-i]);
	ans.insert(s);
	for (int i=0; i<s.length(); i++)
	{
		s += s[0];
		s.erase(s.begin());
		ans.insert(s);
	}
	
	for (auto &it:ans)
		cout << it << endl;
}
