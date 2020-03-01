/*
ID:manolis2
PROG:inflate
LANG:C++11
*/

#include <cstdio>

using namespace std;

FILE *fin = fopen("inflate.in","r"), *fout  = fopen("inflate.out","w");
int N,M,memo[10001];

int main()
{
	fscanf(fin,"%i%i",&M,&N);
	int time,points;
	for (int i=0; i<N; i++)
	{
		fscanf(fin,"%i%i",&points,&time);
		for (int j=time; j<=M;  j++)
			if (memo[j-time] + points > memo[j])
				memo[j] = memo[j-time] + points;
	}
	fprintf(fout,"%i\n",memo[M]);
	return 0;
}

