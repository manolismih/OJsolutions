#include <cstdio>

FILE *fin=fopen("postin.txt","r"), *fout=fopen("postout.txt","w");
int n, from=2000000000, to=2000000000, apantisi;

int main()
{
	fscanf(fin,"%i",&n);
	for (int pos,width, i=1; i<=n; i++)
	{
		fscanf(fin,"%i%i",&pos,&width);
		if (pos < to)
		{
			from = pos;
			to = from+width;
			apantisi = i;
		}	
	}
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

