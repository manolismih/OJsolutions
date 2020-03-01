/*
ID:manolis2
PROG:money
LANG:C++11
*/

#include <cstdio>
#include <algorithm>

using namespace std;

FILE *input = fopen("money.in","r");
FILE *output = fopen("money.out","w");
long long int coins[25], memo[10005][25];
bool examined[10005][25];
int ncoins;

long long int findtropoi(int poso, int limit)
{
	if (examined[poso][limit]) return memo[poso][limit];
	if (poso==0) return 1;
	examined[poso][limit] = true;
	for (int i=limit; i<ncoins; i++)
		if (poso-coins[i]>=0)
			memo[poso][limit] += findtropoi(poso-coins[i],i);
		else
			return memo[poso][limit];
	return memo[poso][limit];
}

int main()
{
	int poso;
	fscanf(input,"%i%i",&ncoins,&poso);
	for (int i=0; i<ncoins; i++)
		fscanf(input,"%i",&coins[i]);
	sort(coins,coins+ncoins);
	findtropoi(poso,0);
	fprintf(output,"%lli\n",memo[poso][0]);
	return 0;
}
