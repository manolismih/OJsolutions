/*
ID:manolis2
PROG:zerosum
LANG:C++11
*/

#include <cstdio>

FILE *input = fopen("zerosum.in","r");
FILE *output = fopen("zerosum.out","w");
int n;
char lisi[15]={'+'}, avail[3]={' ','+','-'};

void checklisi()
{
	int sum=0, curnum=0;
	for (int i=1; i<=n; i++)
	{
		if (lisi[i-1] == '+') curnum=i;
		else if (lisi[i-1] == '-') curnum=-i;
		else 
			if (curnum>0) curnum = curnum*10+i;
			else curnum = curnum*10-i;
		if (lisi[i] != ' ') sum += curnum;
	}
	if (sum==0)
	{
		for (int i=1; i<n; i++)
			fprintf(output,"%i%c",i,lisi[i]);
		fprintf(output,"%i\n",n);
	}
}

void findliseis(int i)
{
	if (i==n)
		checklisi();
	else
		for (int j=0; j<3; j++)
		{
			lisi[i]=avail[j];
			findliseis(i+1);
		}
}

int main()
{
	fscanf(input,"%i",&n);
	for (int i=1; i<15; i++)
		lisi[i]='x';
	findliseis(1);
	return 0;
}

