#include <cstdio>
#include <algorithm>
using namespace std;

FILE *fin = fopen("hippoin.txt","r"), *fout = fopen("hippoout.txt","w");
int n, h, f, first, last;
struct gap{ // όλα τα διαστήματα είναι κλειστά
	int from, to;
};
bool compare(gap a, gap b)
{
	return a.to-a.from > b.to-b.from;
}
gap gaps[1005];

int main()
{
	fscanf(fin,"%d%d%d%d",&n,&h,&f,&first);
	gaps[0].from = first+1;
	for (int i=1; i<h; i++)
	{
		fscanf(fin,"%d",&gaps[i-1].to);
		--gaps[i-1].to;
		gaps[i].from = gaps[i-1].to+2;
	}
	last = gaps[h-1].from-1;
	
	int apantisi=0;
	gaps[h-1].from = 1;
	if (f%2 == 0)
		gaps[h-1].to = first-1+n-last;
	else
	{
		apantisi = max(first-1,n-last);
		f--;
		gaps[h-1].to = min(first-1,n-last);
	}
	sort(gaps,gaps+h,compare);
	
	for (int i=0; i<h && f; i++,f-=2)
		apantisi += gaps[i].to-gaps[i].from+1;
	fprintf(fout,"%d\n",apantisi);
	return 0;
}

