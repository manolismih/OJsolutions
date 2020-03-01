/*
ID:manolis2
PROG:learning
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin=fopen("learning.in","r"), *fout=fopen("learning.out","w");
int n, a, b, apantisi=0;
char s[5];

struct cow{
	int weight;
	bool spot;
};
cow cows[50005];
bool operator<(cow a, cow b)
{
	return a.weight < b.weight;
}

int main()
{
	fscanf(fin,"%i%i%i",&n,&a,&b);
	for (int i=0; i<n; i++)
	{
		fscanf(fin,"%s%i",s,&cows[i].weight);
		if (s[0] == 'S') cows[i].spot = true;
	}
	sort(cows,cows+n);
	
	if (a < cows[0].weight) 
	{
		if (cows[0].spot) apantisi += cows[0].weight-a;
		a = cows[0].weight;
	}
	if (b > cows[n-1].weight)
	{
		if (cows[n-1].spot) apantisi += b-cows[n-1].weight;
		b = cows[n-1].weight;
	} 
	if (n==1) apantisi++;
	
	int i=0, curr=a, middle;
	for (; i<n-1 && curr>cows[i+1].weight; i++)
	;
	
	for (; i<n-1 && curr<b; i++)
	{
		middle = (cows[i].weight+cows[i+1].weight) / 2;
		if (cows[i].spot && curr<=middle) apantisi += min(b,middle) - max(cows[i].weight,curr) + 1;
		if (cows[i+1].spot && b>middle) apantisi += min(b,cows[i+1].weight) - max(middle,curr);
		if ((cows[i].weight+cows[i+1].weight)%2 == 0 && !cows[i].spot && cows[i+1].spot && middle >= curr && middle<=b)
			apantisi++;
		curr = cows[i+1].weight+1;
		if (cows[i+2].weight == curr) i++;
	}
	
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

