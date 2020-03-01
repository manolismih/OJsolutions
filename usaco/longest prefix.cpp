/*
ID:manolis2
PROG:prefix
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

ifstream input("prefix.in");
ofstream output("prefix.out");

set<string> primitives[27][27][27];
string sequence;
int memo[200005] = {0}, maxlength=0;
bool examined[200005] = {0};

inline int ltn(char c) {return int(c)-int('A')+1;}

int apantisi(int i)
{
	if (examined[i]) return memo[i];
	examined[i] = true;
	string s;
	int best=0;
	if (i==sequence.length())
	{
		memo[i]=best;
		return best;
	}
	s += sequence[i];
	if (primitives[ltn(sequence[i])][0][0].find(s) != primitives[ltn(sequence[i])][0][0].end())
		best = apantisi(i+1)+1;
	if (i==sequence.length()-1)
	{
		memo[i]=best;
		return best;
	}
	s+=sequence[i+1];
	if (primitives[ltn(sequence[i])][ltn(sequence[i+1])][0].find(s) != primitives[ltn(sequence[i])][ltn(sequence[i+1])][0].end())
		if (apantisi(i+2)+2 > best) 
			best = apantisi(i+2)+2;
	for (int j=3; j<=maxlength && i+j<=sequence.length(); j++)
	{
		s+=sequence[i+j-1];
		if (primitives[ltn(sequence[i])][ltn(sequence[i+1])][ltn(sequence[i+2])].find(s) != primitives[ltn(sequence[i])][ltn(sequence[i+1])][ltn(sequence[i+2])].end())
			if (apantisi(i+j)+j > best)
				best=apantisi(i+j)+j;
	}
	memo[i]=best;
	return best;
}

int main()
{
	string p;
	input >> p;
	int i2,i3;
	while (p != ".")
	{
		switch (p.length())
		{
			case 1:
				i2=0;
				i3=0;
				break;
			case 2:
				i2=ltn(p[1]);
				i3=0;
				break;
			default:
				i2=ltn(p[1]);
				i3=ltn(p[2]);
				break;
		}
		primitives[ltn(p[0])][i2][i3].insert(p);
		if (p.length()>maxlength) maxlength=p.length();
		input >> p;
	}
	input >> p;
	while (input)
	{	
		sequence += p;
		input >> p;
	}
	cout << sequence.length();
	for (int i=sequence.length()-1; i>0; i--)
		apantisi(i);
	output << apantisi(0) << endl;
	return 0;
}
