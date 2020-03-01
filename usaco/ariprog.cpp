/*
ID:manolis2
PROG:ariprog
LANG:C++
*/
#include <fstream>
#include <deque>
#include <iostream>

using namespace std;

struct number
{
	bool valid;
	int omega, length;
};
number numbers[125001] = {0,-1,0};
int allowed[125001], nallowed=0;
int starting[125001], startingi;
int maxnumber;

int examine(int a1, int omega)
{
	if ((a1 > maxnumber) || (!numbers[a1].valid))
		return 0;
	if (numbers[a1].omega == omega)
		return numbers[a1].length;
	numbers[a1].omega = omega;
	numbers[a1].length = 1+examine(a1+omega,omega);
	return numbers[a1].length;
	
}

int main()
{
	ifstream input("ariprog.in");
	ofstream output("ariprog.out");
	int length, maxsquare;
	input >> length >> maxsquare;
	for (int i=0; i<= maxsquare; i++)
		for (int j=i; j<= maxsquare; j++)
			if (!numbers[i*i+j*j].valid)
				numbers[i*i+j*j].valid = true;
		
	starting[125000] = -1;
	maxnumber = 2*(maxsquare*maxsquare);
	for (int i=0; i<=maxnumber; i++)
		if (numbers[i].valid)
		{
			allowed[nallowed] = i;
			nallowed++;
		}
	int maxomega = maxnumber/(length-1);
	int result;
	for (int i=1; i<= maxomega; i++)
	{
		startingi = 125001;
		for (int j=nallowed-1; j>-1; j--)
		{
			result=examine(allowed[j],i);
			if (result >= length)
			{
				startingi--;
				starting[startingi]=allowed[j];
			}
		}	 
		for (int j=startingi; j<125001; j++)
			output << starting[j] << " " << i << endl;
	}
	if (starting[125000] == -1)
		output << "NONE" << endl;
	return 0;
}

