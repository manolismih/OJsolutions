/*
ID:manolis2
PROG:hamming
LANG:C++
*/

#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

FILE *input = fopen("hamming.in","r");
FILE *output = fopen("hamming.out","w");
int n,b,h,maxbin;
list <bitset<8> > binnums;

void printsol()
{
	int i=1;
	for (list<bitset<8> >::iterator it=binnums.begin(); it!=binnums.end(); it++)
	{
		if ((i%10 == 0) || (i==n))
		{
			fprintf(output,"%i\n",it->to_ulong());	
			i++;
		}
			
		else 
		{
			fprintf(output,"%i%c",it->to_ulong(),' ');
			i++;
		}
	}
	fclose(output);
	exit(0);
	return;
}

bool nextbin(bitset<8> &number, const bitset<8> &prev, int &hamdist, int &currbin)
{
	int i;
	do 
	{
		currbin++;
		if (currbin == maxbin) // maxbin is grater by 1; 2^8 = 256 but 11111111 = 255
			return false;
		for (i=0; number[i]; i++)
		{
			number[i]=0;
			prev[i] ? hamdist++ : hamdist--;
		}	
		number[i]=1;
		prev[i] ? hamdist-- : hamdist++;
	}
	while (hamdist < h);
	return true;
}

bool valid()
{
	list<bitset<8> >::iterator it=binnums.begin();
	int hamdist;
	for (int i=1; i<binnums.size(); it++, i++)
	{
		hamdist=0;
		for (int j=0; j<b; j++)
			if	((*it)[j] ^ binnums.back()[j])
				hamdist++;
		if (hamdist < h)
			return false;
	}
	return true;
}

void dfs()
{
	if (!valid()) return;
	if (binnums.size() == n)
		printsol();
		
	int currbin = binnums.back().to_ulong();	
	bitset<8> newbin = binnums.back();
	int hamdist=0;
	while (nextbin(newbin,binnums.back(),hamdist,currbin))
	{
		binnums.push_back(newbin);
		dfs();
		binnums.pop_back();
	}
	return;
}

int main()
{
	fscanf(input,"%i%i%i",&n,&b,&h);
	maxbin = pow(2,b);
	bitset<8> empty;
	binnums.push_back(empty);
	dfs();
	return 0;
}
