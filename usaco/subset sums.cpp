/*
ID:manolis2
PROG:subset
LANG:C++11
*/

#include <cstdio>

FILE *input = fopen("subset.in","r");
FILE *output = fopen("subset.out","w");

long long int tropoi[400][40];
bool examined[400][40] = {false};

long long int findtropous(int upoloipo, int avail)
{
	if  (upoloipo==0) return 1;
	if(upoloipo<0 || avail==0) return 0;
	
	if (!examined[upoloipo][avail])
	{
		examined[upoloipo][avail] = true;
		tropoi[upoloipo][avail] = findtropous(upoloipo,avail-1) +  findtropous(upoloipo-avail,avail-1);
	}
	return tropoi[upoloipo][avail];
}

int main()
{
	int n, semisum;
	float fsemisum;
	fscanf(input,"%i",&n);
	semisum = (n+1)*n/4;
	fsemisum = (n+1)*n/4.0;
	if (semisum != fsemisum)
		fprintf(output,"0\n");
	else
		fprintf(output,"%i\n",findtropous(semisum,n)/2);
	return 0;
}

