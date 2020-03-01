#include <cstdio>

FILE *fin=fopen("xxx.in","r"), *fout=fopen("xxx.out","w");
int n, heights[1000005], vlepoun=1;

int main()
{
	fscanf(fin,"%i",&n);
	for (int i=0; i<n; i++)
		fscanf(fin,"%i",&heights[i]);
	int biggest = heights[n-1];
	for (int i=n-2; i>-1; i--)
		if (heights[i] > biggest)
		{
			biggest = heights[i];
			vlepoun++;
		}
	fprintf(fout,"%i\n",vlepoun);
	return 0;
}

