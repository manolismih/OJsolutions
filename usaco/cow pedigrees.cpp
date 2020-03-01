/*
ID:manolis2
PROG:nocows
LANG:C++11
*/

#include <cstdio>

FILE *input = fopen("nocows.in","r");
FILE *output = fopen("nocows.out","w");
int v,d, memo[200][105][100];
bool visited[200][105][100]={0};

long long unsigned int choose(int n, int k)
{
	long long unsigned int apantisi=1;
	int div = 2;
	for (int i=n-k+1; i<=n; i++)
	{
		apantisi *= i;
		while (div <= k && apantisi % div == 0)
		{
			apantisi /= div;
			div++;
		}
		if (div > k)
			apantisi %= 9901;
	}
	return apantisi%9901;
}

long long unsigned int findliseis(int komvoi, int depth, int avail)
{
	if (depth==0)
		return (komvoi==0) ? 1 : 0; 
	if (visited[komvoi][depth][avail])
		return memo[komvoi][depth][avail];
	visited[komvoi][depth][avail]=true;
	long long int returnvalue=0;
	for (int i=2; i<=komvoi && i<=avail*2; i+=2)
	{
		returnvalue += choose(avail,i/2)*findliseis(komvoi-i,depth-1,i);
		returnvalue %= 9901;
	}	
	memo[komvoi][depth][avail] = returnvalue;
	return returnvalue;
}

int main()
{
	fscanf(input,"%i%i",&v,&d);
	fprintf(output,"%llu\n",findliseis(v-1,d-1,1));
	return 0;
}

