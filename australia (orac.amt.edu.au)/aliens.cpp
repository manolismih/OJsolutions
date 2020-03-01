#include <cstdio>

FILE *fin=fopen("alienin.txt","r"), *fout=fopen("alienout.txt","w");
int n, w, people[100005], apantisi=1, from, to;

int main()
{
	fscanf(fin,"%i%i",&n,&w);
	for (int i=0; i<n; i++)
		fscanf(fin,"%i",people+i);
		
	for (to=1; to<n; to++)
	{
		for (; people[to]-people[from]>=w; from++);
		if (to-from+1 > apantisi) apantisi = to-from+1;
	}
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

