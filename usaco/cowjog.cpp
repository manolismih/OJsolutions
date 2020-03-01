/*
ID:manolis2
PROG:cowjog
LANG:C++11
*/
#include <cstdio>


FILE *fin=fopen("cowjog.in","r"), *fout=fopen("cowjog.out","w");
int n, speed[100005], apantisi=1;

int main()
{
	fscanf(fin,"%i",&n);
	int trash;
	for (int i=0; i<n; i++)
		fscanf(fin,"%i%i",&trash,&speed[i]);
	
	int min=speed[n-1];
	for (int i=n-2; i>-1; i--)
		if (speed[i] <= min)
		{
			min = speed[i];
			apantisi++;
		}
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

