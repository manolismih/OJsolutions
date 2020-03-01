/*
ID:manolis2
PROG:frac1
LANG:C++
*/

#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

FILE *input = fopen("frac1.in","r");
FILE *output = fopen("frac1.out","w");

struct fraction{
	int a,b;
};

bool compare(fraction x, fraction y)
{
	return (static_cast<int>((double)x.a/x.b*100000) < static_cast<int>((double)y.a/y.b*100000));
}
set<fraction,bool (*)(fraction,fraction)> klasmata(compare);

int main()
{
	int n;
	fraction temp;
	fscanf(input,"%i",&n);
	for (int denom=1; denom<=n; denom++)
		for (int num=1; num<denom; num++)
		{
			temp.a = num;
			temp.b = denom;
			klasmata.insert(temp);
			printf("%i\n",klasmata.size());
		}
	fprintf(output,"%i%c%i\n",0,'/',1);
	for (set<fraction>::iterator it=klasmata.begin(); it!=klasmata.end(); it++)
		fprintf(output,"%i%c%i\n",it->a,'/',it->b);
	fprintf(output,"%i%c%i\n",1,'/',1);
	return 0;
}

