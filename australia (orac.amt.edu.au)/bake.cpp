#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin=fopen("savein.txt","r"), *fout=fopen("saveout.txt","w");
int n, apantisi, mod3, mod4;

int main()
{
	fscanf(fin,"%i",&n);
	for (int price, i=0; i<n; i++)
	{
		fscanf(fin,"%i",&price);
		apantisi += price - price%5;
		switch (price%5)
		{
			case 3:
				mod3++;
				break;
			case 4:
				mod4++;
				break;
		}
	}
	
	int best=2000000000, c, e3, e4;
	for (int a=0; a<=mod3/2; a++)
		for (int b=max(0,mod3-2*a-1); b<=min(mod3-2*a,mod4); b++)
		{
			c = (mod4-b)/3;
			if (c<0) break;
			e3 = mod3 - 2*a - b;
			e4 = mod4 - 3*c - b;
			if (5*(a+b+e3+e4) + 10*c < best)
				best = 5*(a+b+e3+e4) + 10*c;
		}
	fprintf(fout,"%i\n",apantisi+best);
	return 0;
}

