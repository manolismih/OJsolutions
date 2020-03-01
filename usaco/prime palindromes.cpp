/*
ID:manolis2
PROG:pprime
LANG:C++
*/

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int a,b,primes[10000],pn=0,lengths[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000},maxprime;
bool bprimes[10001];
char stra[10],strb[10];
FILE *output = fopen("pprime.out","w");

void koskino()
{
	maxprime=static_cast<int>(sqrt(b));
	int i,p=2;
	while (p*p<=maxprime)
	{
		for (i=p+p; i<=maxprime; i+=p)
			bprimes[i]=false;
		for (i=p+1; i<=maxprime; i++)
			if (bprimes[i]) break;
		p=i;
	}
	for (i=2; i<=maxprime; i++)
		if (bprimes[i])
		{
			primes[pn]=i;
			pn++;
		}
	return;
}

void check(int length, int *d)
{
	int factor=lengths[length],finalnum=0,i;
	for (i=0; i<length/2; i++)
	{
		finalnum +=(*d)*factor;
		d++;
		factor /= 10;
	}
	if (length%2 > 0)
	{
		finalnum += (*d)*factor;
		factor /= 10;
	}
	d--;
	for (; i>-1; i--)
	{
		finalnum += (*d)*factor;
		d--;
		factor /= 10;
	}
	if (finalnum>b) exit(0);
	if (finalnum<a) return;
	if (finalnum<=maxprime)
		if (bprimes[finalnum]) fprintf(output,"%i\n",finalnum);
		else;
	else
	{
		for (int i=0; i<pn; i++)
			if (finalnum%primes[i]==0) return;
		fprintf(output,"%i\n",finalnum);
	}			
	return;
}

void findpalindromes(int length)
{
	int d[5]={0};
	for (d[0]=1; d[0]<10; d[0]+=2)
		if (length>2)
			for (d[1]=0; d[1]<10; d[1]++)
				if (length>4)
					for (d[2]=0; d[2]<10; d[2]++)
						if (length>6)
							for (d[3]=0; d[3]<10; d[3]++)
								if (length>8)
									for (d[4]=0; d[4]<10; d[4]++)
										check(length,d);
								else check(length,d);
						else check(length,d);
				else check(length,d);
		else check(length,d);
	return;
}

int main()
{
	FILE *input = fopen("pprime.in","r");
	fscanf(input,"%s%s",stra,strb);
	a = atoi(stra);
	b = atoi(strb);
	for (int i=0; i<10002; i++)
		bprimes[i]=true;
	koskino();
	for (int i=strlen(stra); i<=strlen(strb); i++)
		findpalindromes(i);
	return 0;
}

