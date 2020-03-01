#include <cstdio>

FILE *fin=fopen("fence.in","r"), *fout=fopen("fence.out","w");
int f[4], min=200;

int main()
{
	for (int i=0; i<4; i++)
	{
		fscanf(fin,"%i",&f[i]);
		if (f[i] < min) min = f[i];
	}
	fprintf(fout,"%i",f[0]-min+1);
	for (int i=1; i<4; i++)
		fprintf(fout," %i",f[i]-min+1);
	fprintf(fout,"\n");
	return 0;
}

