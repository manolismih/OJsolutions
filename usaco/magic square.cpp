/*
ID:manolis2
PROG:msquare
LANG:C++11
*/

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <bitset>

using namespace std;

ifstream fin("msquare.in");
ofstream fout("msquare.out");
string target;
struct node{
	string sheet, moves;	
};
queue<node> oura;
bitset<8> examined[8][8][8][8][8][8][8];

int main()
{
	char c;
	for (int i=0; i<4; i++)
	{
		fin >> c;
		target += c;
	}
	string rev;
	for (int i=0; i<4; i++)
	{
		fin >> c;
		rev += c;
	}
	for (int i=3; i>-1; i--)
		target += rev[i];
	node init={string("12348765"),string()};
	oura.push(init);
	int length;
	
	while (oura.front().sheet != target)
	{
		node &curr = oura.front();
		node next = curr;
		length = curr.moves.length();
		
		if (length<1 || curr.moves[length-1] != 'A')
		{
			for (int i=4; i<8; i++)
				next.sheet[i-4] = curr.sheet[i];
			for (int i=0; i<4; i++)
				next.sheet[i+4] = curr.sheet[i];
			if (!examined[next.sheet[0]-49][next.sheet[1]-49][next.sheet[2]-49][next.sheet[3]-49][next.sheet[4]-49][next.sheet[5]-49][next.sheet[6]-49][next.sheet[7]-49])
			{
				examined[next.sheet[0]-49][next.sheet[1]-49][next.sheet[2]-49][next.sheet[3]-49][next.sheet[4]-49][next.sheet[5]-49][next.sheet[6]-49].set(next.sheet[7]-49);
				next.moves += 'A';
				oura.push(next);
				next.moves.pop_back();
			}
		}
		
		if (length<3 || curr.moves[length-1] != 'B' || curr.moves[length-2] != 'B' || curr.moves[length-3] != 'B')
		{
			next.sheet[0] = curr.sheet[3];
			next.sheet[4] = curr.sheet[7];
			for (int i=1; i<4; i++)
				next.sheet[i] = curr.sheet[i-1];
			for (int i=5; i<8; i++)
				next.sheet[i] = curr.sheet[i-1];
			if (!examined[next.sheet[0]-49][next.sheet[1]-49][next.sheet[2]-49][next.sheet[3]-49][next.sheet[4]-49][next.sheet[5]-49][next.sheet[6]-49][next.sheet[7]-49])
			{
				examined[next.sheet[0]-49][next.sheet[1]-49][next.sheet[2]-49][next.sheet[3]-49][next.sheet[4]-49][next.sheet[5]-49][next.sheet[6]-49].set(next.sheet[7]-49);
				next.moves += 'B';
				oura.push(next);
				next.moves.pop_back();
			}
		}	
		
		if (length<3 || curr.moves[length-1] != 'C' || curr.moves[length-2] != 'C' || curr.moves[length-3] != 'C')
		{
			next.sheet[0] = curr.sheet[0];
			next.sheet[3] = curr.sheet[3];
			next.sheet[4] = curr.sheet[4];
			next.sheet[7] = curr.sheet[7];
			char temp = curr.sheet[1];
			next.sheet[1] = curr.sheet[5];
			next.sheet[5] = curr.sheet[6];
			next.sheet[6] = curr.sheet[2];
			next.sheet[2] = temp;
			if (!examined[next.sheet[0]-49][next.sheet[1]-49][next.sheet[2]-49][next.sheet[3]-49][next.sheet[4]-49][next.sheet[5]-49][next.sheet[6]-49][next.sheet[7]-49])
			{
				examined[next.sheet[0]-49][next.sheet[1]-49][next.sheet[2]-49][next.sheet[3]-49][next.sheet[4]-49][next.sheet[5]-49][next.sheet[6]-49].set(next.sheet[7]-49);
				next.moves += 'C';
				oura.push(next);
				next.moves.pop_back();
			}
		}
		oura.pop();	
	}
	fout << oura.front().moves.length() << endl;
	if (!oura.front().moves.length())
		fout << endl;
	else
	for (int i=0; i<oura.front().moves.length(); i+=60)
		fout << oura.front().moves.substr(i,60) << endl;
	return 0;
}

