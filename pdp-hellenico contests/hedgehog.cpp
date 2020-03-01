#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin=fopen("hedgehog.in","r"), *fout=fopen("hedgehog.out","w");
int n, k, frouta[100005];

int main()
{
	fscanf(fin,"%i%i",&n,&k);
	for (int i=0; i<n; i++)
		fscanf(fin,"%i",&frouta[i]);
		
	sort(frouta,frouta+n);
	if (k>2*n)
	{
		fprintf(fout,"%i\n",frouta[n-1]);
		return 0;
	}
	int mona = 2*k-3*n, dipla = 4*n-2*k;
	if (mona < 0 || dipla < 0)
	{
		fprintf(fout,"-1\n");
		return 0;
	}
	
	
	int apantisi = frouta[n-1];
	n -= mona;
	for (int i=0, j=n-1; i<j; i++, j--)
		if (frouta[i]+frouta[j] > apantisi)
			apantisi = frouta[j]+frouta[i];
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

