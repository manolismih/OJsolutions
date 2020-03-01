#include <cstdio>
#include <algorithm>
using namespace std;


FILE *fin=fopen("slicein.txt","r"), *fout=fopen("sliceout.txt","w");
int n, apantisi=1, curr=1;
pair<int,int> build[100005];
bool built[100005];


int main()
{
	fscanf(fin,"%i",&n);
	for (int i=0; i<n; i++)
	{
		fscanf(fin,"%i",&build[i].first);
		build[i].second = i+1;
	}
	sort(build,build+n);
	built[0] = built[n+1] = true;
	
	for (int i=0; i<n; i++)
	{
		built[build[i].second] = true;
		if (built[build[i].second-1] && built[build[i].second+1]) curr--;
		else if (!built[build[i].second-1] && !built[build[i].second+1])
			if (++curr > apantisi) apantisi = curr;
	}
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

